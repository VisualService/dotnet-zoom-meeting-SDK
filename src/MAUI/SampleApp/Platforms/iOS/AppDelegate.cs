using Foundation;
using ObjCRuntime;
using SampleApp;
using UIKit;

namespace ZoomSDKSampleApp.iOS;

// The UIApplicationDelegate for the application. This class is responsible for launching the 
// User Interface of the application, as well as listening (and optionally responding) to 
// application events from iOS.
[Register("AppDelegate")]
public partial class AppDelegate : MauiUIApplicationDelegate
{
    //
    // This method is invoked when the application has loaded and is ready to run. In this 
    // method you should instantiate the window, load the UI into it and then make the window
    // visible.
    //
    // You have 17 seconds to return from this method, or iOS will terminate your application.
    //
    protected override MauiApp CreateMauiApp()
    {
        return MauiProgram.CreateMauiApp(new iOSZoomSDKService());
    }

    public override bool FinishedLaunching(UIApplication app, NSDictionary options)
    {
        // global::Xamarin.Forms.Forms.Init();
        // LoadApplication(new App());

        Runtime.MarshalManagedException += (object sender, MarshalManagedExceptionEventArgs args) =>
        {
            Console.WriteLine("Marshaling managed exception");
            Console.WriteLine("    Exception: {0}", args.Exception);
            Console.WriteLine("    Mode: {0}", args.ExceptionMode);

        };
        Runtime.MarshalObjectiveCException += (object sender, MarshalObjectiveCExceptionEventArgs args) =>
        {
            Console.WriteLine("Marshaling Objective-C exception");
            Console.WriteLine("    Exception: {0}", args.Exception);
            Console.WriteLine("    Mode: {0}", args.ExceptionMode);
        };

        return base.FinishedLaunching(app, options);
    }
}