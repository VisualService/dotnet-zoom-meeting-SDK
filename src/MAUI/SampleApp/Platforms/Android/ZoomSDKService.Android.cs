using SampleApp.Platforms.Android;
using US.Zoom.Sdk;

[assembly: Dependency(typeof(DroidZoomSDKService))]
namespace SampleApp.Platforms.Android
{
    public class DroidZoomSDKService : Java.Lang.Object, IZoomSDKService, IZoomSDKInitializeListener
    {
        ZoomSDK zoomSDK;
        public async Task<bool> InitZoomLib(string token)
        {
            zoomSDK = ZoomSDK.Instance;
            var zoomInitParams = new ZoomSDKInitParams
            {
                JwtToken = token
            };
            zoomSDK.Initialize(global::Android.App.Application.Context, this, zoomInitParams);
            await Task.Delay(5000);

            return true;
        }

        public async Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo")
        {
            var meetingService = zoomSDK.MeetingService;
            var resultJoinMeeting = meetingService.JoinMeetingWithParams(global::Android.App.Application.Context, new JoinMeetingParams
            {
                MeetingNo = meetingID,
                DisplayName = displayName,
                Password = meetingPassword
            }, new JoinMeetingOptions { });
        }

        public void OnZoomAuthIdentityExpired() { }

        public void OnZoomSDKInitializeResult(int errorCode, int internalErrorCode)
        {
            if (errorCode == ZoomError.ZoomErrorSuccess)
            {
                //Add listeners according to your needs
                //zoomSDK.InMeetingService.AddListener(new YourInMeetingServiceListener());
                //zoomSDK.MeetingService.AddListener(new YourMeetingServiceListener());
            }
            else
            {
                // something bad happened
            }
        }
    }
}