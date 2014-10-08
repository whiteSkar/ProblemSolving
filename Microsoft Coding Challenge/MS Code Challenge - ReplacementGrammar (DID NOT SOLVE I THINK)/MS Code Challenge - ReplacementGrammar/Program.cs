using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MS_Code_Challenge___ReplacementGrammar
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileLines = System.IO.File.ReadAllLines(@"ActualInput.txt").ToList();

            var outputLines = new List<string>();
            int lineIndex = 0;
            var numInputLines = fileLines.Count;

            var ruleList = new List<KeyValuePair<string, string>>();

            while (!string.IsNullOrWhiteSpace(fileLines[lineIndex]))
            {
                var ruleLine = fileLines[lineIndex++].Split(new char[] { '|' });
                ruleList.Add(new KeyValuePair<string, string>(ruleLine.First(), ruleLine.Last()));
            }

            while (string.IsNullOrWhiteSpace(fileLines[lineIndex]))
            {
                lineIndex++;
            }

            var message = "";
            while (lineIndex < numInputLines)
            {
                message += fileLines[lineIndex++];
            }

            ruleList.OrderBy(a => a.Key.Length);

            foreach (var rule in ruleList)
            {
                message = message.Replace(rule.Key, rule.Value);
            }

            outputLines.Add(message);

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
