// See https://aka.ms/new-console-template for more information

using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

Console.WriteLine("Started");

Main();

Console.WriteLine("Finished");
Console.ReadLine();


void Test()
{
    string toReplace = "Hello %s my name is %d yes %1d yes %2d %d %s %d";
    var regex = new Regex("%(s|d)|%([0-9]+d)");
    var matches = regex.Matches(toReplace);
    var i = 1;
    Console.WriteLine("Original String: "+toReplace);
    while (matches.Any())
    {
        //var letter = matches[0].Value[1];
        var letter = "[REPL]";
        toReplace = regex.Replace(toReplace, $"%{i}${letter}", 1);
        i++;
        matches =  regex.Matches(toReplace);
    }
    Console.WriteLine("Final String: "+toReplace);
}

void Main()
{
    var regex = new Regex("%(s|d)|%([0-9]+d)");
    //change your res folder to where you extracted the mobile rtc and then the common lib
    var resFolder =
        @"C:\Users\adam_\OneDrive\Business\Visual Service\Zoom Binding\5.11.3.7251\mobilertc\res";

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