#include <iostream>
#include <string>

using namespace std;

bool isRotation( string str1, string str2 );

int main()
{
	if ( isRotation( "apple", "pleap" ) )
		cout << "Passed 1" << endl;

	if ( !isRotation( "apple", "ppale" ) )
		cout << "Passed 2" << endl;

	if ( isRotation( "abaa", "aaba" ) )
		cout << "Passed 3" << endl;

	if ( isRotation( "abcdefg", "gabcdef" ) )
		cout << "Passed 4" << endl;

	if ( isRotation( "abc", "cab" ) )
		cout << "Passed 5" << endl;

	if ( isRotation( "a", "a" ) )
		cout << "Passed 6" << endl;

	if ( !isRotation( "a", "ab" ) )
		cout << "Passed 7" << endl;

	if ( !isRotation( "a", "b" ) )
		cout << "Passed 8" << endl;

	if ( !isRotation( "", "" ) )
		cout << "Passed 9" << endl;

	return 0;
}

bool isRotation( string str1, string str2 )
{
	if ( str1.length() != str2.length() || str1.length() == 0 )
		return false;

	string temp( str1 );
	
	temp.append( str1, 0, str1.length()-1 );

	if ( temp.find( str2 ) != string::npos )
		return true;

	return false;
}