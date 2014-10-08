#include <iostream>
#include <string>

using namespace std;

bool isLittleEndian()
{
    short int one = 1;
    char* charPtr = (char*) &one;

    return (*charPtr);
}

int countOneBits(int value) // unsigned
{
    int one = 1;
    int count = 0;
    unsigned int uValue = (unsigned int) value;

    while (uValue != 0)
    {
        int result = uValue & one;
        if (result == 1)
            count++;
        uValue = uValue >> 1;
    }

    return count;
}

int main()
{
    cout << "Is little endina? " << (isLittleEndian() ? "Yes" : "No") << endl;
    
    int num = 256;
    cout << "Number of bit one in " << num << " is: " << countOneBits(num) << endl;

    char c;
    cin >> c;
    return 0;
}