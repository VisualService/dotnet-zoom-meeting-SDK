using System;
using System.Collections.Generic;
using Android.Runtime;
using Java.Interop;
using Object = Java.Lang.Object;

namespace US.Zoom.Zmsg.Dataflow
{
    public partial class MMFragmentModule : global::Java.Lang.Object, global::AndroidX.Core.Util.IConsumer
    {
        public void Accept(Object? t)
        {
            t?.NotifyAll();
        }
    }
}

namespace Com.Zipow.Annotate.AnnoMultiPage
{
    public partial class AnnoMultiPageAdapter
    {
        public override unsafe void OnBindViewHolder(global::AndroidX.RecyclerView.Widget.RecyclerView.ViewHolder holder, int position)
        {
            OnBindViewHolder((Com.Zipow.Annotate.AnnoMultiPage.AnnoMultiPageAdapter.WhiteboardViewHolder)holder, position);
        }
    }
}

