#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	int numTest;
	cin >> numTest;

	for (int k = 1; k <= numTest; k++)
	{
		int numWire, numSwitch;
		cin >> numWire >> numSwitch;

		unordered_set<int> roughlyFoundWire;
		map<int, int> foundWire;

		int i;
		for (i = 1; i+2 <= numSwitch; i += 3)
		{
			cout << "FLIP " << i << endl;
			cout << "FLIP " << i+1 << endl;
			cout << "FLIP " << i+2 << endl;

			for (int j = 1; j <= numWire; ++j)
			{
				if (roughlyFoundWire.find(j) == roughlyFoundWire.end())
				{
					cout << "PROBE " << j << endl;
					string temp;
					cin >> temp;

					if (temp == "YES")
					{
						roughlyFoundWire.insert(j);
					}
				}
			}

			unordered_set<int> foundWiresForTheseSwithces = roughlyFoundWire;

			cout << "FLIP " << i << endl;
			for (auto it = foundWiresForTheseSwithces.begin(); it != foundWiresForTheseSwithces.end(); it++)
			{
				cout << "PROBE " << *it << endl;
				string temp;
				cin >> temp;

				if (temp == "NO")
				{
					foundWire.insert(pair<int, int>(*it, i));
				}
			}

			for (auto it = foundWire.begin(); it != foundWire.end(); it++)
			{
				auto itt = foundWiresForTheseSwithces.find(it->first);
				if (itt != foundWiresForTheseSwithces.end())
					foundWiresForTheseSwithces.erase(itt);
			}

			cout << "FLIP " << i+1 << endl;
			for (auto it = foundWiresForTheseSwithces.begin(); it != foundWiresForTheseSwithces.end(); it++)
			{
				cout << "PROBE " << *it << endl;
				string temp;
				cin >> temp;

				if (temp == "NO")
				{
					foundWire.insert(pair<int, int>(*it, i+1));
				}
			}

			for (auto it = foundWire.begin(); it != foundWire.end(); it++)
			{
				auto itt = foundWiresForTheseSwithces.find(it->first);
				if (itt != foundWiresForTheseSwithces.end())
					foundWiresForTheseSwithces.erase(itt);
			}

			for (auto it = foundWiresForTheseSwithces.begin(); it != foundWiresForTheseSwithces.end(); it++)
			{
				if (foundWire.find(*it) == foundWire.end())
				{
					foundWire.insert(pair<int, int>(*it, i+2));
				}
			}
		}

		if (i == numSwitch)
		{
			for (int j = 1; j <= numWire; ++j)
			{
				if (foundWire.find(j) == foundWire.end())
				{
					foundWire.insert(pair<int, int>(j, i));
				}
			}
		}

		if (i == numSwitch - 1)
		{

		}

		/*
		int i;
		for (i = 1; i+1 <= numSwitch; i += 2)
		{
			cout << "FLIP " << i << endl;
			cout << "FLIP " << i+1 << endl;

			for (int j = 1; j <= numWire; ++j)
			{
				if (roughlyFoundWire.find(j) == roughlyFoundWire.end())
				{
					cout << "PROBE " << j << endl;
					string temp;
					cin >> temp;

					if (temp == "YES")
					{
						roughlyFoundWire.insert(j);
					}
				}
			}

			cout << "FLIP " << i << endl;
			for (auto it = roughlyFoundWire.begin(); it != roughlyFoundWire.end(); it++)
			{
				cout << "PROBE " << *it << endl;
				string temp;
				cin >> temp;

				if (temp == "NO")
				{
					foundWire.insert(pair<int, int>(*it, i));
				}
			}

			for (auto it = roughlyFoundWire.begin(); it != roughlyFoundWire.end(); it++)
			{

				if (foundWire.find(*it) == foundWire.end())
				{
					foundWire.insert(pair<int, int>(*it, i+1));
				}
			}
		}

		if (i == numSwitch)
		{
			for (int j = 1; j <= numWire; ++j)
			{
				if (foundWire.find(j) == foundWire.end())
				{
					foundWire.insert(pair<int, int>(j, i));
				}
			}
		}
		*/

		/*
		map<int, int> myMap;

		for (int i = 1; i <= numSwitch; ++i)
		{
			if (numSwitch - i == 0)
			{
				for (int j = 1; j <= numWire; ++j)
				{
					if (myMap.find(j) == myMap.end())
					{
						myMap.insert(pair<int, int>(j, i));
					}
				}

				break;
			}
			cout << "FLIP " << i << endl;
			for (int j = 1; j <= numWire; ++j)
			{
				if (myMap.find(j) == myMap.end())
				{
					cout << "PROBE " << j << endl;
					string temp;
					cin >> temp;

					if (temp == "YES")
					{
						myMap.insert(pair<int, int>(j, i));
					}
				}
			}

			if (myMap.size() == numWire)
				break;

		}
					*/
		cout << "DONE" << endl;
		for (auto it = foundWire.begin(); it != foundWire.end(); it++)
			cout << it->second << " ";
		cout << endl;

		foundWire.clear();
		roughlyFoundWire.clear();
		//cout << "Case #" << k << ": " << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}
