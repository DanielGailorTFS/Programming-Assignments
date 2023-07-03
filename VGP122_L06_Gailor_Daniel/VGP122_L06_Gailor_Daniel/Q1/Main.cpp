/* Create a RationalNumber(fractions) class like the one in Exercise 9.6.
Provide the following capabilities:
a. Create the class as a template class
b. Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
c. Overload the addition, subtraction, multiplication and division operators for this class.
d. Overload the relational and equality operators for this class. */
#include "RationalNumber.h"

int main()
{
	RationalNumber<float> r1(10.0, 20.0);
	RationalNumber<float> r2(3.0, 4.0);
	RationalNumber<float> total;
	cout << "First Rational Number: " << endl;
	r1.Print();
	cout << endl;
	cout << "Second Rational Number: " << endl;
	r2.Print();
	cout << endl;

	total = r1 + r2;
	cout << "Addition:" << endl;
	total.Print();
	cout << endl;

	total = r1 - r2;
	cout << "Subtraction:" << endl;
	total.Print();
	cout << endl;

	total = r1 * r2;
	cout << "Multiplication:" << endl;
	total.Print();
	cout << endl;

	total = r1 / r2;
	cout << "Division:" << endl;
	total.Print();
	cout << endl;

	cout << "total == r1 / r2 ? : " << ((total == r1 / r2) ? "true" : "false") << endl;
	cout << "total != r1 / r2 ? : " << ((total != r1 / r2) ? "true" : "false") << endl;
	cout << "total < r1 / r2 ? : " << ((total < r1 / r2) ? "true" : "false") << endl;
	cout << "total > r1 / r2 ? : " << ((total > r1 / r2) ? "true" : "false") << endl;
	cout << "total <= r1 / r2 ? : " << ((total <= r1 / r2) ? "true" : "false") << endl;
	cout << "total >= r1 / r2 ? : " << ((total >= r1 / r2) ? "true" : "false") << endl;

	return 0;
}