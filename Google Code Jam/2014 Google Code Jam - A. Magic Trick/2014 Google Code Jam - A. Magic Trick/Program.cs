using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2014_Google_Code_Jam___A.Magic_Trick
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
                int lineNum = Int32.Parse(fileLines[lineIndex]);
                lineIndex += lineNum;
                var line = fileLines[lineIndex].Split().ToList();
                lineIndex += (4 - lineNum + 1);
                var lineList = line.Select(l => Int32.Parse(l)).ToList();
                var lineSet = new HashSet<int>(lineList);

                lineNum = Int32.Parse(fileLines[lineIndex]);
                lineIndex += lineNum;
                line = fileLines[lineIndex].Split().ToList();
                lineIndex += (4 - lineNum + 1);
                lineList = line.Select(l => Int32.Parse(l)).ToList();

                int howManySame = 0;
                int theCardNumber = 0;
                foreach (var integer in lineList)
                {
                    if (lineSet.Contains(integer))
                    {
                        howManySame++;
                        theCardNumber = integer;
                    }
                }

                string answerString;
                if (howManySame == 1)
                    answerString = theCardNumber.ToString();
                else if (howManySame <= 0)
                    answerString = "Volunteer cheated!";
                else
                    answerString = "Bad magician!";

                outputLines.Add(string.Format("Case #{0}: {1}", numTestCase++, answerString));
            }

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
