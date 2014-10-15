#include <stdio.h>
#include <stdlib.h>

int getCycle(int input, int cycle);
int getLongestCycle(int input1, int input2);

void main(void)
{
	int input1, input2, temp;
	int num1, num2;
	
	while (scanf("%d%d", &input1, &input2) == 2)
	{
		if (input1 > input2)
		{
			num1 = input2;
			num2 = input1;
		}
		else
		{
			num1 = input1;
			num2 = input2;
		}

		printf("%d %d %d\n", input1, input2, getLongestCycle(num1, num2));
	}

	return;
}

int getCycle(int input, int cycle)
{
	if ( input != 1 )
	{
		if ( input%2 == 0 )
		{
			input /= 2;
		}
		else
		{
			input = input*3 +1;
		}
		cycle++;
		cycle = getCycle(input, cycle);
	}

	return cycle;
}

int getLongestCycle(int input1, int input2)
{
	int i;
	int tempCycle = 0;
	int longestCycle = 0;

	longestCycle = getCycle(input1,1);
	for (i = input1+1; i <= input2; i++)
	{
		tempCycle = getCycle(i,1);
		if (tempCycle > longestCycle)
		{
			longestCycle = tempCycle;
		}
	}
	return longestCycle;
}
