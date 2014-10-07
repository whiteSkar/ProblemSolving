using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TopCoder___SRM_222_Grocery_Bagger
{
    class Program
    {
        static void Main(string[] args)
        {

        }
    }

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
}
