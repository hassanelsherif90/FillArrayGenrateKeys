#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
enum enKeyType{Samall = 1, Capital = 2, SpcialCharcter = 3, Digit};
int ReadPositiveNumber(string Message)
{
	int Number = 0;
	do {
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}

int RandomNumber(int From, int To) {

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

char CheckType(enKeyType Type)
{
	switch (Type) {
	case enKeyType::Capital:
		return char(RandomNumber(65, 90));
		break;
	case enKeyType::Samall:
		return char(RandomNumber(97, 122));
		break;
	case enKeyType::SpcialCharcter:
		return char(RandomNumber(33, 47));
		break;
	case enKeyType::Digit:
		return char(RandomNumber(48, 57));
		break;
	}
	return Type;
}

string GenrateWord(enKeyType CharType, int length)
{
	string word = "";
	for (int i = 0; i < length; i++)
	{
		word = word + CheckType(CharType);
	}
	return word;
}

string GenrateKey()
{
	string Key = "";
	Key = Key + GenrateWord(enKeyType::Capital, 4) + "-";
	Key = Key + GenrateWord(enKeyType::Capital, 4) + "-";
	Key = Key + GenrateWord(enKeyType::Capital, 4) + "-";
	Key = Key + GenrateWord(enKeyType::Capital, 4);

	return Key;
}


void GenrateKeys(int Length) {

	for (int i = 1; i <= Length; i++)
	{
		cout << GenrateKey() << endl;
	}

}

void FillArray(string arr[100], int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = GenrateKey();
	}
}

void PrintArray(string arr[100], int arrLength) {

	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array [" << i << "] : " << arr[i]
			<< endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	int arrLength;
	arrLength = ReadPositiveNumber("");
	FillArray(arr, arrLength);
	PrintArray(arr, arrLength);
	//GenrateKeys(ReadPositiveNumber(" "));
	return 0;
}