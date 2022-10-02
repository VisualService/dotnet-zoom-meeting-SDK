# Xamarin.ZoomSDKBinding
 
 * Android: Meeting SDK Version: 5.11.10.8019.
 
 * iOS: 
 	* MobileRTC Version: 5.11.10.4556
 	* MobileRTC Screen Share Version: Not implemented yet, PRs are welcome! 

 * Originally based on [this repo](https://github.com/stntz/Xamarin.ZoomBinding)
 
 ## Buyer beware - Android
 
 * Requires your android app to compile for Android 12
 * Only tested with Zoom Custom UI. Default UI may work, but it is not tested.
 * Requires adding two dummy resource files in the Android Resources folders to compensate for the lack of a compatible version of the exoplayer binding library for xamarin. They are seeking open source contributions at [their repo](https://github.com/Baseflow/ExoPlayerXamarin) for the upgrade on [this issue](https://github.com/Baseflow/ExoPlayerXamarin/issues/116#issuecomment-884687316), which would remove the need for the dummy resource files. The missing resources do not affect apps running the custom ui, but if you are attempting to use the default UI, you might conceivably run into problems. (Did I mention default UI is not tested?!)
 
## Installation and integration - Android
 
1. Grab the package from nuget ```Install-Package VisualService.Xamarin.Android.ZoomSDK``` and install it as a dependency to your Xamarin.Android platform project. [Package link](https://www.nuget.org/packages/VisualService.Xamarin.Android.ZoomSDK/).

Make sure you tick to include pre-releases - the latest version of the package is 5.11.3.7251-beta

2. Add the two linked dummy resource files to your android resources in your Xamarin.Android project. [This one](https://github.com/VisualService/Xamarin.ZoomSDKBinding/blob/main/src/Droid/shim-files/exo_layout_polyfill.xml) in layout and [this one](https://github.com/VisualService/Xamarin.ZoomSDKBinding/blob/main/src/Droid/shim-files/exo_values_polyfill.xml) in the values folder.

3. Implement a IZoomSDKInitializeListener singleton somewhere in your application

4. Initialise the SDK in the IZoomSDKInitializeListener. Note the main thread access in this step and all the way down. It's needed.

```
                var zoomInitParams = new ZoomSDKInitParams
                {
                    AppKey = YourZoomSDKAppKey,
                    AppSecret = YourZoomSDKAppSecret
                };
                
                await MainThread.InvokeOnMainThreadAsync(()=>
                {
                    zoomSDK = ZoomSDK.Instance;
                    zoomSDK.Initialize(Application.Context, this, zoomInitParams);
                }).ConfigureAwait(false);
```

5. Listen for successful initialisation inside IZoomSDKInitializeListener.OnZoomSDKInitializeResult

```
    public async void OnZoomSDKInitializeResult(int errorCode, int internalErrorCode)
        {
            if (errorCode == ZoomError.ZoomErrorSuccess)
            {
                await MainThread.InvokeOnMainThreadAsync(() =>
                {
                    //perform various setup steps
                    // only custom ui is tested, which requires adding your own Meeting Activity and video renderers in the android.xamarin project
                    // default UI may work fine, but it is untested
                    zoomSDK.MeetingSettingsHelper.CustomizedMeetingUIEnabled = true; 
                    zoomSDK.MeetingSettingsHelper.EnableForceAutoStartMyVideoWhenJoinMeeting(false);
                    
                    //Add listeners according to your needs
                    zoomSDK.InMeetingService.AddListener(new YourInMeetingServiceListener());
                    zoomSDK.MeetingService.AddListener(new YourMeetingServiceListener());
                });

            }
            else
            {
                // something bad happened
            }
    }
```

6. Join Meeting

```
                    var meetingService = zoomSDK.MeetingService;

                    await MainThread.InvokeOnMainThreadAsync(() =>
                    {
                        meetingService.JoinMeetingWithParams(Application.Context,
                            new JoinMeetingParams
                            {
                                MeetingNo = YourMeetingId,
                                Password = YourPassword,
                                DisplayName = "Peter Parker"
                            }, new JoinMeetingOptions());
                    }).ConfigureAwait(false);
 ```
 
 7. At this point, if you are using default UI, zoom will launch an activity containing the call and you can switch on video etc. You're off to the races. Although I think I heard a rumour somewhere that default UI with this library was untested, it could be nothing though.
 8. If using custom ui, in your implementation of IInMeetingServiceListener you passed to the init, listen for the successsfully joined call event, and then start your activity for custom ui. You can follow instructions in [the documentation](https://marketplace.zoom.us/docs/sdk/native-sdks/android/) for custom UI on the Android Zoom meeting SDK for further details

## Installation and integration - iOS

1. Grab the package from nuget ```Install-Package VisualService.Xamarin.iOS.ZoomSDK``` and install it as a dependency to your Xamarin.iOS platform project.
 
2. Implement a IMobileRTCMeetingServiceDelegate (which should also inherit from your "Cross platform interface" as a DependencyService);
 
3. In the IMobileRTCMeetingServiceDelegate class you should initialize the SDK as follows: 
 
 ```
        public void InitZoomLib(string appKey, string appSecret)
        {
            bool InitResult;

            Device.BeginInvokeOnMainThread(() => { 
                InitResult = mobileRTC.Initialize(new MobileRTCSDKInitContext
                {
                    EnableLog = true,
                    Domain = "https://zoom.us",
                    Locale = MobileRTC_ZoomLocale.Default
                });
                if (InitResult)
                {
                    mobileRTC.SetLanguage("it");
                    authService = mobileRTC.GetAuthService();
                    if (authService != null)
                    {
                        authService.Delegate = new MobileDelegate();   //inherits from MobileRTCAuthDelegate
                        authService.ClientKey = appKey;
                        authService.ClientSecret = appSecret;
                        authService.SdkAuth();
                    }
                    Console.WriteLine($"Mobile RTC Version: {mobileRTC.MobileRTCVersion()} ");
                }
            });
        } 
```

4. Listen for successful initialisation inside MobileRTCAuthDelegate
```
        class MobileDelegate : MobileRTCAuthDelegate
        {
            public override void OnMobileRTCAuthReturn(MobileRTCAuthError returnValue)
            {
                Console.WriteLine($"Another Log from our iOS counterpart: {returnValue}");
            }
        }
```

4.1 You can monitor the initialisation and authorization status in any moment like this: 

```
        public bool IsInitialized()
        {
            bool result = false;

            if (MobileRTC.SharedRTC != null)
            {
                if (MobileRTC.SharedRTC.IsRTCAuthorized())
                {
                    if (MobileRTC.SharedRTC.GetMeetingService() != null)
                    {
                        result = true;
                    }
                }
            }
            return result;
        }
```

5. Join the meeting 

```
     public void JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo")
     {
            if (IsInitialized())
            {
                var meetingService = mobileRTC.GetMeetingService();
                meetingService.Init();
                meetingService.Delegate = this;

                MobileRTCMeetingJoinParam meetingParamDict = new MobileRTCMeetingJoinParam();
                meetingParamDict.UserName = displayName;
                meetingParamDict.MeetingNumber = meetingID;
                meetingParamDict.Password = meetingPassword;

                MobileRTCMeetingSettings settings = mobileRTC.GetMeetingSettings();
                settings.DisableDriveMode(true);
                settings.EnableCustomMeeting = false;
                //Specify your meeting options here

                Device.BeginInvokeOnMainThread(() =>
                {
                    var meetingJoinResponse = meetingService.JoinMeetingWithJoinParam(meetingParamDict);
                    Console.WriteLine($"Meeting Joining Response {meetingJoinResponse}");
                });
            }
	}
```

6. Monitor the meeting status
```
        public override void OnMeetingStateChange(MobileRTCMeetingState state)
        {
            if (state == MobileRTCMeetingState.Ended)
            {
                //The meeting has ended
                //=> Fire your event! 
            }
            if (state == MobileRTCMeetingState.InMeeting)
            {
                inMeeting = true;
            }
            else
            {
                inMeeting = false;
            }
        }
```

## Contributing

You are welcome to raise issues. PRs are particularly welcome, as the maintainers primary focus is a commercial product which only uses certain limited feature of the zoom sdk. Therefore time to spend on fixing issues not directly related to features we require will be limited.

## Building locally - Android

If you download a fresh android sdk .aar file to upgrade the version, before it will build, it needs to go through a manual process to strip out incorrectly formatted placeholder characters present in the source resource files. Basically %s and %d characters need replacing with their positional alternatives %1$s and %2$d etc. There are hundreds of resource files, so I am including a replace utility console app in the src. Instructions for use are below. A PR to automate this process further is welcome. I also raised [an issue in the zoom developer forums](https://devforum.zoom.us/t/2-multiple-substitutions-still-specified-in-non-positional-format/63243) to fix this at their end, but there is no sign of a fix yet.

1. Download the latest zoom sdk
2. Inside the mobile RTC folder, find the file called mobilertc.aar and rename it to mobilertc.zip
3. Extract the contents of the folder.
4. Run the replace utility console app, located in src/Droid/, making sure to point to the res folder inside the extracted folder
5. Recompile the mobilertc.aar file with this command ```jar cvf mobilertc.aar -C theExtractedFolderName/ .```
6. Your mobilertc.aar file will now be suitable to use in the binding project.

To create the nuget package

1. Change the Version node in the file MobileRTC_Droid.csproj to the latest version
2. Build in release mode
3. The nuget package will appear in the bin/Release folder
