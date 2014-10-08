#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

int getLength(char* str);
int getLength(int num);
int getLength(ull num);
void reverseCStringInPlace(char* str);

int main()
{
	ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest;
	inputFile >> numTest;

	for (int k = 1; k <= numTest; k++)
	{
		


		//cout << "Case #" << k << ": " << endl;
	}

	inputFile.close();
	//outputFile.close();

	return 0;
}

int getLength(char* str)
{
	if (!str)
		return 0;

	int i = 0;
	while (str[i++] != '\0')

	return i;
}

int getLength(int num)
{
	char buf[21];

	sprintf(buf, "%d", num);
	return getLength(buf);
}

int getLength(ull num)
{
	char buf[21];

	sprintf(buf, "%d", num);
	return getLength(buf);
}

void reverseCStringInPlace(char* str)
{
	int end = getLength(str) - 1;
	int start = 0;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
}
