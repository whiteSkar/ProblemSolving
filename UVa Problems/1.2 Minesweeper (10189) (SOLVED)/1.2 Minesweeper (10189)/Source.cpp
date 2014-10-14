#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int N, M;
char result[100][100];

void increaseByOne(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= M) return;
	if (result[x][y] == '*') return;

	result[x][y]++;
}

void increaseSurroundingsByOne(int x, int y)
{
	x--;
	y--;
	increaseByOne(x, y);
	increaseByOne(++x, y);
	increaseByOne(++x, y);
	increaseByOne(x, ++y);
	increaseByOne(x, ++y);
	increaseByOne(--x, y);
	increaseByOne(--x, y);
	increaseByOne(x, --y);
}

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest = 1;

	while (true)
	{
		cin >> N >> M;

		if (N == 0 && M == 0)
			break;

		for (int i = 0; i < N; ++i)
		{
			string input;
			cin >> input;

			for (int j = 0; j < M; ++j)
			{
				if (input[j] == '*')
					result[i][j] = '*';
				else
					result[i][j] = 0;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (result[i][j] == '*')
					increaseSurroundingsByOne(i, j);
			}
		}

		if (numTest != 1)
			cout << endl;
		cout << "Field #" << numTest++ << ":" << endl;

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (result[i][j] == '*')
					cout << '*';
				else
					cout << (int)result[i][j];
			}
			cout << endl;
		}
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}