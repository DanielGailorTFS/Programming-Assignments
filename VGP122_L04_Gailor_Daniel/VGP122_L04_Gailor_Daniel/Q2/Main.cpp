/* Write a program to find the factorial of a given number using pointers. */

#include <iostream>
using namespace std;

int main()
{
	long long n;
	long long *factorial = new long long;
	*factorial = 1;
	cout << "Enter a number no higher than 20: ";
	cin >> n;
	for (long long i = 1; i <= n; i++)
		*factorial *= i;
	cout << "The factorial of " << n << " is " << *factorial << endl;
	delete factorial;
	return 0;
}