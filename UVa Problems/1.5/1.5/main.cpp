#include <iostream>

using namespace std;

void replaceSpace( char* str );

int main()
{
	char* str = (char*)malloc(30);

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = 'a';
	str[1] = ' ';
	str[2] = 'c';
	str[3] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = 'a';
	str[1] = 'b';
	str[2] = ' ';
	str[3] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = ' ';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = ' ';
	str[1] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = ' ';
	str[1] = ' ';
	str[2] = ' ';
	str[3] = '\0';
	replaceSpace( str );
	cout << str << endl;

	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = ' ';
	str[4] = 'e';
	str[5] = 'f';
	str[6] = ' ';
	str[7] = ' ';
	str[8] = 'i';
	str[9] = '\0';
	replaceSpace( str );
	cout << str << endl;

	delete str;
	return 0;
}

void replaceSpace( char* str )
{
	int length = strlen( str );
	int countSpace = 0;
	int newLength;

	for ( int i = 0; i < length; i++ )
	{
		if ( str[i] == ' ' )
			countSpace++;
	}
	
	newLength = length + countSpace*2;
	str[newLength--] = '\0';
	length--;

	while ( newLength >= 0 )
	{
		if ( str[length] == ' ' )
		{
			str[newLength--] = '0';
			str[newLength--] = '2';
			str[newLength--] = '%';
			length--;
		}
		else
		{
			str[newLength--] = str[length--];
		}
	}
}