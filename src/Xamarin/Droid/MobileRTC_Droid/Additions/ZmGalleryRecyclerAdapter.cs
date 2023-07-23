using System;
using System.Collections.Generic;
using Android.Runtime;
using Java.Interop;

namespace Com.Zipow.Videobox.Confapp.Meeting.Scene.Uservideo
{
    public partial class ZmGalleryRecyclerAdapter
    {
        public override unsafe void OnBindViewHolder(global::AndroidX.RecyclerView.Widget.RecyclerView.ViewHolder holder, int position)
        {
            OnBindViewHolder((Com.Zipow.Annotate.AnnoMultiPage.AnnoMultiPageAdapter.WhiteboardViewHolder)holder, position);
        }
    }
}

