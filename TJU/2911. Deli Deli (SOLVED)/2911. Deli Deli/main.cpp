#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, string> irrList;
map<string, string>::iterator it;

int main()
{
	int numP;
	int numCase;
	string input1;
	string input2;

	cin >> numP >> numCase;

	for ( int i = 0; i < numP; i++ )
	{
		cin >> input1 >> input2;
		irrList.insert( pair<string, string>( input1, input2 ) );
	}
	
	for ( int i = 0; i < numCase; i++ )
	{
		cin >> input1;

		it = irrList.find( input1 );

		if ( it != irrList.end() )
		{
			cout << it->second << endl;
		}
		else
		{
			if ( input1.at( input1.length()-1 ) == 'y' && ( input1.at( input1.length()-2 ) != 'a' &&
															input1.at( input1.length()-2 ) != 'e' &&
															input1.at( input1.length()-2 ) != 'i' &&
															input1.at( input1.length()-2 ) != 'o' &&
															input1.at( input1.length()-2 ) != 'u' ) )
			{
				input1.resize( input1.length()-1 );
				cout << input1 << "ies" << endl;
			}
			else if ( input1.at( input1.length()-1 ) == 'o' ||
						input1.at( input1.length()-1 ) == 's' ||
						input1.at( input1.length()-1 ) == 'x' ||
						( input1.at( input1.length()-2 ) == 'c' && input1.at( input1.length()-1 ) == 'h' ) ||
						( input1.at( input1.length()-2 ) == 's' && input1.at( input1.length()-1 ) == 'h' ) )
			{
				cout << input1 << "es" << endl;
			}
			else
			{
				cout << input1 << 's' << endl;
			}
		}
	}
	return 0;
}