namespace SampleApp
{
    public partial class MainPage : ContentPage
    {
        int count = 0;

        public MainPage()
        {
            InitializeComponent();
        }

        private async void OnCounterClicked(object sender, EventArgs e)
        {
            count++;

            if (count == 1)
                CounterBtn.Text = $"Clicked {count} time";
            else
                CounterBtn.Text = $"Clicked {count} times";

            SemanticScreenReader.Announce(CounterBtn.Text);

            await ((App)Application.Current).ZoomSDKService.JoinMeeting("INSERT_MEETING_ID_HERE","INSERT_MEETING_PW_HERE");

        }
    }

    public interface IZoomSDKService
    {
        Task<bool> InitZoomLib(string token);
        Task JoinMeeting(string meetingID, string meetingPassword, string displayName = "Zoom Demo");
    }
}