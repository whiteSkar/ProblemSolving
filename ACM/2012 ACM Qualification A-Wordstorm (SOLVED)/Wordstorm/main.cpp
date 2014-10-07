#include <iostream>
#include <algorithm>


using namespace std;

void deepCopy( char a[], char b[] );
void clearList( char a[] );
int getLength( char a[]);

int main()
{
	char target[10];
	char test[10];
	char targetSorted[10];
	char testSorted[10];
	char central;
	int numTest;
	int pos = 0;
	int length;
	bool contains = false;
	bool valid = true;
	bool found = false;

	while ( cin >> targetSorted )
	{
		central = targetSorted[4];

		deepCopy( targetSorted, target );

		sort( targetSorted, targetSorted+9 );

		cin >> numTest;
		for ( int i = 0; i < numTest; i++ )
		{
			cin >> testSorted;

			deepCopy( testSorted, test );

			length = getLength( testSorted );
			if ( length  < 4 )
			{
				cout << test << " is invalid" << endl;
				continue;
			}

			sort( testSorted, testSorted+length );

			for ( int j = 0; j < length; j++ )
			{
				if ( testSorted[j] == central )
				{
					contains = true;
					break;
				}
			}
			if ( !contains )
			{
				cout << test << " is invalid" << endl;
				continue;
			}

			for ( int j = 0; j < length; j++ )
			{
				for ( int k = 0; k < 9; k++ )
				{
					if ( found )
					{
						k = pos;
					}
					found = false;
					if ( testSorted[j] == targetSorted[k] )
					{
						pos = k+1;
						found = true;
						break;
					}
				}

				if ( !found )
				{
					cout << test << " is invalid" << endl;
					break;
				}
				//found = false;
			}
			
			if ( found )
			{
				cout << test << " is valid" << endl;
			}
			pos = 0;
			contains = false;
			valid = true;
			found = false;
			clearList( testSorted );
		}
		clearList( targetSorted );
	}
	return 0;
}

void deepCopy( char a[], char b[] )
{
	for ( int i = 0; i < 10; i++ )
	{
		b[i] = a[i];
	}
}

void clearList( char a[] )
{
	for ( int i = 0 ;i < 9; i++ )
	{
		a[i] = 0;
	}
}

int getLength( char a[])
{
	for ( int i = 0; i < 10; i++ )
	{
		if ( a[i] == 0 )
		{
			return i;
		}
	}
	return 10;
}