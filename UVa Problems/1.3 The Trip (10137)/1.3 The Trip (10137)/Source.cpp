#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

int costs[1000];

int main()
{
	ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	bool isFirstCase = true;

	while (true)
	{
		int numStudents;
		inputFile >> numStudents;

		if (numStudents == 0)
			break;

		memset(costs, 0, 1000 * sizeof(int));

		unsigned long long totalCost = 0;
		for (int i = 0; i < numStudents; ++i)
		{
			double input;
			inputFile >> input;
			costs[i] = input * 100;
			totalCost += costs[i];
		}

		double mean = totalCost / numStudents;

		/*
		double sumPass = 0;

		sort(costs+0, costs+numStudents);

		for (int i = numStudents - 1; i >= 0; --i)
		{
			if (costs[i] <= mean)
				break;

			double diff = costs[i] - mean;
			sumPass += diff;
			costs[i] = mean;
		}

		for (int i = 0 - 1; i < numStudents; ++i)
		{
			if (costs[i] >= mean)
				break;

			double diff = mean - costs[i];
			sumPass -= diff;
			costs[i] = mean;
		}

		if (sumPass > 0)
		*/

		int numHigh = 0;
		int numLow = 0;
		unsigned long long sumHigh = 0;
		unsigned long long sumLow = 0;
		for (int i = 0; i < numStudents; ++i)
		{
			if (costs[i] < mean)
			{
				numLow++;
				sumLow += mean - costs[i];
			}
			else if (costs[i] > mean)
			{
				numHigh++;
				sumHigh += costs[i] - mean;
			}
		}

		double result = 0;
		if (sumHigh - sumLow > 0)
		{
			int diff = sumHigh - sumLow;
			result = max((double)sumLow, ((double)sumLow + (diff / numHigh - 1))) / 100;
		}
		else if (sumLow - sumHigh > 0)
		{
			int diff = sumLow - sumHigh;
			result = max((double)sumHigh, ((double)sumHigh + (diff / numLow - 1))) / 100;
		}
		else
		{
			result = (double)sumHigh / 100;
		}

		if (isFirstCase)
		{
			isFirstCase = false;
		}
		else
		{
			cout << endl;
		}

		cout << "$" << fixed << setprecision(2) << result;
	}

	inputFile.close();
	//outputFile.close();

	return 0;
}