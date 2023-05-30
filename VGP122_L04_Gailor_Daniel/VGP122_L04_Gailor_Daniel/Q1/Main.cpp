/* Write a program to find the max value of an integer array data set. The program will ask the user
to input the number of data values in the set and each value. The program prints on screen a
pointer that points to the max value. */

#include <iostream>
using namespace std;

int main()
{
	int n;
	int	*max = new int;
	cout << "Enter the quantity of numbers in the set: ";
	cin >> n;
	int *data = new int[n];
	cout << "Please enter the numbers: ";
	for (int i = 0; i < n; i++)
		cin >> data[i];
	for (int i = 1; i < n; i++)
		if (data[i] > *max)
			max = &data[i];
	cout << "The max value is " << *max << endl;
	delete[] data;
	return 0;
}