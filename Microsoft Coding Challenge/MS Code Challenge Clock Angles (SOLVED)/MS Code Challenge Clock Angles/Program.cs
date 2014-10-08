using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MS_Code_Challenge_Clock_Angles
{
    class Program
    {
        static void Main(string[] args)
        {
            var fileLines = System.IO.File.ReadAllLines(@"ActualInput.txt").ToList();

            var outputLines = new List<string>();
            int lineIndex = 0;
            var n = Int32.Parse(fileLines[lineIndex++]);

            outputLines.Add(n.ToString());

            while (n-- > 0)
            {
                var clockInfo = fileLines[lineIndex++];
                var hour = Int32.Parse(clockInfo.Substring(0, 2));
                var minute = Int32.Parse(clockInfo.Substring(3, 2));
                var second = Int32.Parse(clockInfo.Substring(6, 2));

                double hourRatio = (double)hour / 12;
                double minuteRatio = (double)minute / 60;
                double secondRatio = (double)second / 60;

                double secondAngle = secondRatio * 360;
                double minuteAngle = minuteRatio * 360 + secondAngle / 60;
                double hourAngle = hourRatio * 360 + minuteAngle / 12;

                double angleHM = Math.Abs(hourAngle - minuteAngle);
                double angleMS = Math.Abs(minuteAngle - secondAngle);
                double angleHS = Math.Abs(hourAngle - secondAngle);

                if (angleHM > 180)
                    angleHM = (double)360 - angleHM;
                if (angleMS > 180)
                    angleMS = (double)360 - angleMS;
                if (angleHS > 180)
                    angleHS = (double)360 - angleHS;

                outputLines.Add(string.Format("{0:N2}, {1:N2}, {2:N2}", angleHM, angleHS, angleMS));
            }

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
