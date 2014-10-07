#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main( void )
{
    int score = 0;
    int time = 0;
    int maxA = 0;
    int maxB = 0;
    int losePerMinA = 0;
    int losePerMinB = 0;
	bool possible = false;
    
	cin >> score >> time >> maxA >> maxB >> losePerMinA >> losePerMinB;
	
	int tempScore = maxA + maxB;
	
	if ( score == tempScore || score == 0 )
	{
		cout << "YES";

		return 0;
	}

	
	for ( int i = 1; i <= time; i++ )
	{
		if ( !possible )
		{
			for ( int j = 1; j < time; j++ )
			{
				if ( !possible)
				{
					tempScore -= losePerMinB;
					if ( score == tempScore )
					{
						possible = true;
					}
				}
			}
		}
		tempScore = maxA + maxB;
		tempScore -= losePerMinA * i;
		if ( score == tempScore && i != time )
		{
			possible = true;
		}
	}

	if ( possible )
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
    
    return 0;
}