using System.ComponentModel;

namespace SampleApp
{
    public partial class MainPage : ContentPage
    {

        private readonly IZoomSDKService zoomSdkService;
        public MainPage()
        {
            InitializeComponent();
            zoomSdkService = MauiProgram.ZoomSDKService;
            this.ZoomInitStatusLabel.Text = "ZOOM INIT STATUS: " + zoomSdkService.ZoomInitStatus;
            zoomSdkService.PropertyChanged += ZoomSdkServiceOnPropertyChanged;
        }

        private void ZoomSdkServiceOnPropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            MainThread.BeginInvokeOnMainThread(() =>
            {
                this.ZoomInitStatusLabel.Text = "ZOOM INIT STATUS: " + zoomSdkService.ZoomInitStatus;
                ZoomVersionLabel.Text = "Zoom Version: " + zoomSdkService.ZoomVersion;
                StartCallButton.IsEnabled = zoomSdkService.ZoomInitStatus == ZoomInitStatus.Success;
            });
        }

        private async void OnCounterClicked(object sender, EventArgs e)
        {

            SemanticScreenReader.Announce(StartCallButton.Text);

            await zoomSdkService.JoinMeeting(AppSettings.ZOOM_MEETING_NUMBER,AppSettings.ZOOM_MEETING_PASSWORD);
        }
    }

    public enum ZoomInitStatus
    {
      NotStarted, InProgress, Success, Failed, 
    }
    public interface IZoomSDKService : INotifyPropertyChanged
    {
        ZoomInitStatus ZoomInitStatus { get; set; }
        string ZoomVersion { get; }

        void InitZoomLib(string token);
        Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo");
    }
}