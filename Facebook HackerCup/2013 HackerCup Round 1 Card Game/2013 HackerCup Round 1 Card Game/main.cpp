#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

const ull modulo = 1000000007;

ull getPascal( int line, int pos );
ull factorial( int value );

ull a[10000];

int main()
{
	ifstream inFile( "card_game.txt" );
	ofstream outFile( "output.txt" );
	string data;
	int numTest, n, k;
	ull result;

	inFile >> numTest;

	for ( int i = 0; i < numTest; i++ )
	{
		result = 0;

		inFile >> n >> k;
		for ( int j = 0; j < n; j++ )
		{
			inFile >> a[j];
		}

		vector<ull> av( a, a+n );
		sort( av.begin(), av.end() );
		reverse( av.begin(), av.end() );

		int m = 0;
		for ( int j = n; j >= k; j-- )
		{
			result += getPascal( j-1, k-1 ) * av[m];
			result = result % modulo;
			m++;
		}

		outFile << "Case #" << i+1 << ": " << result;
		if ( i != numTest-1 )
			outFile << endl;
	}

	inFile.close();
	outFile.close();

	return 0;
}

ull getPascal( int line, int pos )
{
	return factorial( line ) / ( ( factorial(line-pos) * factorial(pos) ) % modulo );
}

ull factorial( int value )
{
	ull result = 1;

	for ( int i = value % modulo; i > 1; i-- )
	{
		result *= i;
		result = result % modulo;
	}

	return result;
}