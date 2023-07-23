using Object = Java.Lang.Object;

namespace Com.Zipow.Nydus.Camera
{
    public partial class ZmCameraAngleComparator
    {
        public int Compare(Object paramZMCameraCharacteristic1, Object paramZMCameraCharacteristic2)
        {
            ZMCameraCharacteristic zMCamera1 = (ZMCameraCharacteristic)paramZMCameraCharacteristic1;
            ZMCameraCharacteristic zMCamera2 = (ZMCameraCharacteristic)paramZMCameraCharacteristic2;
            double d1 = zMCamera2.HorizontalAngle;
            double d2 = zMCamera2.HorizontalAngle;

            return ((d1 = zMCamera1.VerticalAngle * d1) < (d2 = zMCamera2.VerticalAngle * d2)) ? 1 : ((d1 > d2) ? -1 : 0);
        }
    }
}

