using System;
using System.Threading.Tasks;

namespace ZoomSDKSampleApp
{
    public interface IZoomSDKService
    {
        Task<bool> InitZoomLib(string appKey, string appSecret);
        Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo");
    }
}

