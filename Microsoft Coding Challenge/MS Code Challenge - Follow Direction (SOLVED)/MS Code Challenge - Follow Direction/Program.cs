using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MS_Code_Challenge___Follow_Direction
{
    class Program
    {
        enum Direction
        {
            North,
            East,
            South,
            West
        };

        static void Main(string[] args)
        {
            var fileLines = System.IO.File.ReadAllLines(@"ActualInput.txt").ToList();

            var outputLines = new List<string>();
            int lineIndex = 0;
            int numLines = fileLines.Count;

            var pos = new Tuple<int, int>(0, 0);
            var curDirection = Direction.North;

            for ( ; lineIndex < numLines; )
            {
                var lineTokens = fileLines[lineIndex++].Split();

                if (lineTokens[0] == "Move")
                {
                    var distance = Int32.Parse(lineTokens[1]);

                    if (curDirection == Direction.North)
                        pos = new Tuple<int, int>(pos.Item1, pos.Item2 + distance);
                    else if (curDirection == Direction.East)
                        pos = new Tuple<int, int>(pos.Item1 + distance, pos.Item2);
                    else if (curDirection == Direction.South)
                        pos = new Tuple<int, int>(pos.Item1, pos.Item2 - distance);
                    else
                        pos = new Tuple<int, int>(pos.Item1 - distance, pos.Item2);
                }
                else
                {
                    var direction = lineTokens[1];

                    if (direction == "right")
                        curDirection = (Direction)(((int)curDirection + 1) % 4);
                    else
                    {
                        if (curDirection == Direction.North)
                        {
                            curDirection = Direction.West;
                            continue;
                        }
                        curDirection = (Direction)(((int)curDirection - 1) % 4);
                    }
                }
            }
            outputLines.Add(pos.Item1 + "," + pos.Item2);

            System.IO.File.WriteAllLines(@"output.txt", outputLines);
        }
    }
}
