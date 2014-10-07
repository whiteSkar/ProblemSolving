#include <stdio.h>

#define MAX_NUM_STUDENT 1000
#define RESULT_OFFSET 0.01

double getAverage(double* inputArray, int sizeOfArray);
double getTotalTransferAmount(double* inputArray, int sizeOfArray, double average);

void main(void)
{
	int i;
	int num_student = 0;
	double average, amount;
	double spentMoney[MAX_NUM_STUDENT];

	while (scanf("%d", &num_student) == 1 && num_student != 0)
	{
		for (i = 0; i < num_student; i++)
		{
			scanf("%lf", &spentMoney[i]);
		}

		average = getAverage(spentMoney, num_student);
		amount = getTotalTransferAmount(spentMoney, num_student, average);
	
		printf("$%.2lf\n", amount);
	}
	return;
}

double getAverage(double* inputArray, int sizeOfArray)
{
	int i;
	double average = 0;

	for (i = 0; i < sizeOfArray; i++)
	{
		average += inputArray[i];
	}
	average /= sizeOfArray;

	return average;
}

double getTotalTransferAmount(double* inputArray, int sizeOfArray, double average)
{
	int i;
	double result = 0;
	
	for (i = 0; i < sizeOfArray; i++)
	{
		if (inputArray[i] >= average)
		{
			result += inputArray[i] - average;
		}
		else
		{
			result += average - inputArray[i];
		}
	}
	result /= 2.0;
	
	if ( (int)(average*1000.0+0.000001) % 10 != 0 )
	{
		result -= RESULT_OFFSET;
	}

	return result;
}