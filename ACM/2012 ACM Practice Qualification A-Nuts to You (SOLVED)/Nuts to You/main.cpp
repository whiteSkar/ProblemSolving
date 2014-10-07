#include <iostream>

using namespace std;

int main()
{
	int turn = 0;
	int numToGet = 1;
	int numCorn;
	int numIGet = 0;

	while ( cin >> numCorn )
	{
		while ( numCorn > 0 )
		{
			if ( turn == 0 )
			{
				numCorn -= numToGet;
				numToGet++;
				turn = 1;
			}
			else
			{
				if ( numCorn - numToGet >= 0 )
				{
					numIGet += numToGet;
					numCorn -= numToGet;
				}
				else
				{
					numIGet += numCorn;
				}
				numToGet++;
				turn = 0;
			}
		}	
		cout << numIGet << endl;
		numIGet = 0;
		numToGet = 1;
		turn = 0;
	}
	return 0;
}