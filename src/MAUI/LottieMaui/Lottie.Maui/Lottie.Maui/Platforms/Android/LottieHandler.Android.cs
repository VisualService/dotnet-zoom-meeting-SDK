using Com.Hcsaba.Mylibrary;
using Microsoft.Maui.Handlers;

namespace Lottie.Maui;

public partial class LottieHandler : ViewHandler<ILottieView, AndroidX.AppCompat.Widget.AppCompatImageView>
{

    LottieAnimationView platformView;

    private static void MapResetAnimation(LottieHandler handler, ILottieView view, object args)
    {
        //handler.PlatformView.Progress = 0;
    }

    private static void MapIsPlaying(LottieHandler handler, ILottieView view)
    {
        /*
        if (view.IsPlaying)
            handler.PlatformView.PlayAnimation();
        else
            handler.PlatformView.PauseAnimation();

        */
    }
    private static void MapLoops(LottieHandler handler, ILottieView view)
    {
        // handler.PlatformView.Loop(view.Loops);
    }
        
    public static void MapAnimation(LottieHandler handler, ILottieView view)
    {
        var name = view?.Animation;
        handler.UpdateAnimation(name);
    }

    void UpdateAnimation(string name)
    {
        platformView.SetAnimation(name);
    }

    protected override AndroidX.AppCompat.Widget.AppCompatImageView CreatePlatformView()
    {
        var callback = new LottieSdkCallbackImpl();
        platformView = new LottieAnimationView(Context, callback);
        return (AndroidX.AppCompat.Widget.AppCompatImageView)platformView.View;
    }
}
