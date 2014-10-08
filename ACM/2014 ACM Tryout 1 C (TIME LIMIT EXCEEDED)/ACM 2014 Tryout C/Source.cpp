#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	int numTest;
	cin >> numTest;

	for (int k = 1; k <= numTest; k++)
	{
		int C, M, B, R, I;
		cin >> C >> M >> B >> R >> I;

		int maxNumTimes = 0;
		int costPerSec = C - B + I;
		int maxMana = M + R;
		for (int i = 0; i <= 100000; ++i)
		{
			costPerSec -= I;
			maxMana -= R;

			int numTimes = maxMana / costPerSec - 1;

			if (numTimes < maxNumTimes)
				break;

			maxNumTimes = numTimes;
			//maxNumTimes = max(maxNumTimes, numTimes);
		}

		cout << maxNumTimes << endl;
	}

	return 0;
}
