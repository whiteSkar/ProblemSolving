#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int getNthFib(int N)
{
	if (N < 0) throw exception();
	if (N == 0) return 0;
	if (N == 1) return 1;

	return getNthFib(N - 1) + getNthFib(N - 2);
}

typedef pair<int, int> fibType;

int getNthFibHelper(int N, unordered_map<int, int> &fibMap)
{
	auto it = fibMap.find(N);
	if (it != fibMap.end())
		return it->second;

	int result = getNthFibHelper(N - 2, fibMap) + getNthFibHelper(N - 1, fibMap);
	fibMap.insert(fibType(N, result));

	return result;
}

int getNthFibDP(int N)
{
	if (N < 0) throw exception();
	unordered_map<int, int> fibMap;
	fibMap.insert(fibType(0 ,0));
	fibMap.insert(fibType(1, 1));
	
	return getNthFibHelper(N, fibMap);
}

int getNthFibIterative(int N)
{
	if (N < 0) throw exception();
	if (N == 0) return 0;

	int a = 1, b = 1, result = b;

	for (int i = 3; i <= N; ++i)
	{
		result = a + b;
		a = b;
		b = result;
	}

	return result;
}

typedef pair<int, int> posType;
typedef pair<posType, int> pathType;

// Since the key for the map is a pair (posType), the map needs a custom hash function. 
namespace std 
{
	template <> struct hash<posType>
	{
		size_t operator()(const posType & x) const
		{
			posType pos = x;
			return hash<int>()(pos.first + pos.second * 17);
		}
	};
}

int getRobotPathHelper(posType pos, unordered_map<posType, int> &pathMap)
{
	auto it = pathMap.find(pos);
	if (it != pathMap.end()) return it->second;

	int numPath;

	if (pos.first == pos.second)
	{
		numPath = getRobotPathHelper(posType(pos.first - 1, pos.second), pathMap) * 2;
	}
	else if (pos.first == 1)
	{
		numPath = getRobotPathHelper(posType(pos.first, pos.second - 1), pathMap) + 1;
	}
	else
	{
		numPath = getRobotPathHelper(posType(pos.first - 1, pos.second), pathMap) + getRobotPathHelper(posType(pos.first, pos.second - 1), pathMap);
	}

	pathMap.insert(pathType(pos, numPath));
	return numPath;
}

int getRobotPath(int N)
{
	if (N < 1) return 0;

	unordered_map<posType, int> pathMap;
	pathMap.insert(pathType(posType(0, 1), 1));
	pathMap.insert(pathType(posType(1, 1), 2));

	return getRobotPathHelper(posType(N, N), pathMap);
}

void printParenthesesHelper(int numLeft, int numRight, string str)
{
	if (numRight == 0 )
	{
		cout << str << endl;
		return;
	}

	if (numLeft > 0)
		printParenthesesHelper(numLeft - 1, numRight, str + "(");
	if (numRight > numLeft)
		printParenthesesHelper(numLeft, numRight - 1, str + ")");
}

void printParentheses(int N)
{
	if (N < 0) throw exception();

	printParenthesesHelper(N, N, "");
}

int main()
{
	int N = 15;
	cout << "getNthFib: " << getNthFib(N) << endl;
	cout << "getNthFibDP: " << getNthFibDP(N) << endl;
	cout << "getNthFibIterative: " << getNthFibIterative(N) << endl;
	cout << endl;

	int D = 7;
	cout << "robotPath: " << getRobotPath(D) << endl;
	cout << endl;

	printParentheses(4);

	char c;
	cin >> c;
	return 0;
}