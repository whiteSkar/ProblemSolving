#include <iostream>

using namespace std;

void setZero( int matrix[], int m, int n );
void setZeroOptimizedSpace( int matrix[], int m, int n );

int main()
{
	int matrix1[3][3] = { 1,1,1,1,1,1,1,1,1 };

	setZeroOptimizedSpace( matrix1[0], 3, 3 );
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
			cout << matrix1[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix2[4][3] = { 1,1,1,1,1,1,1,1,1,0,1,1 };

	setZeroOptimizedSpace( matrix2[0], 4, 3 );
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 3; j++ )
			cout << matrix2[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix3[1][10] = { 1,1,1,1,1,0,1,1,1,1 };

	setZeroOptimizedSpace( matrix3[0], 1, 10 );
	for ( int i = 0; i < 1; i++ )
	{
		for ( int j = 0; j < 10; j++ )
			cout << matrix3[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix4[3][5] = { 0,1,1,1,0,1,1,1,1,1,1,1,0,1,1 };

	setZeroOptimizedSpace( matrix4[0], 3, 5 );
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 5; j++ )
			cout << matrix4[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix5[4][4] = { 0,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0 };

	setZeroOptimizedSpace( matrix5[0], 4, 4 );
	for ( int i = 0; i < 4; i++ )
	{
		for ( int j = 0; j < 4; j++ )
			cout << matrix5[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix6[1][1] = { 1 };

	setZeroOptimizedSpace( matrix6[0], 1, 1 );
	for ( int i = 0; i < 1; i++ )
	{
		for ( int j = 0; j < 1; j++ )
			cout << matrix6[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	int matrix7[1][1] = { 0 };

	setZeroOptimizedSpace( matrix7[0], 1, 1 );
	for ( int i = 0; i < 1; i++ )
	{
		for ( int j = 0; j < 1; j++ )
			cout << matrix7[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}

void setZero( int matrix[], int m, int n )
{
	bool** zero;
	zero = new bool*[m];

	for ( int i = 0; i < m; i++ )
	{
		zero[i] = new bool[n];

		for ( int j = 0; j < n; j++ )
			zero[i][j] = false;
	}

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
			if ( matrix[i*n + j] == 0 )
				zero[i][j] = true;

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
			if ( zero[i][j] )
			{
				for ( int k = 0; k < m; k++ )
					matrix[k*n + j] = 0;

				for ( int k = 0; k < n; k++ )
					matrix[i*n + k] = 0;
			}
	
	for ( int i = 0; i < m; i++ )
		delete[] zero[i];
	delete[] zero;
}

void setZeroOptimizedSpace( int matrix[], int m, int n )
{
	bool* row = new bool[m];
	bool* col = new bool[n];

	for ( int i = 0; i < m; i++ )
		row[i] = false;

	for ( int i = 0; i < n; i++ )
		col[i] = false;

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
			if ( matrix[i*n + j] == 0 )
			{
				row[i] = true;
				col[j] = true;
			}

	for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; j++ )
			if ( row[i] || col[j] )
				matrix[i*n + j] = 0;

	delete[] row;
	delete[] col;
}