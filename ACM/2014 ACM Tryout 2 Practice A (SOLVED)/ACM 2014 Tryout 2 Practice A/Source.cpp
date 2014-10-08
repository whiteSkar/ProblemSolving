#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

bool isEven[3];

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest;
	cin >> numTest;

	for (int k = 1; k <= numTest; k++)
	{
		int numInts;
		cin >> numInts;

		int numEven = 0;
		int numOdd = 0;
		int resultIndex = -1;
		for (int i = 0; i < numInts; ++i)
		{
			int temp;
			cin >> temp;

			if (resultIndex == -1)
			{
				if (temp % 2 == 0)
				{
					numEven++;
					if (i < 3)
						isEven[i] = true;
				}
				else
				{
					numOdd++;
					if (i < 3)
						isEven[i] = false;
				}

				if (numEven != 0 && numOdd != 0 && numEven != numOdd)
				{
					resultIndex = i+1;
					if (numEven + numOdd == 3)
					{
						if (numEven > numOdd)
						{
							for (int m = 0; m < 3; ++m)
								if (!isEven[m])
									resultIndex = m+1;
						}
						else
						{
							for (int m = 0; m < 3; ++m)
								if (isEven[m])
									resultIndex = m+1;
						}
					}
				}
			}
		}

		cout << resultIndex << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}
