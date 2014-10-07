#include <iostream>

using namespace std;

int main()
{
	int input;

	cin >> input;

	int (*intA)[5] = new int[input][5];

	for ( int i = 0; i < input; i++ )
	{
		for ( int j = 0; j < 5; j++ )
		{
			intA[i][j] = i;
			cout << intA[i][j] << " ";
		}
		cout << endl;
	}

	cin >> input;

	return 0;
}