#include <iostream>

using namespace std;

#define MAX 80000

int cows[MAX];
long long sum = 0;
int numCows;
//int jump;


long long getSum( int num );
int findEnd( int index );

int main()
{
	while ( cin >> numCows )
	{
		for ( int i = 0; i < numCows; i++ )
		{
			cin >> cows[i];
		}

		/*
		for ( int i = 0; i < numCows-1; i++ )
		{
			for ( int j = i+1; j < numCows; j++ )
			{
				if ( cows[i] <= cows[j] )
				{
					break;
				}
				sum++;
			}
		}
		*/

		/*
		int j = 0;
		int k = 0;
		while ( j < numCows-1 )
		{
			while ( cows[j] > cows[j+1] )
			{
				j++;
			}
			sum += getSum( j-k );
			k = j+1;
			j++;
		}
		*/

		findEnd( 0 );

		cout << sum << endl;
		sum = 0;
	}
	return 0;
}

long long getSum( int num )
{
	if ( num == 0 )
	{
		return 0;
	}

	return num + getSum( num-1 );
}

int findEnd( int index )
{
	if ( cows[index] <= cows[index+1] )
	{
		return index;
	}
	
	/////

	return findEnd( index+1 );
}

/*
int findEnd( int index )
{
	int jump;
	if ( cows[index] <= cows[index+1] )
	{
		return index;
	}

	int j = index;
	int k = index;
	while ( j < numCows-1 )
	{
		jump = findEnd( j+1 );
		sum += getSum( jump-k );
		k = j+1;
		j = jump;
	}
}
*/