#include <iostream>
#include <string>

using namespace std;

int main( void )
{
	int numOfProblems;
	int numOfWords;
	int numOfOccurance = 0;
	string input;
	const string targetString = "sheep";

	cin >> numOfProblems;
	for ( int i = 0; i < numOfProblems; i++ )
	{
		if ( i != 0 )
		{
			cout << endl;
		}

		cin >> numOfWords;
		for ( int j = 0; j < numOfWords; j++ )
		{
			cin >> input;
			if ( input.compare( targetString ) == 0 )	// input == targetString works, too
			{
				numOfOccurance++;
			}
		}
		cout << "Case " << (i+1) << ": This list contains " << numOfOccurance << " sheep." << endl;
		numOfOccurance = 0;
	}
	return 0;
}
