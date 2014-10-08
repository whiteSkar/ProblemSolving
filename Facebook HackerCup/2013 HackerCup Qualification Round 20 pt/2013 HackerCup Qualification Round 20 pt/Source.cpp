#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool square[20][20];

int main()
{
    int numTests = 0;
    int n = 0;
    string input;
    ifstream fileInput ("square_detector.txt");
    ofstream fileOutput;
    fileOutput.open("output.txt");

    fileInput >> numTests;
    
    for (int curTest = 0; curTest < numTests; ++curTest)
    {
        bool isSquare = true;
        int numOfBlack = 0;
        int length = 0;
        pair<int, int> startIndex(-1,-1);
        fileInput >> n;

        for (int i = 0; i < n; ++i)
        {
            fileInput >> input;
            for (int j = 0; j < n; ++j)
            {
                if (input[j] == '#')
                {
                    if (startIndex.first == -1)
                        startIndex = pair<int, int>(i, j);
                    square[i][j] = true;
                    numOfBlack++;
                }
                else
                {
                    square[i][j] = false;
                }
            }
        }

        for (int j = startIndex.second; j < n; ++j)
        {
            if (!square[startIndex.first][j])
                break;
            length++;
        }

        if (length * length != numOfBlack)
            isSquare = false;

        for (int i = startIndex.first; i < length + startIndex.first; ++i)
            for (int j = startIndex.second; j < length + startIndex.second; ++j)
                if (!square[i][j])
                    isSquare = false;

        fileOutput << "Case #" << curTest + 1 << ": " << (isSquare ? "YES" : "NO") << endl;
    }

    fileOutput.close();
    return 0;
}