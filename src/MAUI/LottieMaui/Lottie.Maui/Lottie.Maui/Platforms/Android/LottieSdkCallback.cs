using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Com.Hcsaba.Mylibrary;


namespace Lottie.Maui;

public class LottieSdkCallbackImpl : Java.Lang.Object, ILottieSdkCallback
{
    public void OnFailure(string p0)
    {
       // Console.WriteLine("OnFailure: " + p0);
    }
}
