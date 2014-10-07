#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int numTestCase = 0;
	int numElements = 0;
	long long result = 0;
	long long vect1[800];
	long long vect2[800];

	cin >> numTestCase;
	for ( int i = 0; i < numTestCase; i++ )
	{
		cin >> numElements;
		for ( int k = 0; k < numElements; k++ )
		{
			cin >> vect1[k];
		}
		
		for ( int k = 0; k < numElements; k++ )
		{
			cin >> vect2[k];
		}

		sort( vect1, vect1+numElements );
		sort( vect2, vect2+numElements );

		for ( int k = 0; k < numElements; k++ )
		{
			result += vect1[k] * vect2[numElements-1-k];
		}

		cout << "Case #" << i+1 << ": " << result << endl;

		numElements = 0;
		result = 0;
	}

	return 0;
}