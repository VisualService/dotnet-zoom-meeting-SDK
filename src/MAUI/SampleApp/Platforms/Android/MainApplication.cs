using Android.App;
using Android.Runtime;
using SampleApp.Platforms.Android;

namespace SampleApp
{
    [Application]
    public class MainApplication : MauiApplication
    {
        public MainApplication(IntPtr handle, JniHandleOwnership ownership)
            : base(handle, ownership)
        {
        }

        protected override MauiApp CreateMauiApp() => MauiProgram.CreateMauiApp(new DroidZoomSDKService());
    }
}