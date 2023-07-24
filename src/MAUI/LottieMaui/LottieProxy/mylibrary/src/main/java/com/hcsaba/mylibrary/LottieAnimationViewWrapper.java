package com.hcsaba.mylibrary;

import android.animation.Animator;
import android.content.Context;
import android.graphics.Color;
import android.view.View;
import android.view.ViewGroup;
import androidx.appcompat.widget.AppCompatImageView;
import com.airbnb.lottie.LottieAnimationView;
import com.airbnb.lottie.LottieCompositionFactory;
import com.airbnb.lottie.LottieDrawable;

public class LottieAnimationViewWrapper {

    private final LottieAnimationView lottieAnimationView;
    private final LottieSdkCallback lottieSdkCallback;
    private final Context _context;

    public LottieAnimationViewWrapper(Context context, LottieSdkCallback sdkCallback){
        _context = context;
        lottieAnimationView = new LottieAnimationView(context);
        lottieAnimationView.setRepeatMode(LottieDrawable.RESTART);
        lottieAnimationView.setRepeatCount(LottieDrawable.INFINITE);
        lottieSdkCallback = sdkCallback;

        ViewGroup.LayoutParams lp = new ViewGroup.LayoutParams(ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT);

        lottieAnimationView.setLayoutParams(lp);
        lottieAnimationView.setFailureListener(result -> {
            lottieSdkCallback.onFailure(result.getLocalizedMessage());
        });

        lottieAnimationView.addAnimatorListener(new Animator.AnimatorListener() {
            @Override
            public void onAnimationStart(Animator animation) {
                System.out.println("Animation: "+"start");
            }

            @Override
            public void onAnimationEnd(Animator animation) {
                System.out.println("Animation: "+"end");
            }

            @Override
            public void onAnimationCancel(Animator animation) {
                System.out.println("Animation: "+"cancel");
            }

            @Override
            public void onAnimationRepeat(Animator animation) {
                System.out.println("Animation: " + "repeat");
            }
        });
    }

    public View getView() {
        return lottieAnimationView;
    }

    public void setAnimation(String animation){
        LottieCompositionFactory.fromAsset(_context, animation).addListener(result -> {
            System.out.println("Loaded!!!!!!!!!!!!!! "+result.getBounds() + " " + result.toString());
            lottieAnimationView.setComposition(result);
            lottieAnimationView.playAnimation();
        }).addFailureListener(result -> result.printStackTrace());
    }
}
