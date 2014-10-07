using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TopCoder___SRM_Classes
{
    // TCCC '04 Online Round 4 Div 1 PUCK I can't come up with a DP solution that deals with the special case!!
    public class BadNeighbors
    {
        public int maxDonations(int[] donations)
        {
            var numElem = donations.Count();
            if (numElem == 0) return 0;

            var D = new int[numElem];
            var containsFirst = new Boolean[numElem];

            for (int i = 0; i < 2; ++i)
                D[i] = donations[i];

            containsFirst[0] = true;
            containsFirst[1] = false;

            for (int i = 2; i < numElem; ++i)
            {
                var max = 0;
                var isContainsFirst = false;
                for (int j = 0; j < i - 1; ++j)
                {
                    if (i + 1 == numElem && j == 0)
                        continue;

                    if (i + 1 == numElem && containsFirst[j])
                    {
                        continue;
                    }

                    if (D[j] > max)
                    {
                        max = D[j];
                        isContainsFirst = containsFirst[j];
                    }
                }

                containsFirst[i] = isContainsFirst;
                D[i] = max + donations[i];
            }

            return D.Max();
        }
    }

    // TCCC '03 Semifinals 3 Div 1
    public class ZigZag
    {
        public int longestZigZag(int[] sequence)
        {
            var numElem = sequence.Count();

            if (numElem == 0) return 0;
            if (numElem == 1) return 1;

            var LZS = new int[numElem];
            var sign = new int[numElem];
            var isSameSpecialCase = true;
            LZS[0] = 1;
            sign[0] = 0;

            for (int i = 1; i < numElem; ++i)
            {
                var max = 0;
                var lastSign = 0;

                for (int j = 0; j < i; ++j)
                {
                    if (sequence[i] < sequence[j] && (sign[j] == 1 || (isSameSpecialCase && sign[j] == 0)))
                    {
                        max = Math.Max(max, LZS[j]);
                        lastSign = -1;
                        isSameSpecialCase = false;
                    }
                    else if (sequence[i] > sequence[j] && (sign[j] == -1 || (isSameSpecialCase && sign[j] == 0)))
                    {
                        max = Math.Max(max, LZS[j]);
                        lastSign = 1;
                        isSameSpecialCase = false;
                    }
                    else { }
                }

                LZS[i] = max + 1;
                sign[i] = lastSign;
            }

            var result = 0;
            foreach (var s in LZS)
                result = Math.Max(result, s);

            return result;
        }
    }

    // SRM 195 Div 1
    public class FanFailure
    {
        public int[] getRange(int[] capacities, int minCooling)
        {
            var capacitiesList = capacities.OrderBy(c => c).ToList();

            var maxCapacity = 0;
            foreach (var capacity in capacitiesList)
                maxCapacity += capacity;

            var currentCapacity = 0;
            var MFC = 0;
            var MFS = 0;
            foreach (var capacity in capacitiesList)
            {
                currentCapacity += capacity;
                if (maxCapacity - currentCapacity >= minCooling)
                    MFS++;
            }

            capacitiesList.Reverse();
            currentCapacity = 0;
            foreach (var capacity in capacitiesList)
            {
                currentCapacity += capacity;
                if (maxCapacity - currentCapacity >= minCooling)
                    MFC++;
            }

            var result = new int[2];
            result[0] = MFS;
            result[1] = MFC;

            return result;
        }
    }



    // SRM 222 Div 1
    public class GroceryBagger
    {
        public int minimumBags(int strength, string[] itemType)
        {
            int result = 0;

            if (strength <= 0)
                return result;

            var myTable = new System.Collections.Hashtable();

            foreach (var item in itemType)
            {
                if (!myTable.ContainsKey(item))
                    myTable.Add(item, 1);
                else
                    myTable[item] = (int)myTable[item] + 1;
            }


            foreach (var tableEntry in myTable.Values)
            {
                result += (int)tableEntry / strength + ((int)tableEntry % strength > 0 ? 1 : 0);
            }

            return result;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var sequence = new int[] { 70, 55, 13, 2, 99, 2, 80, 80, 80, 80, 100, 19, 7, 5, 5, 5, 1000, 32, 32 };
            Console.WriteLine((new ZigZag().longestZigZag(sequence)));  // expected: 8

            var donations = new int[] { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
            Console.WriteLine((new BadNeighbors().maxDonations(donations)));  // expected: 8
        }
    }

}
