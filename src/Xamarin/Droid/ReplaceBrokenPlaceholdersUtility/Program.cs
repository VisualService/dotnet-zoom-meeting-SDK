// See https://aka.ms/new-console-template for more information

using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

var regex = new Regex("%(s|d)|%([0-9]+d)|%([0-9]+s)");

Console.WriteLine("Started");

Main();
//var theLine = "%1s, %2s of %3s, selected";
//ProcessLine(ref theLine);

//Console.WriteLine(theLine);
Console.WriteLine("Finished");

void ProcessLine(ref string line)
{
    var matches = regex.Matches(line);
    if (matches.Any())
    {
        Console.WriteLine($"Found problem in line: {line}");
        var position = 1;
        while (matches.Any())
        {
            var letter = matches[0].Value.Contains("d") ? "d" : "s";
            line =  regex.Replace(line, $"%{position}${letter}", 1);
            position++;
            matches =  regex.Matches(line);
        }
        Console.WriteLine($"Corrected line to: {line}");
    }
}

// Download the latest zoom sdk
// Inside the mobile RTC folder, find the file called mobilertc.aar and rename it to mobilertc.zip
// Extract the contents of the folder.
// Run this method making sure to point to the res folder inside the extracted folder
// Recompile the mobilertc.aar file with this command ```jar cvf mobilertc.aar -C theExtractedFolderName/ .```
// Your mobilertc.aar file will now be suitable to use in the binding project.
// Do the same with the commonlib.aar file. ```jar cvf ZoomCommonLib.aar -C "C:\Users\adam_\OneDrive\Business\Visual Service\Zoom Binding\5.11.3.7251\commonlib\/" .```
void Main()
{

    //change your res folder to where you extracted the mobile rtc and then the common lib e.g C:\Users\adam_\OneDrive\Business\Visual Service\Zoom Binding\5.11.3.7251\commonlib\res
    var resFolder =
        @"C:\Users\Michele DM\Documents\GitHub\Xamarin.ZoomSDKBinding\Exoplayer UI Resources\Resources";

    //var resFolder = @"C:\Users\adam_\Downloads\test";

    var allFiles = Directory.GetFiles(resFolder, "**.xml", SearchOption.AllDirectories).Select(x => x.ToLowerInvariant()).Where(x => x.Contains("values"));
    foreach (var file in allFiles)
    {
        var allLines = File.ReadAllLines(file);
        if (allLines.Any())
        {
            for (var j = 0; j < allLines.Length; j++)
            {
                ProcessLine(ref allLines[j]);
            }
            File.WriteAllLines(file, allLines);
        }
    }
}