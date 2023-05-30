/* Write a program to count the number of vowels and consonants in a character array, using
pointers. */

#include <iostream>
using namespace std;

int main()
{
	int vowels = 0, consonants = 0;
	char *str = new char[100];
	cout << "Enter a word or sentence to calculate: ";
	cin.getline(str, 100);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
						str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
						str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
						str[i] == 'U')
			vowels++;
		else if ((str[i] >= 'a' && str[i] <= 'z') ||
						(str[i] >= 'A' && str[i] <= 'Z'))
			consonants++;
	}
	cout << "The word/sentence has " << vowels << " vowels and " << consonants << " consonants." << endl;
	delete[] str;
	return 0;
}