using AndroidX.RecyclerView.Widget;

namespace Com.Zipow.Videobox.Confapp.QA
{
    public partial class ZoomQAQuestion
    {
        public int CompareTo(Java.Lang.Object _object)
        {
            var paramZoomQAQuestion = (ZoomQAQuestion)_object;
            return paramZoomQAQuestion.UpvoteCompareTo(paramZoomQAQuestion);
        }
    }
}

namespace Com.Zipow.Nydus.Camera
{
    public partial class ZmCameraAngleComparator
    {
        public int Compare(Java.Lang.Object paramZMCameraCharacteristic1, Java.Lang.Object paramZMCameraCharacteristic2)
        {
            ZMCameraCharacteristic zMCamera1 = (ZMCameraCharacteristic)paramZMCameraCharacteristic1;
            ZMCameraCharacteristic zMCamera2 = (ZMCameraCharacteristic)paramZMCameraCharacteristic2;
            double d1 = zMCamera2.HorizontalAngle;
            double d2 = zMCamera2.HorizontalAngle;

            return ((d1 = zMCamera1.VerticalAngle * d1) < (d2 = zMCamera2.VerticalAngle * d2)) ? 1 : ((d1 > d2) ? -1 : 0);
        }
    }
}


namespace Com.Zipow.Videobox.Confapp.Meeting.Scene.Uservideo
{
    public partial class ZmGalleryRecyclerAdapter
    {
        public override void OnBindViewHolder(RecyclerView.ViewHolder viewHolder, int viewType)
        {
            
        }
    }
}

