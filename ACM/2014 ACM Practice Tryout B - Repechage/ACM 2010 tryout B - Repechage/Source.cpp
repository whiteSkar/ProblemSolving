#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
 
using namespace std;
 
int main()
{
    int N;
 
	while (true)
	{
		cin >> N;
		if (N == 0) break;

		string first;
		string second;
        map<string, vector<string>> myMap;
		
		int numLines = pow(2, N) - 1;
		for (int i = 0; i < numLines; ++i)
		{
			cin >> first >> second;
			
			auto it = myMap.find(first);
			if (it == myMap.end())
			{
				vector<string> temp;
				temp.push_back(second);
				myMap.insert(pair<string, vector<string>>(first, temp));
			}
			else
			{
				it->second.push_back(second);
			}
		}

		string gold;
		string silver;
		vector<string> repechage;

		for (auto it = myMap.begin(); it != myMap.end(); ++it)
		{
			if (it->second.size() == N)
			{
				gold = it->first;
				
				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
					repechage.push_back(*it2);
			}
			
			if (it->second.size() == N - 1)
			{
				silver = it->first;

				for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
					repechage.push_back(*it2);
			}
		}

		sort(repechage.begin(), repechage.end());

		cout << "Gold: " << gold << endl;
		cout << "Silver: " << silver << endl;
		cout << "Repechage:";
		for (auto it = repechage.begin(); it != repechage.end(); ++it)
		{
			if (*it == silver) continue;

			cout << " " << *it;
		}
		cout << endl;
    }
 
    return 0;
}