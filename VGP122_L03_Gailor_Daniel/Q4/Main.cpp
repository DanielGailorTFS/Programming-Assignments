/* Write a program that inputs a series of integers and passes them one at a time to
function isEven, which uses the modulus operator to determine whether an integer
is even. The function should take an integer argument and return true if the integer
is even and false otherwise. */

#include <iostream>
using namespace std;

bool isEven(int number) {

	if (number % 2 == 0) {
		return true;
	}
	return false;
}

int main() {

	int number[20];
	int calcMax = 10;
	int calcNum = 0;
	string evenOdd;
	bool calculate = false;


	cout << "How many numbers do you wish to calculate?" << endl;
	cin >> calcMax;

	while (calcNum < calcMax) {
		for (int i = 0; calcNum < calcMax; i++) {
			cout << "Please enter the number for calculation " << calcNum+1 << " out of " << calcMax << ": " << endl;
			cin >> number[i];
			calcNum++;
		}


		if (calcNum >= calcMax) {
			calculate = true;
			calcNum = 0;
		
		}
	cout << "Below are the numbers and their odd or even status: " << endl;

	cout << "Number       Odd/Even" << endl;
	calcNum = 0;

	while (calculate == true && calcNum < calcMax) {
		for (int i = 0; calcNum < calcMax; i++) {


			if (isEven(number[i]) == true) {
				evenOdd = "Even";
			}
			else {
				evenOdd = "Odd";
			}


			cout << number[i] << "       " << evenOdd << endl;

			calcNum++;
		}
	}
	}

	return 0;

}