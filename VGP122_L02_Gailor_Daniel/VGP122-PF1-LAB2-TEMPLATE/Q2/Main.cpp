/* The process of finding the largest number (i.e., the maximum of a group of
numbers) is used frequently in computer applications. For example, a program that
determines the winner of a sales contest inputs the number of units sold by each
salesperson. The salesperson who sells the most units wins the contest. Write a C
++ program that uses a while statement to determine and print the largest of 10
numbers input by the user. Your program should use three variables, as follows:
a. counter—A counter to count to 10 (i.e., to keep track of how many numbers
have been input and to determine when all 10 numbers have been processed).
b. number—The current number input to the program.
c. largest—The largest number found so far. */


#include <iostream>
using namespace std;

int main()
{
	int counter = 1;
	int number;
	int largestNum;

	cout << "Please input 10 numbers. This program will ascertain the one with the highest value." << endl;
	cout << "Number one: " << endl;
	cin >> largestNum;
	


	while (counter < 10) {

		counter++;
		cout << "Input Number " << counter << endl;
		cin >> number;

			if (number > largestNum) {
				largestNum = number;
			}
	}

	cout << "The largest number entered was: " << largestNum << endl;



	return 0;
}