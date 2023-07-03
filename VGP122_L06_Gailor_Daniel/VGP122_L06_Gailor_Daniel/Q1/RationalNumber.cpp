/* Create a RationalNumber(fractions) class like the one in Exercise 9.6.
Provide the following capabilities:
a. Create the class as a template class
b. Create a constructor that prevents a 0 denominator in a fraction, reduces or simplifies
fractions that are not in reduced form and avoids negative denominators.
c. Overload the addition, subtraction, multiplication and division operators for this class.
d. Overload the relational and equality operators for this class. */

#include "RationalNumber.h"

template <typename T>
RationalNumber<T>::RationalNumber()
{
	numerator = 0;
	denominator = 1;
}

template <typename T>
RationalNumber<T>::RationalNumber(T num, T den)
{
	if (den == 0)
	{
		cout << "Denominator cannot be 0. Setting denominator to 1." << endl;
		denominator = 1;
	}
	else
	{
		denominator = den;
	}
	numerator = num;
	reduce();
}

template <typename T>
void RationalNumber<T>::reduce()
{
	if (denominator < 0)
	{
		denominator *= -1;
		numerator *= -1;
	}
	int gcd = GreatestCommonDenominator(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

template <typename T>
int RationalNumber<T>::GreatestCommonDenominator(T num, T den)
{
	if (den == 0)
	{
		return num;
	}
	return GreatestCommonDenominator((int)den, (int)num % (int)den);
}

template <typename T>
// Overload the addition operator
RationalNumber<T> RationalNumber<T>::operator+(const RationalNumber& rhs)
{
	RationalNumber<T> temp;
	temp.numerator = (numerator * rhs.denominator) + (denominator * rhs.numerator);
	temp.denominator = denominator * rhs.denominator;
	temp.reduce();
	return temp;
}

template <typename T>
// Overload the subtraction operator
RationalNumber<T> RationalNumber<T>::operator-(const RationalNumber& rhs)
{
	RationalNumber<T> temp;
	temp.numerator = (numerator * rhs.denominator) - (denominator * rhs.numerator);
	temp.denominator = denominator * rhs.denominator;
	temp.reduce();
	return temp;
}

template <typename T>
// Overload the multiplication operator
RationalNumber<T> RationalNumber<T>::operator*(const RationalNumber& rhs)
{
	RationalNumber<T> temp;
	temp.numerator = numerator * rhs.numerator;
	temp.denominator = denominator * rhs.denominator;
	temp.reduce();
	return temp;
}

template <typename T>
// Overload the division operator
RationalNumber<T> RationalNumber<T>::operator/(const RationalNumber& rhs)
{
	RationalNumber<T> temp;
	temp.numerator = numerator * rhs.denominator;
	temp.denominator = denominator * rhs.numerator;
	temp.reduce();
	return temp;
}

template <typename T>
RationalNumber <T> RationalNumber<T>::operator=(const RationalNumber& rhs)
{
	numerator = rhs.numerator;
	denominator = rhs.denominator;
	reduce();
	return *this;	
}

template <typename T>
// Overload the equality operator
bool RationalNumber<T>::operator==(const RationalNumber& rhs)
{
	return (numerator == rhs.numerator && denominator == rhs.denominator);
}

template <typename T>
// Overload the inequality operator
bool RationalNumber<T>::operator!=(const RationalNumber& rhs)
{
	return (numerator != rhs.numerator || denominator != rhs.denominator);
}

template <typename T>
// Overload the less than operator
bool RationalNumber<T>::operator<(const RationalNumber& rhs)
{
	return (numerator * rhs.denominator < denominator * rhs.numerator);
}

template <typename T>
// Overload the greater than operator
bool RationalNumber<T>::operator>(const RationalNumber& rhs)
{
	return (numerator * rhs.denominator > denominator * rhs.numerator);
}

template <typename T>
// Overload the less than or equal to operator
bool RationalNumber<T>::operator<=(const RationalNumber& rhs)
{
	return (numerator * rhs.denominator <= denominator * rhs.numerator);
}

template <typename T>
// Overload the greater than or equal to operator
bool RationalNumber<T>::operator>=(const RationalNumber& rhs)
{
	return (numerator * rhs.denominator >= denominator * rhs.numerator);
}

template <typename T>
void RationalNumber<T>::Print()
{
	cout << numerator << "/" << denominator << endl;
}

template class RationalNumber<int>;
template class RationalNumber<float>;
template class RationalNumber<double>;


