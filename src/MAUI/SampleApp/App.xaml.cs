namespace SampleApp;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        MainPage = new AppShell();
    }


    protected override void OnStart()
    {
        MauiProgram.ZoomSDKService.InitZoomLib(AppSettings.ZOOM_JWT);
    }
            
}