using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lottie.Maui;

public class LottieView : View, ILottieView
{
    private string _animation;
    public string Animation 
    { 
        get => _animation; 
        set {
            _animation = value;
        } 
    }

    public bool Loops => true;

    private bool _isPlaying;

    public bool IsPlaying { get => _isPlaying; set => _isPlaying = value; }

    public void PlaybackCompleted()
    {
        throw new NotImplementedException();
    }
}
