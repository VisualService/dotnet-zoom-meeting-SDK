using Microsoft.Extensions.Logging;

namespace SampleApp;

public static class MauiProgram
{
    public static IZoomSDKService ZoomSDKService { get; set; }
    
    public static MauiApp CreateMauiApp(IZoomSDKService zoomSDKService)
    {
        ZoomSDKService = zoomSDKService;
        var builder = MauiApp.CreateBuilder();
        builder
            .UseMauiApp<App>()
            .ConfigureFonts(fonts =>
            {
                fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
                fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
            });

#if DEBUG
        builder.Logging.AddDebug();
#endif

        return builder.Build();
    }
}