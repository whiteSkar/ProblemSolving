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

typedef unsigned long long ull;
const int MOD_VAL = 20140927;

ull memoMax[1001] = {0};
ull memoPart[2002] = {0};

ull getMaxWays(int N)
{
	if (N == 1)
	{
		memoMax[1] = 1;
		return 1;
	}

	if (memoMax[N] != 0)
		return memoMax[N];

	int twoN = N << 1;
	memoMax[N] = (getMaxWays(N-1) * (twoN-1)) % MOD_VAL;
	return memoMax[N];
};

ull getPartWays(int twoN)
{
	if (memoPart[twoN] != 0)
		return memoPart[twoN];

	int left = 0, right = twoN - 2;

	ull result = 0;
	while (right >= 0)
	{
		result += ((getPartWays(left) * getPartWays(right)) % MOD_VAL);
		left += 2;
		right -= 2;
	}

	memoPart[twoN] = result % MOD_VAL;
	return memoPart[twoN];
}

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest;
	cin >> numTest;

	memoPart[0] = 1;
	memoPart[2] = 1;
	memoPart[4] = 2;

	for (int k = 1; k <= numTest; k++)
	{
		int N;
		cin >> N;
		
		int twoN = N << 1;
		int resultMax = getMaxWays(N);
		int resultPart = getPartWays(twoN);

		cout << resultPart << " " << resultMax << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}