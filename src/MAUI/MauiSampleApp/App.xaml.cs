
namespace SampleApp;

public partial class App : Application
{
    public App()
    {
        InitializeComponent();

        MainPage = new AppShell();
    }

    
    public IZoomService ZoomService { get; private set; }
    
    protected override void OnStart()
    {
        base.OnStart();
#if ANDROID
            ZoomService = new Platforms.Android.ZoomService();
#endif
        ZoomService.Init();
    }
}