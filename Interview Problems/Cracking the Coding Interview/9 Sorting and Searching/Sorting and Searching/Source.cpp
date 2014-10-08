#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// A has enough buffer at the end to hold all the elements of B
void mergeAIntoBOrdered(int* A, int sizeA, int* B, int sizeB)
{
	if (!A || !B || sizeA < 0 || sizeB < 0) throw exception();
	if (sizeB == 0) return;

	int indexA = sizeA -1;
	int indexB = sizeB - 1;
	int indexResult = sizeA + sizeB - 1;

	while (indexA >= 0 && indexB >= 0)
	{
		if (A[indexA] > B[indexB])
		{
			A[indexResult--] = A[indexA--];
		}
		else
		{
			A[indexResult--] = B[indexB--];
		}
	}

	while (indexB >= 0)
	{
		A[indexResult--] = B[indexB--];
	}
};

void sortAnagramsStickTogether(vector<string>* strings)
{
	if (strings->empty() || strings->size() == 1) return;

	multimap<string, string> myMap;	// map does not allow duplicate keys. multimap does

	for (auto it = strings->begin(); it != strings->end(); ++it)
	{
		string temp = *it;	// string assignment in c++ is always pass by value. string is immutable and always new string are created
		sort(temp.begin(), temp.end());
		myMap.insert(pair<string, string>(temp, *it)); // same here. new string
	}

	strings->clear();	// values in the myMap stays after this call since strings are immutable and new strings are passed in

	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		strings->push_back(it->second);
	}
};

// assume no duplicates
int getIndexOfInARotatedSortedArray(int* A, int size, int target)
{
	if (!A || size < 0) throw exception();
	if (size == 0) return -1;
	if (size == 1)
	{
		if (A[0] == target) return 0;
		else return -1;
	}
	if (size == 2)
	{
		if (A[0] == target) return 0;
		if (A[1] == target) return 1;
		return -1;
	}

	int previous = A[0], high = size - 1, low = 0, index = (high + low) / 2;

	while (high != low)
	{
		if ((high - low) == 1)
		{
			if (A[high] < A[low])
			{
				high = low;
				index = low;
			}
			else
			{
				low = high;
				index = high;
			}
		}
		else
		{
			if (A[index] < previous)
			{
				high = index;
				previous = A[index];
				index = (high + low) / 2;
			}
			else
			{
				low = index;
				previous = A[index];
				index = (high + low + 1) / 2;
			}
		}
	}
	index = (index + 1) % size;

	if (target < A[index])
	{
		low = 0;
		high = index - 1;
	}
	else if (target > A[index])
	{
		if (target > A[size - 1])
		{
			low = 0;
			high = index - 1;
		}
		else
		{
			low = index + 1;
			high = size - 1;
		}
	}
	else
	{
		low = index;
		high = index;
	}

	if (high < 0) return -1;

	index = (high + low) / 2;
	while (low != high)
	{
		if (target < A[index])
			high = index - 1;
		else if (target > A[index])
			low = index + 1;
		else
			low = high = index;

		index = (high + low) / 2;
	}

	if (target == A[index])
		return index;
	else
		return -1;
};

int main()
{
	// 1
	int A[15];
	int B[5];
	A[0] = 1;
	A[1] = 3;
	A[2] = 7;
	A[3] = 10;
	A[4] = 15;
	A[5] = 16;
	A[6] = 16;
	A[7] = 17;
	A[8] = 20;
	A[9] = 30;

	B[0] = -1;
	B[1] = 5;
	B[2] = 8;
	B[3] = 18;
	B[4] = 29;

	mergeAIntoBOrdered(A, 10, B, 5);

	for (int i = 0; i < 15; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl << endl;

	// 2
	vector<string> strings;
	strings.push_back("bac");
	strings.push_back("bec");
	strings.push_back("ccaa");
	strings.push_back("a");
	strings.push_back("ceb");
	strings.push_back("acac");
	strings.push_back("b");
	strings.push_back("acb");
	strings.push_back("abc");
	strings.push_back("dddef");
	strings.push_back("caca");

	sortAnagramsStickTogether(&strings);

	for (auto it = strings.begin(); it != strings.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl << endl;

	// 3
	const int size = 12;
	int arr[size] = {15,16,19,20,25,1,3,4,5,7,10,14};

	cout << "Index is: " << getIndexOfInARotatedSortedArray(arr, size, 5);	// should be 8
	cout << endl << endl;


	return 0;
}