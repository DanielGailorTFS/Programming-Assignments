/* Use a one-dimensional array to solve the following problem. Read in 20 numbers,
each of which is between 10 and 100, inclusive. As each number is read, validate it
and store it in the array only if it isn’t a duplicate of a number already read. After
reading all the values, display only the unique values that the user entered. Provide
for the “worst case” in which all 20 numbers are different. Use the smallest
possible array to solve this problem. */

#include <iostream>
using namespace std;

int main() {

	int arrayNumbers[20] = { 0 };
	int arraySize = 1;
	int dupeCount = 0;
	int counter = 20;

	while (counter > 0) {
		int number;
		cout << "Please enter a number between 10 and 100 with as few duplicates as possible. You have " << counter << " attempts left." << endl;
		cin >> number;

		if (number >= 10 && number <= 100) {
			bool duplicate = false;

			for (int i = 0; i < arraySize; i++) {
			
				if (number == arrayNumbers[i]) {
					duplicate = true;
					break;
				
				}
			
			}
			if (duplicate) {
				cout << "Oops! That's a duplicate! Focus!" << endl;	
				dupeCount += 1;
				counter--;
			}
			else {
				arrayNumbers[arraySize] = number;
				arraySize += 1;
				counter--;
			}
		}
		else {
			cout << "Invalid number. The number must be between 10 and 100!" << endl;
		}
	}

	cout << "Here is the list of original numbers: " << endl;
	
	for (int i = 1; i < arraySize; i++) {
		if (i == 1) {
			cout << arrayNumbers[1];
		}
		else {
			cout << " " << arrayNumbers[i];
		}
	}
	cout << ". " << endl;
	cout << "Number of duplicates entered: " << dupeCount << endl;
	
	return 0;
}