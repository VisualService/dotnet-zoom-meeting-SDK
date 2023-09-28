using System;
using System.Threading.Tasks;
using SampleApp;
using Zoomios;

[assembly: Dependency(typeof(ZoomSDKSampleApp.iOS.iOSZoomSDKService))]
namespace ZoomSDKSampleApp.iOS
{
    public class iOSZoomSDKService : IMobileRTCMeetingServiceDelegate, IZoomSDKService
    {
        private bool inMeeting;
        private MobileRTCAuthService authService;

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

        public async Task<bool> InitZoomLib(string jwtToken)
        {
            bool InitResult = false; ;

            await Device.InvokeOnMainThreadAsync(() =>
            {
                InitResult = MobileRTC.SharedRTC.Initialize(new MobileRTCSDKInitContext
                {
                    EnableLog = true,
                    Domain = "https://zoom.us",
                    Locale = MobileRTC_ZoomLocale.Default
                });
                if (InitResult)
                {
                    MobileRTC.SharedRTC.SetLanguage("en");
                    authService = MobileRTC.SharedRTC.GetAuthService();
                    if (authService != null)
                    {
                        authService.Delegate = new MobileDelegate();   //inherits from MobileRTCAuthDelegate
                        authService.JwtToken = jwtToken;
                        authService.SdkAuth();
                    }
                    Console.WriteLine($"Mobile RTC Version: {MobileRTC.SharedRTC.MobileRTCVersion()} ");
                }
            });

            return InitResult;
        }

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

        public async Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo")
        {
            if (IsInitialized())
            {
                var meetingService = MobileRTC.SharedRTC.GetMeetingService();
                meetingService.Init();
                meetingService.Delegate = this;

                MobileRTCMeetingJoinParam meetingParamDict = new MobileRTCMeetingJoinParam();
                meetingParamDict.UserName = displayName;
                meetingParamDict.MeetingNumber = meetingID;
                meetingParamDict.Password = meetingPassword;

                MobileRTCMeetingSettings settings = MobileRTC.SharedRTC.GetMeetingSettings();
                settings.DisableDriveMode(true);
                settings.EnableCustomMeeting = false;
                //Specify your meeting options here

                var meetingJoinResponse = await Device.InvokeOnMainThreadAsync(() =>
                {
                    return meetingService.JoinMeetingWithJoinParam(meetingParamDict);
                });

                Console.WriteLine($"Meeting Joining Response {meetingJoinResponse}");
            }
        }
    }

    class MobileDelegate : MobileRTCAuthDelegate
    {
        public override void OnMobileRTCAuthReturn(MobileRTCAuthError returnValue)
        {
            Console.WriteLine($"Another Log from our iOS counterpart: {returnValue}");
        }
    }
}

