#include <stdio.h>

void inspectAround(int x, int y, char (*board)[102], char (*result)[101]);

void main(void)
{
	int row, column, i, j;
	int round = 1;
	char c;
	char mineBoard[102][102];
	char mineResult[101][101];

	while (scanf("%d %d", &row, &column) == 2 && row != 0 && column != 0)
	{
		for ( i = 0; i < 102; i++ )
		{
			for ( j = 0; j < 102; j++ )
			{
				mineBoard[i][j] = '.';
			}
		}

		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= column; j++)
			{
				c = getchar();
				if (c != '\n')
				{
					mineBoard[i][j] = c;
				}
				else
				{
					j--;
				}
			}
		}

		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= column; j++)
			{
				if (mineBoard[i][j] == '*')
				{
					mineResult[i][j] = '*';
				}
				else
				{
					inspectAround(i, j, mineBoard, mineResult);
				}
			}
		}

		if (round > 1 )
		{
			printf("\n");
		}
		printf("Field #%d:\n", round);
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= column; j++)
			{
				if (mineResult[i][j] == '*')
				{
					printf("%c", mineResult[i][j]);
				}
				else
				{
					printf("%d", mineResult[i][j]);
				}
			}
			printf("\n");
		}
		round++;
	}
	return;
}

void inspectAround(int x, int y, char (*board)[102], char (*result)[101])
{
	int i, j;
	char count = 0;

	for (i = x-1; i <= x+1; i++)
	{
		for (j = y-1; j <= y+1; j++)
		{
			if (board[i][j] == '*')
			{
				count++;
			}
		}
	}
	result[x][y] = count;	
}