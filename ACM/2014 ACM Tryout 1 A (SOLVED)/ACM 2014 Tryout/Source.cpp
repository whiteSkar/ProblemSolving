#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	//ifstream inputFile("input.txt");	// change to cin

	int numCheese;
	cin >> numCheese;

	while (numCheese > 0)
	{
		int numCheeses[3];
		numCheeses[0] = 0;
		numCheeses[1] = 0;
		numCheeses[2] = 0;

		for (int i = 0; i < numCheese; ++i)
		{
			string input;
			cin >> input;

			if (input == "Cheddar")
				numCheeses[0]++;
			if (input == "Gouda")
				numCheeses[1]++;
			if (input == "Havarti")
				numCheeses[2]++;
		}

		sort(numCheeses + 0, numCheeses + 3);

		int result = max(numCheeses[0] * 3, numCheeses[1] * 2);
		result = max(numCheeses[2], result);

		cout << result << endl;

		cin >> numCheese;
	}

	//inputFile.close();

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