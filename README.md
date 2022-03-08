# Xamarin.ZoomSDKBinding
 
 Current Zoom Android Meeting SDK Version: 5.9.6.4777
 
 ## Buyer beware
 
 * No support for iOS yet. PRs welcome!
 * Requires your android app to compile for Android 12
 * Only tested with Zoom Custom UI. Default UI may work, but it is not tested.
 * Requires adding two dummy resource files in the Android Resources folders to compensate for the lack of a compatible version of the exoplayer binding library for xamarin. They are seeking open source contributions at [their repo](https://github.com/Baseflow/ExoPlayerXamarin) for the upgrade on [this issue](https://github.com/Baseflow/ExoPlayerXamarin/issues/116#issuecomment-884687316), which would remove the need for the dummy resource files.
 
## Installation and integration
 
1. Grab the package from nuget ```Install-Package VisualService.Xamarin.Android.ZoomSDK```

2. Add the two linked dummy resource files to your android resources. [This one](TBC) in layout and [this one](TBC) in the values folder.

3. Implement a IZoomSDKInitializeListener singleton somewhere in your application

4. Initialise the SDK in the IZoomSDKInitializeListener.

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


Base originally upon https://github.com/stntz/Xamarin.ZoomBinding
