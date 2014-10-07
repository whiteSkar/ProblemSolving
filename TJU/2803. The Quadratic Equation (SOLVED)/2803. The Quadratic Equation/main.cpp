#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

long double getDiscriminant( long double a, long double b, long double c );

int main()
{
	int numCase;
	long double a, b, c;
	long double result;

	cin >> numCase;

	for ( int i = 0; i < numCase; i++ )
	{
		cin >> a >> b >> c;

		result = getDiscriminant( a, b, c );

		cout << fixed;

		if ( result > 0 )
		{
			long double result2 = result;
			result = ( (-b) + result ) / ( 2 * a );
			result2 = ( (-b) - result2 ) / ( 2 * a );

			if ( result <= result2 )
			{
				cout << setprecision(3) << result << " ";
				cout << setprecision(3) << result2 << endl;
			}
			else
			{
				cout << setprecision(3) << result2 << " ";
				cout << setprecision(3) << result << endl;
			}
		}
		else if ( result == 0 )
		{
			result = ( (-b) + result ) / (2*a);
			cout << setprecision(3) << result << endl;
		}
		else
		{
			cout << "No solution!" << endl;
		}
	}
	return 0;
}

long double getDiscriminant( long double a, long double b, long double c )
{
	long double result = 0;

	result = ( b * b ) - ( 4.0 * a * c );

	if ( result >= 0 )
	{
		return sqrt( result );
	}
	else
	{
		return -1;
	}
}