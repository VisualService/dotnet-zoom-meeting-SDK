﻿using Object = Java.Lang.Object;

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

