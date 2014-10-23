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

typedef pair<int, int> pos;

const char NON_PIECE = '0';
const int N = 8;
char board[N][N];

char getPiece(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return NON_PIECE;

	if (board[y][x] == '.')
		return NON_PIECE;

	return board[y][x];
};

bool isTarget(int x, int y, char target)
{
	return getPiece(x, y) == target;
};

bool isNonTargetPiece(char piece, char target)
{
	return (piece != NON_PIECE && piece != target);
};

bool checkPawn(bool isWhite, int x, int y, char target)
{
	int dx = 1;
	int dy = 1;
	if (isWhite)
		dy = -1;

	return isTarget(x + dx, y + dy, target) || isTarget(x - dx, y + dy, target);
};

// Code Duplicate: room to refactor
bool checkRook(int x, int y, char target)
{
	for (int i = x + 1; i < N; ++i)
	{
		char piece = getPiece(i, y);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = x - 1; i >= 0; --i)
	{
		char piece = getPiece(i, y);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = y + 1; i < N; ++i)
	{
		char piece = getPiece(x, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = y - 1; i >= 0; --i)
	{
		char piece = getPiece(x, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	return false;
};

// Code Duplicate: room to refactor
bool checkBishop(int x, int y, char target)
{
	for (int i = y+1, j = x+1; i < N && j < N; ++i, ++j)
	{
		char piece = getPiece(j, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = y+1, j = x-1; i < N && j >= 0; ++i, --j)
	{
		char piece = getPiece(j, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = y-1, j = x-1; i >= 0 && j >= 0; --i, --j)
	{
		char piece = getPiece(j, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	for (int i = y-1, j = x+1; i >= 0 && j < N; --i, ++j)
	{
		char piece = getPiece(j, i);
		if (piece != NON_PIECE && piece != target)
			break;

		if (piece == target)
			return true;
	};

	return false;
};

bool checkQueen(int x, int y, char target)
{
	return checkRook(x, y, target) || checkBishop(x, y, target);
};

const int knightMoveCount = 8;
pos knightMovements[knightMoveCount] = {pos(1, -2), pos(2, -1), pos(2, 1), pos(1, 2), pos(-1, 2), pos(-2, 1), pos(-2, -1), pos(-1, -2)};
bool checkKnight(int x, int y, char target)
{
	for (int i = 0; i < knightMoveCount; ++i)
	{
		pos curPos = knightMovements[i];
		if (isTarget(x + curPos.first, y + curPos.second, target))
			return true;
	}

	return false;
};

bool isCheckMate(char piece, int x, int y)
{
	char blackKing = 'k';
	char whiteKing = 'K';
	if (piece == 'P')
		return checkPawn(true, x, y, blackKing);
	else if (piece == 'p')
		return checkPawn(false, x, y, whiteKing);
	else if (piece == 'R')
		return checkRook(x, y, blackKing);
	else if (piece == 'r')
		return checkRook(x, y, whiteKing);
	else if (piece == 'B')
		return checkBishop(x, y, blackKing);
	else if (piece == 'b')
		return checkBishop(x, y, whiteKing);
	else if (piece == 'Q')
		return checkQueen(x, y, blackKing);
	else if (piece == 'q')
		return checkQueen(x, y, whiteKing);
	else if (piece == 'N')
		return checkKnight(x, y, blackKing);
	else if (piece == 'n')
		return checkKnight(x, y, whiteKing);
	else
		return false;
};

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numCase = 1;
	while (true)
	{
		bool isEmptyBoard = true;
		for (int i = 0; i < N; ++i)
		{
			string input;
			cin >> input;
			if (input != "........")
				isEmptyBoard = false;

			for (int j = 0; j < N; ++j)
				board[i][j] = input.at(j);
		}

		if (isEmptyBoard)
			break;

		string result = "no king is in check.";
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				char piece = board[i][j];
				if (isCheckMate(piece, j, i))
				{
					if ((int)piece >= (int)'A' && (int)piece <= (int)'Z')
					{
						result = "black king is in check.";
					}
					else
					{
						result = "white king is in check.";
					}
					i = N;
					j = N;
				}
			}
		}
		
		cout << "Game #" << numCase++ << ": " << result << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}