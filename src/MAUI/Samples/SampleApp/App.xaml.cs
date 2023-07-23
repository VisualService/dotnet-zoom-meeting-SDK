using SampleApp.Platforms.Android;

namespace SampleApp
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();

            MainPage = new AppShell();
        }

        public ZoomService ZoomService { get; private set; }
        
        protected override void OnStart()
        {
            base.OnStart();
            ZoomService = new ZoomService();
            ZoomService.Init();
        }
    }
}