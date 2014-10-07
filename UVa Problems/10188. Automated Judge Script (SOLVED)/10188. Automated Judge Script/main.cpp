#include <iostream>
#include <string>

using namespace std;

#define HOW_MANY 100
#define CHAR_LENGTH 100

int runCount = 1;

string answer[HOW_MANY];
string input[HOW_MANY];
int answerN[HOW_MANY * CHAR_LENGTH];
int inputN[HOW_MANY * CHAR_LENGTH];
int answerCount = 0;
int inputCount = 0;

bool exactMatch( string answer[], string input[], int n );
bool exactMatchHelper( string answer, string input );
bool numericMatchHelper( int answer[], int input[] );
bool checkNumeric( string answer[], string input[], int n, int m );
void answerNumeric( string answer );
void inputNumeric ( string input );



int main( void )
{
	int n, m;
	string nS, mS;

	cin >> n;
	while ( n != 0)
	{
		answerCount = 0;
		inputCount = 0;

		cin.get();
		
		for ( int i = 0; i < n; i++ )
		{
			getline( cin, answer[i] );
		}
		
		cin >> m;
		cin.get();

		for ( int i = 0; i < m; i++ )
		{
			getline( cin, input[i] );
		}
		
		if ( m == n )
		{
			if ( exactMatch( answer, input, n ) )
			{
				cout << "Run #" << runCount++ << ": Accepted" << endl;
				cin >> n;
				continue;
			}
		}
		
		if ( checkNumeric( answer, input, n, m ) )
			cout << "Run #" << runCount++ << ": Presentation Error" << endl;
		else
			cout << "Run #" << runCount++ << ": Wrong Answer" << endl;

		cin >> n;
	}

	return 0;
}


bool exactMatch( string answer[], string input[], int n )	// if lengths of answer and input are different, this function shouldn't be called
{
	for ( int i = 0; i < n; i++ )
	{
		if ( answer[i].length() != input[i].length() )
			return false;

		if ( !exactMatchHelper( answer[i], input[i] ) )
			return false;
	}

	return true;
}

bool exactMatchHelper( string answer, string input )
{
	for ( unsigned int j = 0; j < answer.length(); j++ )
	{
		if ( answer[j] != input[j] )
		{
			return false;
		}
	}

	return true;
}

bool numericMatchHelper( int answer[], int input[] )
{
	if ( answerCount != inputCount )
		return false;

	for ( int j = 0; j < answerCount; j++ )
	{
		if ( answer[j] != input[j] )
		{
			return false;
		}
	}

	return true;
}

bool checkNumeric( string answer[], string input[], int n, int m )
{
	for ( int i = 0; i < n; i++ )
	{
		answerNumeric( answer[i] );
	}

	for ( int i = 0; i < m; i++ )
	{
		inputNumeric( input[i] );
	}

	return numericMatchHelper( answerN, inputN );
}

void answerNumeric( string answer )
{
	for ( unsigned int i = 0; i < answer.length(); i++ )
	{
		if ( isdigit( answer[i] ) )
			answerN[answerCount++] = answer[i];
	}	
}

void inputNumeric ( string input )
{
	for ( unsigned int i = 0; i < input.length(); i++ )
	{
		if ( isdigit( input[i] ) )
			inputN[inputCount++] = input[i];
	}
}
