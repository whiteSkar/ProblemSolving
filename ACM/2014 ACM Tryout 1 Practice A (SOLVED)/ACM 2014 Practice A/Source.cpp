#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

double getZSubOne(double a, double b, double n, double z0)
{
	if (n == 0)
		return z0;

	return a * getZSubOne(a, b, n - 1, z0) + b;
}

int main()
{
	//ifstream inputFile("input.txt");	// change to cin

	double a, b, z0, n, result = 0;

	while (cin >> a)
	{
		cin >> b >> z0 >> n;

		cout << std::setprecision(3) << fixed << getZSubOne(a, b, n, z0) << endl;
	}

	//inputFile.close();

	return 0;
}
