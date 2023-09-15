using System.ComponentModel;
using System.Runtime.CompilerServices;
using SampleApp.Platforms.Android;
using US.Zoom.Sdk;
using Application = Android.App.Application;

[assembly: Microsoft.Maui.Controls.Dependency(typeof(DroidZoomSDKService))]
namespace SampleApp.Platforms.Android
{
    /// <summary>
    /// Yes, we're mixing a service and a viewmodel. But what do you want from me, it's a sample app!
    /// </summary>
    public class DroidZoomSDKService 
        : Java.Lang.Object, IZoomSDKService, IZoomSDKInitializeListener, INotifyPropertyChanged
    {
        private ZoomInitStatus zoomInitStatus;

        public DroidZoomSDKService()
        {
           ZoomInitStatus = ZoomInitStatus.NotStarted;
        }
        

        // Create the OnPropertyChanged method to raise the event
        // The calling member's name will be used as the parameter.
        protected void OnPropertyChanged([CallerMemberName] string name = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }

        // Declare the event
        public event PropertyChangedEventHandler PropertyChanged;

        public ZoomInitStatus ZoomInitStatus
        {
            get => zoomInitStatus;
            set
            {
                if (value == zoomInitStatus) return;
                zoomInitStatus = value;
                OnPropertyChanged();
            }
        }

        public void InitZoomLib(string token)
        {
            try
            {
                ZoomInitStatus = ZoomInitStatus.InProgress;

                var zoomInitParams = new ZoomSDKInitParams
                {
                    JwtToken = token
                };

                ZoomSDK.Instance.Initialize(Application.Context, this, zoomInitParams);
            }
            catch (Exception e)
            {
                ZoomInitStatus = ZoomInitStatus.Failed;
            }
        }

        public async Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo")
        {
            var meetingService = ZoomSDK.Instance.MeetingService;
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
                ZoomInitStatus = ZoomInitStatus.Success;
                //Add listeners according to your needs
                //ZoomSDK.Instance.InMeetingService.AddListener(new YourInMeetingServiceListener());
                //ZoomSDK.Instance.MeetingService.AddListener(new YourMeetingServiceListener());
            }
            else
            {
                ZoomInitStatus = ZoomInitStatus.Failed;
                // something bad happened
            }
        }
    }
}