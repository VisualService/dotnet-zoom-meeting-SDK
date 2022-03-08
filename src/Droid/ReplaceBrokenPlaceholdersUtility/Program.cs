// See https://aka.ms/new-console-template for more information

using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

Console.WriteLine("Started");

Main();

Console.WriteLine("Finished");
Console.ReadLine();

void Main()
{
    var placeholders = new []{ "s", "d" };

    //change your res folder to where you extracted the mobile rtc
    var resFolder = @"C:\Users\adam_\Downloads\zoom feb 22\zoom-sdk-android-5.9.6.4777\mobilertc\res";
    var allFiles = Directory.GetFiles(resFolder, "**.xml", SearchOption.AllDirectories).Select(x => x.ToLowerInvariant()).Where(x => x.Contains("values"));
    foreach (var file in allFiles)
    {
        var allLines = File.ReadAllLines(file);
        if (allLines.Any())
        {
            for (var j = 0; j < allLines.Length; j++)
            {
                var line = allLines[j];
                
                //todo for lines with both a d and an s, we will end up with %1$s %1$d when we want $1$s %2$d.
                foreach (var placeholder in placeholders)
                {
                    var countOfPosition = Regex.Matches(line, $"%{placeholder}").Count;
                    if (countOfPosition >= 1)
                    {
                        Console.WriteLine($"Found problem in line: {line}");
                        var newLine = line;
                        var reconstructedLine = string.Empty;
                        var allBlock = newLine.Split(new[] { $"%{placeholder}" }, StringSplitOptions.None);
                        for (var i = 1; i <= allBlock.Length; i++)
                        {
                            if (i == allBlock.Length)
                            {
                                reconstructedLine += allBlock[i - 1];
                            }
                            else
                            {
                                reconstructedLine += allBlock[i - 1] + $"%{i}${placeholder}";
                            }
                        }
                        allLines[j] = reconstructedLine;
                        Console.WriteLine($"Reconstructed the line to: {reconstructedLine}");
                    }
                }
            }
            File.WriteAllLines(file, allLines);
        }
    }
}