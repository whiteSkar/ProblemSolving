#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main( void )
{
	string inputA;
	string inputB;
	string output = "";
	int cPos;

	while ( getline( cin, inputA ) && getline( cin, inputB ) )
	{
		for ( int i = 0; i < inputA.length(); i++ )
		{
			cPos = inputB.find( inputA[i], 0 );
			if ( cPos != string::npos )
			{
				output.push_back( inputA[i] );
				inputB.erase( cPos, 1 );
			}
		}
		sort( output.begin(), output.end() );
		cout << output << endl;
		output.clear();
	}

	return 0;
}
