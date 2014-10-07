#include <iostream>
#include <vector>

using namespace std;

void removeVectorElement(vector<int> vec)
{
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << &*it << " ";
	}
	cout << endl;
	vec.pop_back();
};

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	removeVectorElement(vec);

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << &*it << " ";
	}
	cout << endl;

	char c;
	cin >> c;
	return 0;
}