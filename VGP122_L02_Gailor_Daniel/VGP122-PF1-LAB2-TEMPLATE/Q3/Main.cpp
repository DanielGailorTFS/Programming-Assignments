/* Write an application that finds the smallest of several integers. Assume that the
first value read specifies the number of values to input from the user. */
#include <iostream>
using namespace std;

int main() {

	int inputTotal, counter = 1, number, smallestNum = 99999;

	cout << "How many numbers would you like to enter? This program will find the smallest value entered." << endl;
	cin >> inputTotal;


	while (counter < inputTotal) {
		cout << "Enter number " << counter << " of the " << inputTotal << " total." << endl;
		cin >> number;
		counter++;

			if (number < smallestNum) {
				smallestNum = number;
			}


	}

	cout << "The smallest number out of the " << inputTotal << " entered is: " << smallestNum << endl;


	return 0;
}