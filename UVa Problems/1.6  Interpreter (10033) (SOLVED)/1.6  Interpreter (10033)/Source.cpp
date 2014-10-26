#include <math.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int HALT = -1;
const int NO_OUTPUT = 0;

const int RAM_SIZE = 1000;
int ram[RAM_SIZE];

const int REGISTER_COUNT = 10;
int registers[REGISTER_COUNT];

int opCodeProcessor(int opCode)
{
	string opCodeString = to_string(opCode);
	if (opCodeString.length() <= 2)
		opCodeString = "0" + opCodeString;
	if (opCodeString.length() <= 1)
		opCodeString = "0" + opCodeString;

	int type = opCodeString[0] - '0';
	int firstOperand = opCodeString[1] - '0';
	int secondOperand = opCodeString[2] - '0';

	switch (type)
	{
	case 0:
		if (registers[secondOperand] != 0)
			return registers[firstOperand];
		break;
	case 1:
		return HALT;
	case 2:
		registers[firstOperand] = secondOperand;
		break;
	case 3:
		registers[firstOperand] = (registers[firstOperand] + secondOperand) % RAM_SIZE;
		break;
	case 4:
		registers[firstOperand] = (registers[firstOperand] * secondOperand) % RAM_SIZE;
		break;
	case 5:
		registers[firstOperand] = registers[secondOperand];
		break;
	case 6:
		registers[firstOperand] = (registers[firstOperand] + registers[secondOperand]) % RAM_SIZE;
		break;
	case 7:
		registers[firstOperand] = (registers[firstOperand] * registers[secondOperand]) % RAM_SIZE;
		break;
	case 8:
		registers[firstOperand] = ram[registers[secondOperand]];
		break;
	case 9:
		ram[registers[secondOperand]] = registers[firstOperand];
		break;
	default:
		break;
	}

	return NO_OUTPUT;
};

int main()
{
	//ifstream inputFile("input.txt");	// change to cin
	//ofstream outputFile("output.txt");

	string input;
	getline(cin, input);

	int numTest = atoi(input.c_str());

	getline(cin, input);	// first blank line

	for (int k = 1; k <= numTest; k++)
	{
		memset(ram, 0, RAM_SIZE * sizeof(int));
		memset(registers, 0, REGISTER_COUNT * sizeof(int));

		int count = 0;
		while (getline(cin, input))
		{
			if (input.empty())
				break;

			ram[count++] = atoi(input.c_str());
		}

		int curAddress = 0;
		int instructionCount = 0;
		while (true)
		{
			int output = opCodeProcessor(ram[curAddress]);
			instructionCount++;
			if (output == HALT)
				break;
			else if (output == NO_OUTPUT)
				curAddress++;
			else
				curAddress = output;
		}

		cout << instructionCount << endl;
		if (k < numTest)
			cout << endl;
	}

	//inputFile.close();
	//outputFile.close();

	return 0;
}