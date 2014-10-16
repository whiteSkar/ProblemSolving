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

		int totalCost = 0;
		for (int i = 0; i < numStudents; ++i)
		{
			double input;
			inputFile >> input;
			costs[i] = input * 100;
			totalCost += costs[i];
		}

		double mean = (double)totalCost / numStudents;

		double sumPos = 0;
		double sumNeg = 0;

		for (int i = 0; i < numStudents; ++i)
		{
			double diff = abs(costs[i] - mean);
			if (costs[i] > mean)
			{
				sumPos += diff;
			}
			else if (costs[i] < mean)
			{
				sumNeg += diff;
			}
		}
		/*
		if (isFirstCase)
		{
			isFirstCase = false;
		}
		else
		{
			cout << endl;
		}
		*/

		cout << "$" << fixed << setprecision(2) << (double)(int)min(sumPos, sumNeg) / 100 << endl;
	}

	inputFile.close();
	//outputFile.close();

	return 0;
}