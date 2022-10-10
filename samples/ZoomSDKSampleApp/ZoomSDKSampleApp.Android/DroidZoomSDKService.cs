//using System;
//using System.Threading.Tasks;
//using Android.App;
//using Java.Interop;
//using US.Zoom.Sdk;
//using Xamarin.Essentials;

//namespace ZoomSDKSampleApp.Droid
//{
//    public class DroidZoomSDKService : IZoomSDKInitializeListener, IZoomSDKService
//    {
//        ZoomSDK zoomSDK;

//        public DroidZoomSDKService() { }

//        public IntPtr Handle => throw new NotImplementedException();

//        public int JniIdentityHashCode => 0;

//        public JniObjectReference PeerReference => throw new NotImplementedException();

//        public JniPeerMembers JniPeerMembers => throw new NotImplementedException();

//        public JniManagedPeerStates JniManagedPeerState => throw new NotImplementedException();

//        public void Dispose()
//        {
//        }

//        public void Disposed()
//        {
//        }

//        public void DisposeUnlessReferenced()
//        {
//        }

//        public void Finalized()
//        {
//        }

//        public async Task<bool> InitZoomLib(string appKey, string appSecret)
//        {
//            var zoomInitParams = new ZoomSDKInitParams
//            {
//                AppKey = appKey,
//                AppSecret = appSecret
//            };

//            await MainThread.InvokeOnMainThreadAsync(() =>
//            {
//                zoomSDK = ZoomSDK.Instance;
//                zoomSDK.Initialize(Application.Context, this, zoomInitParams);
//            }).ConfigureAwait(false);

//            return true;
//        }

//        public async Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo")
//        {
//            var meetingService = zoomSDK.MeetingService;

//            await MainThread.InvokeOnMainThreadAsync(() =>
//            {
//                meetingService.JoinMeetingWithParams(Application.Context,
//                    new JoinMeetingParams
//                    {
//                        MeetingNo = meetingID,
//                        Password = meetingPassword,
//                        DisplayName = displayName
//                    }, new JoinMeetingOptions());
//            }).ConfigureAwait(false);
//        }

//        public void OnZoomAuthIdentityExpired()
//        {
//            throw new NotImplementedException();
//        }

//        public async void OnZoomSDKInitializeResult(int errorCode, int internalErrorCode)
//        {
//            if (errorCode == ZoomError.ZoomErrorSuccess)
//            {
//                await MainThread.InvokeOnMainThreadAsync(() =>
//                {
//                    //perform various setup steps
//                    // only custom ui is tested, which requires adding your own Meeting Activity and video renderers in the android.xamarin project
//                    // default UI may work fine, but it is untested
//                    zoomSDK.MeetingSettingsHelper.CustomizedMeetingUIEnabled = true;  // set this to false to use the zoom provided, Default UI
//                    zoomSDK.MeetingSettingsHelper.EnableForceAutoStartMyVideoWhenJoinMeeting(false);

//                    //Add listeners according to your needs
//                    //zoomSDK.InMeetingService.AddListener(new YourInMeetingServiceListener());
//                    //zoomSDK.MeetingService.AddListener(new YourMeetingServiceListener());
//                });

//            }
//            else
//            {
//                // something bad happened
//            }
//        }

//        public void SetJniIdentityHashCode(int value)
//        {
//            throw new NotImplementedException();
//        }

//        public void SetJniManagedPeerState(JniManagedPeerStates value)
//        {
//            throw new NotImplementedException();
//        }

//        public void SetPeerReference(JniObjectReference reference)
//        {
//            throw new NotImplementedException();
//        }

//        public void UnregisterFromRuntime()
//        {
//            throw new NotImplementedException();
//        }
//    }
//}

