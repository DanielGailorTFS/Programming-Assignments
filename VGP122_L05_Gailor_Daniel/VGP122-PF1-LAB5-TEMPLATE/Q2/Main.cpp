/* Create a class called Rational for performing arithmetic with fractions. Write a program to test
your class. Use integer variables to represent the private data of the class— the numerator and the
denominator. Provide a constructor that enables an object of this class to be initialized when it’s
declared. The constructor should contain default values in case no initializers are provided and
should store the fraction in reduced form.

For example, the fraction 2/4 would be stored in the object as 1 in the numerator and 2 in the denominator. 

Provide public member functions that perform each of the following tasks:
a. add—Adds two Rational numbers. The result should be stored in reduced form.
b. subtract—Subtracts two Rational numbers. Store the result in reduced form.
c. multiply—Multiplies two Rational numbers. Store the result in reduced form.
d. divide—Divides two Rational numbers. The result should be stored in reduced form.
e. toRationalString—Returns a string representation of a Rational number in the form a/b, where
a is the numerator and b is the denominator.
f. toDouble—Returns the Rational number as a double. */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Rational
{

	private:
	int numerator = 1;
	int denominator = 2;

	public:
		Rational(int numerator, int denominator)
		{
		setNumerator(numerator);
		setDenominator(denominator);
		}

		void setNumerator(int numerator)
		{
		this->numerator = numerator;
		}

		void setDenominator(int denominator)
		{
		this->denominator = denominator;
		}

		int getNumerator()
		{
		return numerator;
		}

		int getDenominator()
		{
		return denominator;
		}

		string toRationalString()
		{
		stringstream ss;
		ss << numerator << "/" << denominator;
		return ss.str();
		}

		double toDouble()
		{
		return (double)numerator / denominator;
		}

		Rational add(Rational r)
		{
		int numerator = this->numerator * r.getDenominator() + this->denominator * r.getNumerator();
		int denominator = this->denominator * r.getDenominator();
		return Rational(numerator, denominator);
		}

		Rational subtract(Rational r)
		{
		int numerator = this->numerator * r.getDenominator() - this->denominator * r.getNumerator();
		int denominator = this->denominator * r.getDenominator();
		return Rational(numerator, denominator);
		}

		Rational multiply(Rational r)
		{
		int numerator = this->numerator * r.getNumerator();
		int denominator = this->denominator * r.getDenominator();
		return Rational(numerator, denominator);
		}

		Rational divide(Rational r)
		{
		int numerator = this->numerator * r.getDenominator();
		int denominator = this->denominator * r.getNumerator();
		return Rational(numerator, denominator);
		}
		Rational simplify()
		{
			int gcd = 1;
			int smaller = numerator < denominator ? numerator : denominator;
			for (int i = 2; i <= smaller; i++)
			{
				if (numerator % i == 0 && denominator % i == 0)
				{
					gcd = i;
				}
			}
			return Rational(numerator / gcd, denominator / gcd);
		}

};

int main()
{
	int numerator, denominator;
	cout << "Enter numerator and denominator for first rational number: ";
	cin >> numerator >> denominator;
	Rational r1(numerator, denominator);
	cout << "Enter numerator and denominator for second rational number: ";
	cin >> numerator >> denominator;
	Rational r2(numerator, denominator);
	Rational r3 = r1.add(r2);
	Rational r4 = r1.subtract(r2);
	Rational r5 = r1.multiply(r2);
	Rational r6 = r1.divide(r2);
	cout << r1.toRationalString() << " + " << r2.toRationalString() << " = " << r3.toRationalString() << " = " << r3.toDouble() << endl;
	cout << r1.toRationalString() << " - " << r2.toRationalString() << " = " << r4.toRationalString() << " = " << r4.toDouble() << endl;
	cout << r1.toRationalString() << " * " << r2.toRationalString() << " = " << r5.toRationalString() << " = " << r5.toDouble() << endl;
	cout << r1.toRationalString() << " / " << r2.toRationalString() << " = " << r6.toRationalString() << " = " << r6.toDouble() << endl;
	cout << r1.toRationalString() << " simplified is " << r1.simplify().toRationalString() << endl;
	cout << r2.toRationalString() << " simplified is " << r2.simplify().toRationalString() << endl;
	cout << r3.toRationalString() << " simplified is " << r3.simplify().toRationalString() << endl;
	cout << r4.toRationalString() << " simplified is " << r4.simplify().toRationalString() << endl;
	cout << r5.toRationalString() << " simplified is " << r5.simplify().toRationalString() << endl;
	cout << r6.toRationalString() << " simplified is " << r6.simplify().toRationalString() << endl;
	return 0;
}