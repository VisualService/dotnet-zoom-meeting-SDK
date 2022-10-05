using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace ZoomSDKSampleApp
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }

        async void Button_Clicked(System.Object sender, System.EventArgs e)
        {
            await DependencyService.Get<IZoomSDKService>().JoinMeeting(AppKeys.A_MEETING_ID, AppKeys.A_MEETING_PASSWORD, "Rocky Balboa");
        }
    }
}

