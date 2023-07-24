using Microsoft.Maui;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


#if __IOS__ || MACCATALYST
using PlatformView = UIKit.UIView;
#elif ANDROID
using PlatformView = AndroidX.AppCompat.Widget.AppCompatImageView;
#endif

namespace Lottie.Maui;

public partial class LottieHandler
{
    public static readonly PropertyMapper<ILottieView, LottieHandler> Mapper = new(ViewMapper)
    {
        [nameof(ILottieView.Animation)] = MapAnimation,
        [nameof(ILottieView.Loops)] = MapLoops,
        [nameof(ILottieView.IsPlaying)] = MapIsPlaying,
    };

    public static readonly CommandMapper<ILottieView, LottieHandler> CommmandMapper = new()
    {
        ["Reset"] = MapResetAnimation,
    };

    public LottieHandler() : base(Mapper, CommmandMapper)
    {
    }
}
