using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2014_Google_Code_Jam___B.Cookie_Clicker
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileLines = System.IO.File.ReadAllLines(@"input.txt").ToList();

            var outputLines = new List<string>();
            int lineIndex = 0;
            var n = Int32.Parse(fileLines[lineIndex++]);
            int numTestCase = 1;

            //outputLines.Add(n.ToString());

            while (n-- > 0)
            {
                var inputLine = fileLines[lineIndex++].Split();
                double C = Double.Parse(inputLine[0]);
                double F = Double.Parse(inputLine[1]);
                double X = Double.Parse(inputLine[2]);
                double numFarms = 0.0;
                double totalTime = 0.0;

                while (true)
                {
                    double timeToGetCookie = C / (numFarms * F + 2);
                    double timeToGetXWithNextCookie = X / ((numFarms + 1) * F + 2);
                    double timeToGetXWithCurrentCookie = X / (numFarms * F + 2);

                    if (timeToGetCookie + timeToGetXWithNextCookie > timeToGetXWithCurrentCookie)
                    {
                        totalTime += timeToGetXWithCurrentCookie;
                        break;
                    }
                    else
                    {
                        totalTime += timeToGetCookie;
                        numFarms++;
                    }
                }

                outputLines.Add(string.Format("Case #{0}: {1:0.0000000}", numTestCase++, totalTime));
            }

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
