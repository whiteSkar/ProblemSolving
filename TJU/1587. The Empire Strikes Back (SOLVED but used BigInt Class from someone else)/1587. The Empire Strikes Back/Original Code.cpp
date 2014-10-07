#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, unsigned long long> preList;
map<pair<int, int>, unsigned long long>::iterator it;

int input;				

unsigned long long getRoutes( int width, int height );

int main()
{
	unsigned long long output;

	while ( cin >> input )
	{
		if ( input == 0 )
		{
			return 0;
		}

		output = getRoutes( input, input );
		output *= 2;
		cout << output << endl;
	}

	return 0;
}

unsigned long long getRoutes( int width, int height )
{
	unsigned long long result = 0;
	int widthOri = width;
	int heightOri = height;

	if ( width == 1 && height <= 1)
	{
		return 1;
	}

	it = preList.find( make_pair( width, height ) );
	if ( it != preList.end() )
	{
		return it->second;
	}

	if ( width == height )
	{
		height--;
	}
	width--;

	for ( int i = height; i >= 0; i-- )
	{
		result += getRoutes( width, i );
	}

	preList.insert( make_pair( make_pair( widthOri, heightOri ), result ));

	return result;
}

