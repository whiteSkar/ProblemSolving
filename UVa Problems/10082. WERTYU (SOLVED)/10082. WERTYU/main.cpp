#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

char getCharOnLeft( char c );

string keyBoard = "1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main( void )
{
	string input;
	string output;

	while ( getline( cin, input ) )
	{
		output = "";

		for ( int i = 0; i < input.length(); i++ )
		{
			output.push_back( getCharOnLeft( input[i] ) );
		}
		
		cout << output << endl;
	}

	return 0;
}

char getCharOnLeft( char c )
{
	for ( int i = 0; i < keyBoard.length(); i++ )
	{
		if ( keyBoard[i] == c )
		{
			if ( c == '\\' )
			{
				return '\'';
			}
			return keyBoard[i-1];
		}
	}

	return ' ';
}
