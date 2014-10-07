#include <iostream>
#include <algorithm>

using namespace std;

struct peasant{
	short pos;
	short dest;
};

struct peasant listB[30000];
struct peasant listR[30000];
int numB;
int numR;
int numPair;

bool comparator( const struct peasant &a, const struct peasant &b )
{
	return a.pos < b.pos;
}

int findPrevR( struct peasant a[], struct peasant b[], int numOfb, int index );
int findNext( struct peasant a[], struct peasant b[], int numOfb, int index );
void checkAllB( struct peasant a[], struct peasant b[], int numA, int numB );

int main()
{
	int numScenario;

	cin >> numScenario;
	for ( int a = 0; a < numScenario; a++ )
	{
		if ( a != 0 )
		{
			cout << endl;
		}

		numPair = 0;
		cin >> numB >> numR;
		for ( int i = 0; i < numB; i++ )
		{
			cin >> listB[i].pos >> listB[i].dest;
		}
		for ( int i = 0; i < numR; i++ )
		{
			cin >> listR[i].pos >> listR[i].dest;
		}

		sort( listB, listB+numB, comparator );
		sort( listR, listR+numR, comparator );

		if ( numB >= numR )
		{
			checkAllB( listB, listR, numB, numR );
		}
		else
		{
			checkAllB( listR, listB, numR, numB );
		}

		cout << "Scenario #" << a+1 << ":" << endl;
		cout << numPair << endl;
	}
	return 0;
}

int findPrev( struct peasant a[], struct peasant b[], int numOfb, int index )
{
	int i;

	for ( i = 0; i < numOfb; i++ )
	{
		if ( b[i].pos > a[index].pos )
		{
			return i-1;
		}
	}
	if ( i == numOfb )
	{
		return numOfb-1;;
	}
	return -1;
}

int findNext( struct peasant a[], struct peasant b[], int numOfb, int index )
{
	int i;

	for ( i = numOfb-1; i >= 0; i-- )
	{
		if ( b[i].pos < a[index].pos )
		{
			return i+1;
		}
	}
	if ( i == -1 )
	{
		return 0;
	}
	return -1;
}

void checkAllB( struct peasant a[], struct peasant b[], int numOfa, int numOfb )
{
	for ( int index = 0; index < numOfa; index++ )
	{
		bool crossed = false;
		int i = findPrev( a, b, numOfb, index );
		int j = 0;

		if ( a[index].pos > b[numOfb-1].pos && a[index].dest > b[numOfb-1].dest )
		{
			return;
		}

		if ( i >= 0 )
		{
			j = i+1;
			for ( ; i >= 0; i-- )
			{
				if ( b[i].dest >= a[index].dest )
				{
					crossed = true;
					numPair++;
				}
				else
				{
					break;
				}
			}

			if ( crossed )
			{
				continue;
			}
		}

		if ( j > 0)
		{
			for ( ; j < numOfb; j++ )
			{
				if ( b[j].dest <= a[index].dest )
				{
					numPair++;
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			j = findNext( a, b, numOfb, index );
			if ( j >= 0 )
			{
				for ( ; j < numOfb; j++ )
				{
					if ( b[j].dest <= a[index].dest )
					{
						numPair++;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
}