using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lottie.Maui;

public interface ILottieView: IView
{
    string Animation { get; set; }
    bool Loops { get; }
    bool IsPlaying { get; set; }
    void PlaybackCompleted();
}
