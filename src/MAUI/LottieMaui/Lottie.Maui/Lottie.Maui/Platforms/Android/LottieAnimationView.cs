using Android.Content;
using AndroidX.AppCompat.Widget;
using Com.Hcsaba.Mylibrary;

namespace Lottie.Maui;
public partial class LottieAnimationView : LottieAnimationViewWrapper
{

    //LottieAnimationViewWrapper viewWrapper;
    //LottieSdkCallbackImpl callback;

    public LottieAnimationView(Context context, LottieSdkCallbackImpl sdkCallbackImpl) : base(context, sdkCallbackImpl)
    {
        //callback = new LottieSdkCallbackImpl();
        //viewWrapper = new LottieAnimationViewWrapper(context, callback);

        
    }
    

    public void SetAnimationResource(string name) 
    {
        SetAnimation(name);
    }
    
    public int Progress;
    public bool Loops;

    public void PlayAnimation()
    {

    }

    public void PauseAnimation()
    {

    }

    public void ClearAnimation() { }



    public void Loop(bool loop)
    {

    }
}
