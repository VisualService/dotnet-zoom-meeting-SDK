using SampleApp.Platforms.Android;
using SampleApp.Helpers;
namespace SampleApp;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        MainPage = new AppShell();

#if ANDROID
        ZoomSDKService = new DroidZoomSDKService();
        #elif IOS
       //todo implement iOS
#endif
        
    }

    public IZoomSDKService ZoomSDKService { get; private set; }

    protected override void OnStart()
    {
        ZoomSDKService.InitZoomLib(AppSettings.ZOOM_JWT);
    }
            
}