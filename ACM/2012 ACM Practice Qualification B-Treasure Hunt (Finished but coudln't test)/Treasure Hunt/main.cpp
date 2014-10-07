#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int input1; int input2;
	int output;

	while ( cin >> input1 )
	{
		cin >> input2;

		if ( input1 <= 0 || input2 <= 0 )
		{
			return 0;
		}

		output = max( input1, input2 ) / 2;

		cout << output << endl;
	}
	return 0;
}