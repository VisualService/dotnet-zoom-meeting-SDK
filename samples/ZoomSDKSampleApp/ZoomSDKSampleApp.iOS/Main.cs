﻿using System;
using System.Collections.Generic;
using System.Linq;

using Foundation;
using UIKit;

namespace ZoomSDKSampleApp.iOS
{
    public class Application
    {
        // This is the main entry point of the application.
        static void Main(string[] args)
        {
            // if you want to use a different Application Delegate class from "AppDelegate"
            // you can specify it here.
            try
            {
                UIApplication.Main(args, null, typeof(AppDelegate));
            }
            catch (Exception ex) {
                Console.WriteLine($"Managed Exception Caught: {ex}");
            }

       
        }
    }
}

