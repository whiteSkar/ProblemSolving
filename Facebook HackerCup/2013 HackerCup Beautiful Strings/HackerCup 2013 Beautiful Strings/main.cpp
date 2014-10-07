#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


void clearData();


int data[26];


int main(void)
{
	string inputString;
	int numTest;
	int score;
	int totalScore;
	ifstream myFile;
	ofstream outFile( "output.txt" );
	myFile.open( "beautiful_stringstxt.txt" );
	
	getline( myFile, inputString );
	numTest = atoi( inputString.c_str() );
	
	for ( int testCase = 1; testCase <= numTest; testCase++ )
	{
		clearData();
		score = 26;
		totalScore = 0;

		getline( myFile, inputString );
		
		for ( int i = 0; i < inputString.length(); i++ )
		{
			if ( isalpha( inputString[i] ) )
			{
				data[tolower( inputString[i] ) - 97]++;
			}
		}

		vector<int> dataVector( data, data+26 );
		sort( dataVector.begin(), dataVector.end() );
		reverse( dataVector.begin(), dataVector.end() );

		if ( testCase != 1 )
		{
			cout << endl;
			outFile << endl;
		}

		for ( vector<int>::iterator it = dataVector.begin(); it != dataVector.end(); it++ )
		{
			totalScore += ( *it * score-- );
		}
		cout << "Case #" << testCase << ": " << totalScore;
		outFile << "Case #" << testCase << ": " << totalScore;
	}

	myFile.close();
	outFile.close();

	cin >> inputString;

	return 0;
}


void clearData()
{
	for ( int i = 0; i < 26; i++ )
	{
		data[i] = 0;
	}
}