#include <iostream>
//#include <fstream>
#include <string>
#include <map>

using namespace std;


int inputCount;
string cryptic_string = "the quick brown fox jumps over the lazy dog";
string base_string;
string input[200];
string output[200];
map<char, char> charMapping;


void printOutput();
void translateAllMessage();
void translateLine( int index );
void mapBaseToCrypt();
bool findBaseString();
bool checkIfCryptic( string s );


int main( void )
{
	int numCases;
	string garbage;

	//ifstream myFile( "test.txt" );

	//myFile >> numCases;
	//myFile.get();

	cin >> numCases;
	cin.get();

	for ( int i = 0; i < numCases; i++ )
	{
		int j = 0;
		inputCount = 0;
		
		if ( i == 0 )
		{
			//getline( myFile, garbage );
			getline( cin, garbage );	// blank line
		}
		else
		{
			cout << endl;	// separate test cases
		}
		
		while ( 1 )
		{
			//getline( myFile, input[j] );
			getline( cin, input[j] );

			if ( input[j] == "" )
				break;

			inputCount++;
			j++;
		}

		if ( !findBaseString() )
		{
			cout << "No solution." << endl;
			continue;
		}

		mapBaseToCrypt();
		translateAllMessage();
		printOutput();
		if ( i != numCases - 1 )
			cout << endl;
	}
	
	return 0;
}

void printOutput()
{
	for ( int i = 0; i < inputCount; i++ )
	{
		cout << output[i];
		
		if ( i != inputCount-1 )
			cout << endl;
	}
}

void translateAllMessage()
{
	for ( int i = 0; i < inputCount; i++ )
	{
		translateLine( i );
	}
}

void translateLine( int index )
{
	map<char, char>::iterator it;
	output[index] = "";

	for ( unsigned int i = 0; i < input[index].length(); i++ )
	{
		it = charMapping.find( input[index][i] );
		output[index].push_back( it->second );
	}
}

void mapBaseToCrypt()
{
	charMapping.clear();

	for ( unsigned int i = 0; i < base_string.length(); i++ )
	{
		charMapping.insert( pair<char, char>( base_string[i], cryptic_string[i] ) );
	}
	charMapping.insert (pair<char, char>( ' ', ' ' ) );
}

bool findBaseString()
{
	for ( int i = 0; i < inputCount; i++ )
	{
		base_string = "";
		if ( checkIfCryptic( input[i] ) )
			return true;
	}

	return false;
}

bool checkIfCryptic( string s )		// brute force. Any other way?
{
	if ( s.length() != cryptic_string.length() )
		return false;
	
	for ( unsigned int i = 0; i < s.length(); i++ )
	{
		if ( i == 3 || i == 9 || i == 15 || i == 19 || i == 25 || i == 30 || i == 34 || i == 39 )
		{
			if ( s[i] != ' ' )
				return false;
			base_string.push_back( ' ' );
		}
		else if ( i == 17 || i == 21 || i == 26 || i == 28 || i == 29 || i == 31 || i == 32 || i == 33 || i == 41 )
		{
			if ( i == 17 )
			{
				if ( s[i] != base_string[12] )		// 'o'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 21 )
			{
				if ( s[i] != base_string[5] )		// 'u'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 26 )
			{
				if ( s[i] != base_string[12] )		// 'o'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 28 )
			{
				if ( s[i] != base_string[2] )		// 'e'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 29 )
			{
				if ( s[i] != base_string[11] )		// 'r'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 31 )
			{
				if ( s[i] != base_string[0] )		// 't'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 32 )
			{
				if ( s[i] != base_string[1] )		// 'h'
					return false;

				base_string.push_back( s[i] );
			}
			else if ( i == 33 )
			{
				if ( s[i] != base_string[2] )		// 'e'
					return false;

				base_string.push_back( s[i] );
			}
			else
			{
				if ( s[i] != base_string[12] )		// 'o'
					return false;

				base_string.push_back( s[i] );
			}
		}
		else
		{
			if ( base_string.find( s[i] ) != string::npos )
				return false;
			else
				base_string.push_back( s[i] );
		}
	}

	return true;
}
