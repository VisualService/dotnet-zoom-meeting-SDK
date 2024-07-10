using System;
using System.ComponentModel;
using System.Threading.Tasks;
using Microsoft.Maui.Controls;
using SampleApp;
using Zoomios;

[assembly: Dependency(typeof(ZoomSDKSampleApp.iOS.iOSZoomSDKService))]
namespace ZoomSDKSampleApp.iOS
{
    public class iOSZoomSDKService : IMobileRTCMeetingServiceDelegate, IZoomSDKService
    {
        private bool inMeeting;
        private MobileRTCAuthService authService;
        private ZoomInitStatus zoomInitStatus = ZoomInitStatus.NotStarted;

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

        public async void InitZoomLib(string jwtToken)
        {
            ZoomInitStatus = ZoomInitStatus.InProgress;
            await Device.InvokeOnMainThreadAsync(() =>
            {
                var initResult = MobileRTC.SharedRTC.Initialize(new MobileRTCSDKInitContext
                {
                    EnableLog = true,
                    Domain = "https://zoom.us",
                    Locale = MobileRTC_ZoomLocale.Default
                });
                if (initResult)
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
                    
                    ZoomInitStatus = ZoomInitStatus.Success;
                }

                else
                {
                    ZoomInitStatus = ZoomInitStatus.Failed;
                }
            });
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
                //Specify your meeting options here

                var meetingJoinResponse = await Device.InvokeOnMainThreadAsync(() =>
                {
                    return meetingService.JoinMeetingWithJoinParam(meetingParamDict);
                });

                Console.WriteLine($"Meeting Joining Response {meetingJoinResponse}");
            }
        }

        public ZoomInitStatus ZoomInitStatus
        {
            get => zoomInitStatus;
            set
            {
                zoomInitStatus = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(ZoomInitStatus)));
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
    }

    class MobileDelegate : MobileRTCAuthDelegate
    {
        public override void OnMobileRTCAuthReturn(MobileRTCAuthError returnValue)
        {
            Console.WriteLine($"Another Log from our iOS counterpart: {returnValue}");
        }
    }
}

