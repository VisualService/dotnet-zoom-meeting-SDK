using System;
using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace ZoomSDKSampleApp
{
    public partial class App : Application
    {
        public App ()
        {
            InitializeComponent();



            MainPage = new MainPage();
        }

        protected override async void OnStart ()
        {
            var zoomService = DependencyService.Get<IZoomSDKService>();
            var initResult = await zoomService.InitZoomLib(APP_KEY, APP_SECRET);

            Console.WriteLine($"Init Result Was: {initResult}");
        }

        protected override void OnSleep ()
        {
        }

        protected override void OnResume ()
        {
        }

 
    }
}

