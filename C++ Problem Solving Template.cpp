#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> pos;

void tokenizeString(const string &str, vector<string>& tokens, const string &delimiters);
bool pairCompare(const pos &arg1, const pos &arg2);
bool isStringEmptyOrWhitespace(string str);

/* How to make an array of 2d array statically */
const int COL_SIZE = 5;
const int twoDArrSize = 3;
typedef char (*twoDArray)[COL_SIZE];
twoDArray twoDArr[twoDArrSize] = {};

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

	return strlen(str);
}

int getLength(int num)
{
	char buf[21];

	sprintf(buf, "%d", num);
	return strlen(buf);
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

void tokenizeString(const string &str, vector<string>& tokens, const string &delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (pos != string::npos || lastPos != string::npos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

bool pairCompare(const pos &arg1, const pos &arg2)
{
	return arg1.second < arg2.second;
}

bool isStringEmptyOrWhitespace(string str)
{
	if (str.empty() || str.find_first_not_of(' ') == std::string::npos)
		return true;
	return false;
}