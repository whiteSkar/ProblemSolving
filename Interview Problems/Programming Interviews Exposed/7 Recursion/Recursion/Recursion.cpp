#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binarySearch(int arr[], int target, int low, int high)
{
    if (!arr || high < low)
        throw exception();

    if (low == high && arr[low] != target)
        return -1;

    int center = (high - low) / 2 + low;

    if (arr[center] == target)
        return center;
    else if (arr[center] < target)
        return binarySearch(arr, target, center+1, high);
    else
        return binarySearch(arr, target, low, center-1);
}

int binarySearch(int arr[], int target, int size)
{
    return binarySearch(arr, target, 0, size-1);
}

int binarySearchIterative(int* arr, int target, int size)
{
    if (!arr || size <= 0)
        throw exception();

    int low = 0, high = size - 1;

    while (high > low)
    {
        int center = (high-low) / 2 + low;

        if (arr[center] == target)
            return center;
        else if (arr[center] > target)
            high = center - 1;
        else
            low = center + 1;
    }

    if (high < low)
        return -1;

    if (arr[low] == target)
        return low;
    else
        return -1;
}

void getPermutations(string str, string buffer, vector<string> &perms)
{
    if (str.empty())
    {
        perms.push_back(buffer);
		return;
    }

    for (unsigned int i = 0; i < str.length(); i++)
    {
        string strWithoutThisChar = str.substr(0, i) + str.substr(i+1);	// if the argument to substr function is equal to the length of the string, it returns empty string
        getPermutations(strWithoutThisChar, buffer + str[i], perms);
    }
}

vector<string> getPermutations(string str)
{
    vector<string> stringVector;
    if (str.empty()) return stringVector;

    getPermutations(str, "", stringVector);

    return stringVector;
}

void printCombinations(string str, string &buffer, unsigned int curPos)
{
    for (unsigned int i = curPos; i < str.length(); ++i)
    {
        buffer += str[i];
        cout << buffer << endl;

        printCombinations(str, buffer, i+1);
    }

    buffer = buffer.substr(0, buffer.length() - 2);
    return;
}

void printCombinations(string str)
{
    if (str.empty())
        return;

    string buffer = "";
    printCombinations(str, buffer, 0);
}

char getCharKey(int number, int pos)
{
    static char charList[10][3] = {{'0', '0', '0'}, {'1', '1', '1'}, {'a', 'b', 'c'}, {'d', 'e', 'f'},
        {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
    {'p', 'q', 'r'}, {'s', 't', 'u'}, {'v', 'w', 'x'}};

    return charList[number][pos-1];
}

void printTelephoneNumbersInAlphabets(int* number, int n, char* alphaNumber, int pos, int &count)
{
    if (pos >= n)
    {
        cout << alphaNumber << endl;
        count++;
        return;
    }

    for (int i = 1; i <= 3; ++i)
    {
        alphaNumber[pos] = getCharKey(number[pos], i);
        printTelephoneNumbersInAlphabets(number, n, alphaNumber, pos+1, count);
        
        if (number[pos] == 0 || number[pos] == 1)
            return;
    }
}

void printTelephoneNumbersInAlphabets(int* number, int n)
{
    if (!number)
        throw exception();

    char* alphaNumber = (char*)malloc(n * sizeof(char) + 1);
    if (!alphaNumber)
        throw exception();

    alphaNumber[n] = '\0';
    int count = 0;
    printTelephoneNumbersInAlphabets(number, n , alphaNumber, 0, count);
    cout << "Number of results: " << count << endl;
    free(alphaNumber);
}

int getNumWaysCoinsHelper(int N, int caseCents)
{
	int result = 0;

	if (N == 0) return 1;
	if (N < 0) return 0;

	if (N >= 25 && caseCents >= 25)
		result += getNumWaysCoinsHelper(N - 25, 25);		
	if (N >= 10 && caseCents >= 10)
		result += getNumWaysCoinsHelper(N - 10, 10);	
	if (N >= 5 && caseCents >= 5)
		result += getNumWaysCoinsHelper(N - 5, 5);	
	if (N >= 1 && caseCents >= 1)
		result += getNumWaysCoinsHelper(N - 1, 1);	

	return result;
}

int getNumWaysCoins(int N)
{
	if (N < 0) throw exception();

	return getNumWaysCoinsHelper(N, 25);
}

const int N = 8;
void printBoard(bool board[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int getQueenIndex(bool board[N][N], int col)
{
	for (int i = 0; i < N; ++i)
		if (board[i][col])
			return i;
	return -1;
}

void printQueensHelper(bool board[N][N], int col, int &count)
{
	if (col < 0) throw exception();
	
	if (col >= N)
	{
		//cout << "Found a way" << endl;
		count++;
		printBoard(board);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		bool isPossible = true;
		for (int j = 0; j < col || (j == 0 && col == 0); ++j)
		{
			int rowOfQueen = getQueenIndex(board, j);
			if (!((i != rowOfQueen && (col - i != j - rowOfQueen) && (col + i != j + rowOfQueen)) || col == 0))
			{
				isPossible = false;
				break;
			}
		}
		
		if (isPossible)
		{
			board[i][col] = true;
			printQueensHelper(board, col + 1, count);
			board[i][col] = false;
		}
	}
}

void printWaysToPlaceQueens()
{
	bool board[N][N];
	int count = 0;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			board[i][j] = false;

	printQueensHelper(board, 0, count);
	cout << "There are " << count << " ways." << endl;
}

int columnForRow[N];
bool check(int row)
{
	for (int i = 0; i < row; ++i)
	{
		int diff = abs(columnForRow[i] - columnForRow[row]);
		if (diff == 0 || diff == row - i)
			return false;
	}
	return true;
}

void printQueensSolution(int row, int &count)
{
	if (row == N)
	{
		count++;
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		columnForRow[row] = i;
		if (check(row))
			printQueensSolution(row + 1, count);
	}
}

int main()
{
    const int size = 20;
    int integers[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 40, 50, 55, 100, 2000, 3400, 10009, 23002, 30000};

    int target = 20;
    int index = binarySearchIterative(integers, target, size);
    cout << "index is: " << index << " ==? " << integers[index]  << " ==? target:" << target << endl;

    string someString = "abc";
    vector<string> permutations = getPermutations(someString);

    cout << "Number of permuations is: " << permutations.size() << endl;
    for (vector<string>::iterator it = permutations.begin(); it != permutations.end(); ++it)
    {
        cout << *it << endl;
    }
	cout << endl;

	/*
    cout << endl;
    cout << "Combinations of " << someString << ":" << endl;
    printCombinations(someString);

    cout << endl;
    const int phoneNumberLength = 7;
    int phoneNumber[phoneNumberLength] = {4, 9, 7, 7, 4, 2, 7};
    printTelephoneNumbersInAlphabets(phoneNumber, phoneNumberLength);
	*/

	/*
	int N = 25;
	cout << "Number of ways to represent " << N << "cents is: " << getNumWaysCoins(N) << endl;
	*/

	printWaysToPlaceQueens();
	int count = 0;
	printQueensSolution(0, count);
	cout << "Count by solution is: " << count << endl;

    char c;
    cin >> c;
    return 0;
}