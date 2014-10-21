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

const int R = 5;
const int C = 3;
const int MAX_ROW = 23 * 8;		// (2s + 3) * (max num digit = 8)
const int MAX_COL = 12 * 8 + 7;	// (s + 2) * 8 + (7 = one column of space in between digits)

char zero[R][C] = {' ', '-', ' ',
				   '|', ' ', '|',
				   ' ', ' ', ' ',
				   '|', ' ', '|',
				   ' ', '-', ' '};

char one[R][C] = {' ', ' ', ' ',
				  ' ', ' ', '|',
				  ' ', ' ', ' ',
				  ' ', ' ', '|',
				  ' ', ' ', ' '};

char two[R][C] = {' ', '-', ' ',
				  ' ', ' ', '|',
				  ' ', '-', ' ',
				  '|', ' ', ' ',
				  ' ', '-', ' '};

char three[R][C] = {' ', '-', ' ',
				    ' ', ' ', '|',
		 		    ' ', '-', ' ',
				    ' ', ' ', '|',
				    ' ', '-', ' '};

char four[R][C] = {' ', ' ', ' ',
				   '|', ' ', '|',
				   ' ', '-', ' ',
				   ' ', ' ', '|',
				   ' ', ' ', ' '};

char five[R][C] = {' ', '-', ' ',
				   '|', ' ', ' ',
				   ' ', '-', ' ',
				   ' ', ' ', '|',
				   ' ', '-', ' '};

char six[R][C] = {' ', '-', ' ',
				  '|', ' ', ' ',
				  ' ', '-', ' ',
				  '|', ' ', '|',
				  ' ', '-', ' '};

char seven[R][C] = {' ', '-', ' ',
				    ' ', ' ', '|',
				    ' ', ' ', ' ',
				    ' ', ' ', '|',
				    ' ', ' ', ' '};

char eight[R][C] = {' ', '-', ' ',
				    '|', ' ', '|',
				    ' ', '-', ' ',
				    '|', ' ', '|',
				    ' ', '-', ' '};

char nine[R][C] = {' ', '-', ' ',
				   '|', ' ', '|',
				   ' ', '-', ' ',
				   ' ', ' ', '|',
				   ' ', '-', ' '};

typedef char (*twoDArray)[C];
twoDArray numLCD[10]  = {zero, one, two, three, four, five, six, seven, eight, nine};

char output[MAX_ROW][MAX_COL];

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	while (true)
	{
		int s, n;
		cin >> s >> n;

		if (n == 0 && s == 0)
			break;

		string buf = to_string(n);
		int bufLength = buf.length();

		memset(output, ' ', MAX_ROW * MAX_COL);

		int row = 2 * s + 3;
		int col = s + 2;

		for (int i = 0; i < bufLength; ++i)
		{
			int digit = buf[i] - '0';
			int rowOffset = 0;

			for (int j = 0; j < R; ++j)
			{
				if (j == 1 || j == 3)
				{
					for (int n = 0; n < s; ++n)
					{
						int colOffset = 0;
						for (int k = 0; k < C; ++k)
						{
							// Can skip when the value to write is ' ' to improve the performance
							// Duplicate code. Can refactor to clean the code
							if (k == 1)
							{
								for (int m = 0; m < s; ++m)
								{
									output[rowOffset][i*(col+1)+colOffset] = numLCD[digit][j][k];
									colOffset++;
								}
							}
							else
							{
								output[rowOffset][i*(col+1)+colOffset] = numLCD[digit][j][k];
								colOffset++;
							}
						}
						rowOffset++;
					}
				}
				else
				{
					int colOffset = 0;
					for (int k = 0; k < C; ++k)
					{
						// Can skip when the value to write is ' ' to improve the performance
						// Duplicate code. Can refactor to clean the code
						if (k == 1)
						{
							for (int m = 0; m < s; ++m)
							{
								output[rowOffset][i*(col+1)+colOffset] = numLCD[digit][j][k];
								colOffset++;
							}
						}
						else
						{
							output[rowOffset][i*(col+1)+colOffset] = numLCD[digit][j][k];
							colOffset++;
						}
					}
					rowOffset++;
				}
			}
		}

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < (bufLength * (col+1)) - 1; ++j)
			{
				cout << output[i][j];
			}
			cout << endl;
		}

		cout << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}
