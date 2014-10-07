#include <iostream>

using namespace std;

void rotateImage( int image[], int n );
void rotateImageInPlace( int image[], int n );

int main()
{
	int image1[3][3] = { 1,2,3,4,5,6,7,8,9 };

	rotateImage( image1[0], 3 );
	rotateImageInPlace( image1[0], 3 );
	
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			cout << image1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	rotateImage( image1[0], 3 );
	rotateImageInPlace( image1[0], 3 );
	
	for ( int i = 0; i < 3; i++ )
	{
		for ( int j = 0; j < 3; j++ )
		{
			cout << image1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int image2[2][2] = { 1,2,3,4 };

	rotateImage( image2[0], 2 );
	rotateImageInPlace( image2[0], 2 );
	
	for ( int i = 0; i < 2; i++ )
	{
		for ( int j = 0; j < 2; j++ )
		{
			cout << image2[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	int image3[1][1] = { 1 };

	rotateImage( image3[0], 1 );
	rotateImageInPlace( image3[0], 1 );
	
	for ( int i = 0; i < 1; i++ )
	{
		for ( int j = 0; j < 1; j++ )
		{
			cout << image3[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void rotateImage( int image[], int n )
{
	int **buffer;
	
	buffer = new int*[n];

	for ( int i = 0; i < n; i++ )
	{
		buffer[i] = new int[n];
	}

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			buffer[j][n-1-i] = image[i*n + j];
		}
	}

	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < n; j++ )
		{
			image[i*n + j] = buffer[i][j];
		}
	}

	for ( int i = 0; i < n; i++ )
	{
		delete[] buffer[i];
	}
	delete[] buffer;
}

void rotateImageInPlace( int image[], int n )
{
	int x, y, temp1;
	int temp2;

	for ( int i = 0; i < n/2; i++ )
	{

		for ( int j = i; j < n-1-i; j++ )
		{
			x = i;
			y = j;

			for ( int k = 0; k < 3; k++ )
			{
				temp2 = image[y*n + (n-1-x)];
				image[y*n + (n-1-x)] = image[i*n + j];
				image[i*n + j] = temp2;
				
				temp1 = y;
				y = n-1-x;
				x = temp1;
			}
		}
	}
}