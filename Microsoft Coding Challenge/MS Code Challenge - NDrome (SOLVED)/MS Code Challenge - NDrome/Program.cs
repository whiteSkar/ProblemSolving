using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MS_Code_Challenge___NDrome
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileLines = System.IO.File.ReadAllLines(@"ActualInput.txt").ToList();

            var outputLines = new List<string>();
            int lineIndex = 0;
            var numLines = fileLines.Count;

            for ( ; lineIndex < numLines; )
            {
                var tokens = fileLines[lineIndex++].Split(new char[] {'|'});
                var str = tokens[0];
                var N = Int32.Parse(tokens[1]);
                bool isTrue = true;

                if (N <= 0)
                    throw new Exception();

                if (str.Length % N != 0)
                {
                    isTrue = false;
                    outputLines.Add(String.Format("{0}|{1}|{2}", str, N, (isTrue ? 1 : 0)));
                    continue;
                }
                if (str.Length == N)
                {
                    isTrue = true;
                    outputLines.Add(String.Format("{0}|{1}|{2}", str, N, (isTrue ? 1 : 0)));
                    continue;
                }

                var left = 0;
                var right = str.Length - N;

                while (left < right)
                {
                    if (str.Substring(left, N) != str.Substring(right, N))
                    {
                        isTrue = false;
                        break;
                    }
                    left += N;
                    right -= N;
                }

                outputLines.Add(String.Format("{0}|{1}|{2}", str, N, (isTrue ? 1 : 0)));
            }

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
