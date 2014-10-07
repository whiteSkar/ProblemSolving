#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int numHouses;

	while (cin >> numHouses)
	{
		vector<int> houses;
		for (int i = 0; i < numHouses; ++i)
		{
			int houseNumber;
			cin >> houseNumber;

			houses.push_back(houseNumber);
		}

		int startingHouseNumber;
		cin >> startingHouseNumber;

		sort(houses.begin(), houses.end());

		int leftHouse = houses.front();
		int rightHouse = houses.back();

		int distanceFromStartingToCloserEndHouse = min(abs(startingHouseNumber - leftHouse), abs(rightHouse - startingHouseNumber));
		int distanceFromEndToEnd = rightHouse - leftHouse;

		int totalMinDistance = distanceFromEndToEnd + distanceFromStartingToCloserEndHouse;
		int result = totalMinDistance + numHouses;

		cout << result << endl;
	}

	return 0;
}
