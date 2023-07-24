using Java.Interop;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using US.Zoom.Sdk;
using AndroidApp = Android.App.Application;
namespace SampleApp.Platforms.Android;

public class ZoomService : IZoomSDKInitializeListener, IZoomService
{
    public void Init()
    {
        Dispatcher.GetForCurrentThread().Dispatch(() =>
        {
            var zoomInitParams = new ZoomSDKInitParams
            {
                AppKey = "***REMOVED***",
                AppSecret = "***REMOVED***",
            };
            ZoomSDK.Instance.Initialize(AndroidApp.Context, this, zoomInitParams);
        });
    }

    public void JoinMeeting()
    {
        Dispatcher.GetForCurrentThread().Dispatch(() =>
        {
            var meetingService = ZoomSDK.Instance.MeetingService;
            var resultJoinMeeting = meetingService.JoinMeetingWithParams(AndroidApp.Context, new JoinMeetingParams
            {
                MeetingNo = "88133482907",
                DisplayName = "ADAM MAUI!",
                Password = "eXdDbnJPbXpmTUpTZXV5OHQ2bWNsQT09"
            }, new JoinMeetingOptions { });
        });
    }
    public nint Handle => throw new NotImplementedException();

    public int JniIdentityHashCode => throw new NotImplementedException();

    public JniObjectReference PeerReference => throw new NotImplementedException();

    public JniPeerMembers JniPeerMembers => throw new NotImplementedException();

    public JniManagedPeerStates JniManagedPeerState => throw new NotImplementedException();

    public void Dispose()
    {
        throw new NotImplementedException();
    }

    public void Disposed()
    {
        throw new NotImplementedException();
    }

    public void DisposeUnlessReferenced()
    {
        throw new NotImplementedException();
    }

    public void Finalized()
    {
        throw new NotImplementedException();
    }

    public void OnZoomAuthIdentityExpired()
    {
        throw new NotImplementedException();
    }

    public void OnZoomSDKInitializeResult(int errorCode, int internalErrorCode)
    {
        if (errorCode == IZoomError.ZoomErrorSuccess)
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

    public void SetJniIdentityHashCode(int value)
    {
        throw new NotImplementedException();
    }

    public void SetJniManagedPeerState(JniManagedPeerStates value)
    {
        throw new NotImplementedException();
    }

    public void SetPeerReference(JniObjectReference reference)
    {
        throw new NotImplementedException();
    }

    public void UnregisterFromRuntime()
    {
        throw new NotImplementedException();
    }
}