using Object = Java.Lang.Object;

namespace Com.Zipow.Videobox.Confapp.QA
{
    public partial class ZoomQAQuestion
    {
        public int CompareTo(Object _object)
        {
            var paramZoomQAQuestion = (ZoomQAQuestion)_object;
            return paramZoomQAQuestion.UpvoteCompareTo(paramZoomQAQuestion);
        }
    }
}

