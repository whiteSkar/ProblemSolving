#include <iostream>
#include <string>

//using namespace std;

bool isStringCharsUnique(string str)
{
	int length = str.length();
	bool charMap[256];

	for (int i = 0; i < 256; ++i)
		charMap[i] = false;

	for (int i = 0; i < length; ++i)
	{
		if (charMap[str[i]])
			return false;
		charMap[str[i]] = true;
	}

	return true;
}

void reverseString(char* str)
{
	if (!str) throw exception();

	int right = strlen(str) - 1;
	int left = 0;
	
	while (left < right)
	{
		char temp = str[right];
		str[right--] = str[left];
		str[left++] = temp;
	}
}

void removeDuplicatesNaive(char* str)
{
	if (!str) throw exception();

	char* it = str;
	char* curPos = str;

	while (*it != '\0')
	{
		bool isDup = false;
		for (char* j = str; j < it; ++j)
		{
			if (*j == *it)
			{
				++it;
				isDup = true;
				break;
			}
		}
		if (isDup)
			continue;
		*curPos++ = *it++;
	}
	*curPos = '\0';
}

void removeDuplicateEfficient(char* str)
{
	if (!str) throw exception();

	bool charMap[256];

	for (int i = 0; i < 256; ++i)
		charMap[i] = false;

	char* curPos = str;
	
	while (*str != '\0')
	{
		if (charMap[*str])
			++str;
		else
		{
			charMap[*str] = true;
			*curPos++ = *str++;
		}
	}
	*curPos = '\0';
}

bool isAnagram(string str1, string str2)
{
	int length1 = str1.length();
	int length2 = str2.length();

	if (length1 != length2)
		return false;

	int charMap[256];
	for (int i = 0; i < 256; ++i)
		charMap[i] = 0;

	for (int i = 0; i < length1; ++i)
	{
		charMap[str1[i]]++;
		charMap[str2[i]]--;
	}

	for (int i = 0; i < 256; ++i)
	{
		if (charMap[i] != 0)
			return false;
	}
	
	return true;
}

string replaceSpace(string str)
{
	int length = 0;
	int spaceCount = 0;
	char* cPtr = &str[0];

	while (*cPtr != '\0')
	{
		if (*cPtr++ == ' ')
			spaceCount++;
		length++;
	}

	int newLength = length + 2*spaceCount;
	char* newStr = (char*)malloc((newLength + 1) * sizeof(char));
	if (!newStr) throw exception();

	char* curPos = newStr;

	for (int i = 0; i < length; ++i)
	{
		if (str[i] != ' ')
		{
			*curPos++ = str[i];
		}
		else
		{
			*curPos++ = '%';
			*curPos++ = '2';
			*curPos++ = '0';
		}
	}
	*curPos = '\0';

	string result = string(newStr);
	free(newStr);
	return result;
}

void rotateImageRight(int** image, int n)
{
	if (!image || !*image || n < 0) throw exception();

	for (int i = 0; i < (n + 1)/2; ++i)
	{
		for (int j = i; j < n - 1 - i; ++j)
		{
			int firstElem = image[i][j];
			int curI = i;
			int curJ = j;

			for (int k = 0; k < 3; ++k)
			{
				int oldI = n - 1 - curJ;
				int oldJ = curI;
				image[curI][curJ] = image[oldI][oldJ];
				curI = oldI;
				curJ = oldJ;
			}
			image[curI][curJ] = firstElem;
		}
	}
}

void displayImage(int** image, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << image[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void displayMatrix(int** matrix, int row, int col)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
	

void setToZero(int** matrix, int m, int n)
{
	if (!matrix || !*matrix || m <= 0 || n <= 0) throw exception();

	bool* mMap = (bool*)malloc(m * sizeof(bool));
	if (!mMap) throw exception();
	bool* nMap = (bool*)malloc(n * sizeof(bool));
	if (!nMap) throw exception();

	for (int i = 0; i < m; ++i)
		mMap[i] = false;
	for (int i = 0; i < n; ++i)
		nMap[i] = false;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] == 0)
			{
				mMap[i] = true;
				nMap[j] = true;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (mMap[i] || nMap[j])
				matrix[i][j] = 0;
		}
	}

	free(mMap);
	free(nMap);
}

bool isSubstring(string str1, string str2)
{
	return str1.find(str2) != string::npos;
}

bool isRotation(string str1, string str2)
{
	int length1 = str1.length();
	int length2 = str2.length();
	if (length1 <= 0 || length2 <= 0)  throw exception();

	if (length1 != length2)
		return false;

	string rotationCompareString = str1 + str1.substr(0, length1 - 1);	// str1 + str1

	return isSubstring(rotationCompareString, str2);
}


int main()
{
	string str1 = "abcABC";
	cout << "is " << str1 << " unique? " << (isStringCharsUnique(str1) ? "Yes" : "No") << endl;

	string str2 = "abcde";
	char* str2Ptr = (char*)malloc(str2.length()+1);
	strcpy(str2Ptr, str2.c_str());
	reverseString(str2Ptr);
	cout << "Before reverse: " << str2 << " After reverse: " << str2Ptr << endl;
	free(str2Ptr);

	string string3 = "aabcdeeeeefgaadefa";
	char* str3 = (char*)malloc(string3.length()+1);
	strcpy(str3, string3.c_str());
	cout << "Before removeDuplicateEfficient: " << str3;
	removeDuplicateEfficient(str3);
	cout << " After removeDuplicateEfficient: " << str3 << endl;
	free(str3);

	string ana1 = "anagram";
	string ana2 = "rnmgaaa";
	cout << "is " << ana1 <<" and " << ana2 << " anagram? " << (isAnagram(ana1, ana2) ? "Yes" : "No") << endl;

	string str4 = "yoho he hehe    ehhh ";
	string replacedString = replaceSpace(str4);
	cout << "Space in " << str4 << " is replaced: " << replacedString << endl;

	const int n = 9;
	int **imagePP = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		imagePP[i] = new int[n];
	}
	for (int i = 0;i < n; ++i)
		for (int j = 0; j < n; ++j)
			imagePP[i][j] = i*n + j + 10;
	displayImage(imagePP, n);

	rotateImageRight(imagePP, n);
	displayImage(imagePP, n);

	int row = 3;
	int col = 5;
	int **matrix = new int*[row];
	for (int i = 0; i < row; ++i)
		matrix[i] = new int[col];
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			if ((i != 0 || j != 0) && (i*col + j+1) % 1 == 0)
				matrix[i][j] = 0;
			else
				matrix[i][j] = i*col + j+1;
	displayMatrix(matrix, row, col);

	setToZero(matrix, row, col);
	displayMatrix(matrix, row, col);

	string str5 = "waterbottle";
	string str6 = "bottlewater";
	cout << "is " << str6 << " rotation of " << str5 << "? " << (isRotation(str5, str6) ? "Yes" : "No") << endl;

	char c;
	cin >> c;
	return 0;
}