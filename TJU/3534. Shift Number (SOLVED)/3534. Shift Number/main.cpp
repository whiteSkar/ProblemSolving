#include <iostream>

using namespace std;

int main()
{
	long long input = -1;
	long long output = 0;
	long long multiplier = 10;
	long long divident = 1111111111111111111;

	while ( 1 )
	{
		cin >> input;
		if ( input == 0 )
		{
			return 0;
		}

		for ( int i = 0; i < 18; i++ )
		{
			if ( input % divident == 0)
			{
				output = input / divident;
				break;
			}
			divident /= multiplier;
		}
		divident = 1111111111111111111;

		if ( output == 0 )
		{
			output = input;
		}
		cout << output << endl;
		output = 0;
	}

	return 0;
}
