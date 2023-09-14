using SampleApp.Platforms.Android;

namespace SampleApp;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        MainPage = new AppShell();
    }

    public IZoomSDKService ZoomSDKService { get; private set; }
    protected async override void OnStart()
    {
        ZoomSDKService = new DroidZoomSDKService();

        if (ZoomSDKService != null)
        {
            var initResult =   ZoomSDKService.InitZoomLib("INSERT_JWT_HERE");

        }
           
    }
            
}