#include <stdio.h>
#include <math.h>

int main( void )
{
	int input = 0;
	int count;
	int numTest = 0;
	double result = 0;
	double i;
	int j;

	FILE* fp;
	FILE* fpp;
	fpp = fopen ( "output.txt", "w" );
	fp = fopen( "double_squares.txt", "r" );

	if ( fp == NULL )
	{
		puts ( "Cannot open file.\n" );
		return 0;
	}

	fscanf( fp, "%d", &numTest);
	fprintf( fpp, "%d\n", numTest ); //

	while ( numTest > 0 )
	{
		count = 0;
		fscanf( fp, "%d", &input );

		i = sqrt( (double)input );
		j = (int) i;

		if ( i - j == 0 )
		{
			count++;
			j--;
		}

		for ( ; j >= 0; j-- )
		{
			result = input - (j * j);
			result = sqrt( (double) result );
			if ( result - (int)result == 0 )
			{
				count ++;
			}

		}

		if ( count != 1 )
		{
			count /= 2;
		}
		fprintf( fpp, "%d\n", count );

		numTest--;
	}
	fclose( fp );
	return 0;
}

