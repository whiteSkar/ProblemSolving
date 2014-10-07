#include <stdio.h>
#include <stdlib.h>


int main( void )
{
	bool first = true;
	int numTest = 0;
	int number = 1;
	int i;
	bool endOfLine = false;

	char c = 0;
	int min;
	int numAlphabet[8];

	FILE* fp;
	FILE* fpp;
	fp = fopen( "alphabet_soup.txt", "r" );
	fpp = fopen ( "output.txt", "w" );

	if ( fp == NULL )
	{
		puts ( "Cannot open file.\n" );
		return 0;
	}

	fscanf( fp, "%d", &numTest);

	while ( numTest > 0 )
	{
		for ( i = 0; i < 8; i ++ )
		{
			numAlphabet[i] = 0;
		}

		endOfLine = false;
		while ( !endOfLine && !feof( fp ) )
		{
			switch( fgetc( fp ) )
			{
				case 65:
					numAlphabet[0]++;
					break;

				case 67:
					numAlphabet[1]++;
					break;

				case 69:
					numAlphabet[2]++;
					break;

				case 72:
					numAlphabet[3]++;
					break;

				case 75:
					numAlphabet[4]++;
					break;

				case 80:
					numAlphabet[5]++;
					break;

				case 82:
					numAlphabet[6]++;
					break;

				case 85:
					numAlphabet[7]++;
					break;

				case 10:
					endOfLine = true;
					break;				

				default:
					;
			}
		}

		for ( i = 2; i < 8; i++ )
		{
			min = numAlphabet[0];
			if ( numAlphabet[i] < min )
			{
				min = numAlphabet[i];
			}
			if ( numAlphabet[1] < (min * 2) )
			{
				min = (numAlphabet[1] / 2);
			}
		}

		if ( !first )
		{
			if ( numTest == 1 )
			{
				fprintf( fpp, "Case #%d: %d", number, min );
				number++;
				numTest--;
			}
			else
			{
				fprintf( fpp, "Case #%d: %d\n", number, min );
				number++;
				numTest--;
			}
		}
		else
		{
			first = false;
		}
	}

	fclose( fp );
	fclose( fpp );
	return 0;
}

