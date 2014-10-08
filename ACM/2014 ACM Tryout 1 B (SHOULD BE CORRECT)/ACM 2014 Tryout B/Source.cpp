#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

pair<int, int> enemy[5];

bool myfunction (pair<int, int> p1, pair<int, int> p2) 
{
	double p1Ratio = (double) p1.second / (double) p1.first;
	double p2Ratio = (double) p2.second / (double) p2.first;

	if (p1Ratio >= p2Ratio)
	{
		if (p1Ratio == p2Ratio && p1.first > p2.first)
			return false;

		return true;
	}
	return false;
};

int main()
{
	//ifstream inputFile("input.txt");	// change to cin

	int numTest;
	cin >> numTest;

	int ourDamage = 0;
	int enemyDamage = 0;
	for (int k = 1; k <= numTest; k++)
	{
		for (int i = 0; i < 5; ++i)
		{
			cin >> enemy[i].first;
		}
		for (int i = 0; i < 5; ++i)
		{
			int temp;
			cin >> temp;
			enemy[i].second = temp;
			enemyDamage += temp;
		}
		for (int i = 0; i < 5; ++i)
		{
			int temp;
			cin >> temp;
			ourDamage += temp;
		}

		sort(enemy + 0, enemy + 5, myfunction);

		double result = 0;
		for (int i = 0; i < 5; ++i)
		{
			result += (double)enemyDamage * ((double)enemy[i].first / (double)ourDamage);
			enemyDamage -=	enemy[i].second;
		}

		cout << fixed << setprecision(5) << result << endl;
	}

	//inputFile.close();

	return 0;
}
