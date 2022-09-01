using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Object = Java.Lang.Object;


// ReSharper disable once CheckNamespace Namespace must match for partial class to be recognised
namespace US.Zoom.Core.Data.Emoji
{
    public partial class EmojiComparetor
    {
        public int Compare(Object o1, Object o2)
        {
            return Compare((CommonEmoji)o1, (CommonEmoji)o2);
        }
    }
}