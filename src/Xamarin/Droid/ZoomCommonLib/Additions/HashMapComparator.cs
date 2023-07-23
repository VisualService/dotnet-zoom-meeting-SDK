using US.Zoom.Core.Data.Emoji;
using Object = Java.Lang.Object;

namespace US.Zoom.Core.Model
{
    public partial class HashMapComparator
    {
        public int Compare(Object o1, Object o2)
        {
            return Compare((CommonEmoji)o1, (CommonEmoji)o2);
        }
    }
}

