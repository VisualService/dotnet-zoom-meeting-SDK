# Xamarin.ZoomSDKBinding
 
 * Android: Meeting SDK Version: 5.9.6.4777
 
 * iOS: No support for iOS yet. PRs welcome!
 
 ## Buyer beware - Android
 
 * Requires your android app to compile for Android 12
 * Only tested with Zoom Custom UI. Default UI may work, but it is not tested.
 * Requires adding two dummy resource files in the Android Resources folders to compensate for the lack of a compatible version of the exoplayer binding library for xamarin. They are seeking open source contributions at [their repo](https://github.com/Baseflow/ExoPlayerXamarin) for the upgrade on [this issue](https://github.com/Baseflow/ExoPlayerXamarin/issues/116#issuecomment-884687316), which would remove the need for the dummy resource files. The missing resources do not affect apps running the custom ui, but if you are attempting to use the default UI, you might conceivably run into problems. (Did I mention defaul UI is not tested?!)
 
## Installation and integration - Android
 
1. Grab the package from nuget ```Install-Package VisualService.Xamarin.Android.ZoomSDK```

2. Add the two linked dummy resource files to your android resources. [This one](TBC) in layout and [this one](TBC) in the values folder.

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
                    // only custom ui is tested, which requires adding your own actiity and video renderers
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
 
 7. In your implementation of IInMeetingServiceListener you passed to the init, listen for successfully having joined a meeting, and start your activity for custom ui. You can follow instructions in[ the documentation](https://marketplace.zoom.us/docs/sdk/native-sdks/android/) for custom UI on the Android Zoom meeting SDK for further details

## Contributing

You are welcome to raise issues. PRs are particularly welcome, as the maintainers primary focus is a commercial product which only uses certain limited feature of the zoom sdk. Therefore time to spend on fixing issues not directly related to features we require will be limited.

## Building locally

If you download a fresh android sdk .aar file to upgrade the version, before it will build, it needs to go through a manual process to strip out incorrectly formatted placeholder characters present in the source resource files. Instructions are below. A PR to automate this process further is welcome.

Instructions for recompilation:


TBD




Based originally upon https://github.com/stntz/Xamarin.ZoomBinding
