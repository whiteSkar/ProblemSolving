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

int getNextMin(int min)
{
	return (min+1) % 60;
};

int getNextHour(int hour)
{
	return (hour+1) % 24;
};

bool isPalindrome(string str)
{
	int i = 0, j = str.length()-1;

	while (i < j)
	{
		if (str[i++] != str[j--])
			return false;
	}
	return true;
};

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest;
	cin >> numTest;

	for (int k = 1; k <= numTest; k++)
	{
		string input;
		cin >> input;

		string hourStr = input.substr(0, 2);
		string minStr = input.substr(3);

		int hour = atoi(hourStr.c_str());
		int min = atoi(minStr.c_str());

		while (true)
		{
			int nextMin = getNextMin(min);
			int nextHour = hour;
			if (nextMin < min)
				nextHour = getNextHour(hour);

			char buffer[6];
			sprintf(buffer, "%02d:%02d", nextHour, nextMin);
			string time(buffer);

			if (isPalindrome(time))
			{
				cout << time << endl;
				break;
			}

			min = nextMin;
			hour = nextHour;
		}
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}
