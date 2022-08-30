// See https://aka.ms/new-console-template for more information

using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

Console.WriteLine("Started");

Main();

Console.WriteLine("Finished");
Console.ReadLine();

// Download the latest zoom sdk
// Inside the mobile RTC folder, find the file called mobilertc.aar and rename it to mobilertc.zip
// Extract the contents of the folder.
// Run this method making sure to point to the res folder inside the extracted folder
// Recompile the mobilertc.aar file with this command ```jar cvf mobilertc.aar -C theExtractedFolderName/ .```
// Your mobilertc.aar file will now be suitable to use in the binding project.
// Do the same with the commonlib.aar file. ```jar cvf ZoomCommonLib.aar -C theExtractedFolderName/ .```
void Main()
{
    var regex = new Regex("%(s|d)|%([0-9]+d)");
    //change your res folder to where you extracted the mobile rtc and then the common lib e.g C:\Users\adam_\OneDrive\Business\Visual Service\Zoom Binding\5.11.3.7251\commonlib\res
    var resFolder =
        @"C:\Users\adam_\OneDrive\Business\Visual Service\Zoom Binding\5.11.3.7251\commonlib\res";

    //var resFolder = @"C:\Users\adam_\Downloads\test";

    var allFiles = Directory.GetFiles(resFolder, "**.xml", SearchOption.AllDirectories).Select(x => x.ToLowerInvariant()).Where(x => x.Contains("values"));
    foreach (var file in allFiles)
    {
        var allLines = File.ReadAllLines(file);
        if (allLines.Any())
        {
            for (var j = 0; j < allLines.Length; j++)
            {
                var matches = regex.Matches(allLines[j]);
                if (matches.Any())
                {
                    Console.WriteLine($"Found problem in line: {allLines[j]}");
                    var position = 1;
                    while (matches.Any())
                    {
                        var letter = matches[0].Value.Contains("d") ? "d" : "s";
                        allLines[j] =  regex.Replace(allLines[j], $"%{position}${letter}", 1);
                        position++;
                        matches =  regex.Matches(allLines[j]);
                    }
                    Console.WriteLine($"Corrected line to: {allLines[j]}");
                }
            }
            File.WriteAllLines(file, allLines);
        }
    }
}