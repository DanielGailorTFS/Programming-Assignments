/* Factorials are used frequently in probability problems. The factorial of a
positive integer n (written n! and pronounced “n factorial”) is equal to the product
of the positive integers from 1 to n. Write an application that calculates the
factorials of 1 through 20. Use type long. Display the results in tabular format. */

#include <iostream>
using namespace std;

int main(){

	int totalNum, factorial = 1, counter = 1;

	cout << "Enter a number no higher than 20 to calculate: " << endl;
	cin >> totalNum;

	while (counter <= totalNum) {
		factorial *= counter;
		counter++;
		cout << factorial << endl;
	
	}
	cout << "The factorial of " << totalNum << " is " << factorial << endl;

	return 0;
}