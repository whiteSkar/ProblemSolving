#include <iostream>
#include <string>

using namespace std;

bool isAnagram( string str1, string str2 );

int main()
{
	if ( isAnagram( "", "" ) )
		cout << "Passed1" << endl;

	if ( !isAnagram( "", "a" ) )
		cout << "Passed2" << endl;

	if ( !isAnagram( "a", "" ) )
		cout << "Passed3" << endl;

	if ( !isAnagram( "a", "b" ) )
		cout << "Passed4" << endl;

	if ( isAnagram( "a", "a" ) )
		cout << "Passed5" << endl;

	if ( isAnagram( "ab", "ab" ) )
		cout << "Passed6" << endl;

	if ( isAnagram( "ab", "ba" ) )
		cout << "Passed7" << endl;

	if ( !isAnagram( "abc", "ab" ) )
		cout << "Passed8" << endl;

	if ( isAnagram( "anagram", "nag a ram" ) )
		cout << "Passed9" << endl;

	return 0;
}

bool isAnagram( string str1, string str2 )
{
	int ascii[128];
	int length1 = str1.length();
	int length2 = str2.length();

	for ( int i = 0; i < 128; i++ )
	{
		ascii[i] = 0;
	}

	for ( int i = 0; i < length1; i++ )
	{
		ascii[str1[i]]++;
	}

	for ( int i = 0; i < length2; i++ )
	{
		ascii[str2[i]]--;
	}

	for ( int i = 0; i < 128; i++ )
	{
		if ( i == ' ' )
			continue;

		if ( ascii[i] != 0 )
			return false;
	}

	return true;
}
