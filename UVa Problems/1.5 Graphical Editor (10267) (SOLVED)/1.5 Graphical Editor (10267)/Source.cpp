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

void tokenizeString(const string &str, vector<string>& tokens, const string &delimiters);

const int MAX_M = 251;
const int MAX_N = 251;

int M;
int N;

char table[MAX_N][MAX_M];

void clearTable()
{
	char white = 'O';
	memset(table, white, sizeof(char) * MAX_M * MAX_N);
};

void colorPixel(int X, int Y, char C)
{
	table[Y][X] = C;
};

void colorVerticalSegment(int X, int Y1, int Y2, char C)
{
	if (X < 1 || X > M) return;

	if (Y2 < Y1)
	{
		swap(Y1, Y2);
	}

	for (int i = Y1; i <= Y2; ++i)
	{
		if (i < 1 || i > N) continue;

		table[i][X] = C;
	}
};

void colorHorizontalSegment(int X1, int X2, int Y, char C)
{
	if (Y < 1 || Y > N) return;

	if (X2 < X1)
	{
		swap(X1, X2);
	}

	for (int i = X1; i <= X2; ++i)
	{
		if (i < 1 || i > M) continue;

		table[Y][i] = C;
	}
};

void colorRectangleSegment(int X1, int Y1, int X2, int Y2, char C)
{
	for (int j = Y1; j <= Y2; ++j)
	{
		if (j < 1 || j > N) continue;

		for (int i = X1; i <= X2; ++i)
		{
			if (i < 1 || i > M) continue;

			table[j][i] = C;
		}
	}
};

char getColorAt(int X, int Y)
{
	if (X < 1 || X > M || Y < 1 || Y > N) return 0;

	return table[Y][X];
};

void fillRegionWithColorHelper(int X, int Y, char C)
{
	if (X < 1 || X > M || Y < 1 || Y > N) return;

	char colorAtThisPosition = table[Y][X];
	table[Y][X] = C;

	if (getColorAt(X+1, Y) == colorAtThisPosition)
	{
		fillRegionWithColorHelper(X+1, Y, C);
	}
	if (getColorAt(X, Y+1) == colorAtThisPosition)
	{
		fillRegionWithColorHelper(X, Y+1, C);
	}
	if (getColorAt(X-1, Y) == colorAtThisPosition)
	{
		fillRegionWithColorHelper(X-1, Y, C);
	}
	if (getColorAt(X, Y-1) == colorAtThisPosition)
	{
		fillRegionWithColorHelper(X, Y-1, C);
	}
};

void fillRegionWithColor(int X, int Y, char C)
{
	if (getColorAt(X, Y) == C) return;

	fillRegionWithColorHelper(X, Y, C);
};

void writeTable(string name)
{
	cout << name << endl;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << table[i][j];
		}
		cout << endl;
	}
};

void inputProcessor(string command, vector<string> &arguments)
{
	if (command == "I")
	{
		clearTable();
		M = atoi(arguments[0].c_str());
		N = atoi(arguments[1].c_str());
	}
	else if (command == "C")
	{
		clearTable();
	}
	else if (command == "L")
	{
		if (arguments.size() < 3) return;
		colorPixel(atoi(arguments[0].c_str()), atoi(arguments[1].c_str()), arguments[2][0]);
	}
	else if (command == "V")
	{
		if (arguments.size() < 4) return;
		colorVerticalSegment(atoi(arguments[0].c_str()), atoi(arguments[1].c_str()), atoi(arguments[2].c_str()), arguments[3][0]);
	}
	else if (command == "H")
	{
		if (arguments.size() < 4) return;
		colorHorizontalSegment(atoi(arguments[0].c_str()), atoi(arguments[1].c_str()), atoi(arguments[2].c_str()), arguments[3][0]);
	}
	else if (command == "K")
	{
		if (arguments.size() < 5) return;
		colorRectangleSegment(atoi(arguments[0].c_str()), atoi(arguments[1].c_str()), atoi(arguments[2].c_str()), atoi(arguments[3].c_str()), arguments[4][0]);
	}
	else if (command == "F")
	{
		if (arguments.size() < 3) return;
		fillRegionWithColor(atoi(arguments[0].c_str()), atoi(arguments[1].c_str()), arguments[2][0]);
	}
	else if (command == "S")
	{
		if (arguments.size() < 1) return;
		writeTable(arguments[0]);
	}
	else
	{
		// Do nothing
	}
}

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	while (true)
	{
		string input;
		getline(cin, input);
		if (input.length() == 0) continue;

		// Is the first command always going to be I? or should I skip all commands until the command I is read?
		vector<string> inputs;
		tokenizeString(input, inputs, " ");

		string command = inputs.front();
		inputs.erase(inputs.begin());
		if (command == "X") break;

		inputProcessor(command, inputs);
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
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