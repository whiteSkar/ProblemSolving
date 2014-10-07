#include <iostream>
#include <string>

using namespace std;

void removeDuplicates( char* str );
void removeDuplicatesWithConstantSizeArray( char* str );

int main()
{
	string input;
	const char* p_input;
	char* pc_input;

	while (1)
	{
		cin >> input;
		p_input = input.c_str();
		pc_input = (char*)malloc( strlen( p_input ) +1 );
		strcpy( pc_input, p_input );
		removeDuplicates( pc_input );
		cout << p_input << endl;
		cout << pc_input << endl;
		removeDuplicatesWithConstantSizeArray( pc_input );
		cout << pc_input << endl;
		delete pc_input;
	}

	return 0;
}

void removeDuplicates( char* str )
{
	int start = 0;
	int end = 0;
	bool found;

	if ( !str )
		return;

	while ( str[end] != '\0' )
	{
		found = false;

		for ( int i = 0; i < start; i++ )
		{
			if ( str[end] == str[i] )
				found = true;
		}
		
		if ( !found )
			str[start++] = str[end];

		end++;
	}

	str[start] = '\0';
}

void removeDuplicatesWithConstantSizeArray( char* str )
{
	bool ascii[128];
	char* start = str;
	char* end = str;

	if ( !str )
		return;

	for ( int i = 0; i < 128; i++ )
	{
		ascii[i] = false;
	}

	while ( *end != '\0' )
	{
		if ( !ascii[*end] )
		{
			*start++ = *end;
			ascii[*end] = true;
		}
		end++;
	}

	*start = '\0';
}

