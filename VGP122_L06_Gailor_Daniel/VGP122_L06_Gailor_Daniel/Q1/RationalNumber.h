#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

template <typename T>
class RationalNumber 
{
	public:
	RationalNumber();
	RationalNumber(T, T);

	RationalNumber operator+(const RationalNumber&);
	RationalNumber operator-(const RationalNumber&);
	RationalNumber operator*(const RationalNumber&);
	RationalNumber operator/(const RationalNumber&);
	RationalNumber operator=(const RationalNumber&);


	bool operator==(const RationalNumber&);
	bool operator!=(const RationalNumber&);
	bool operator<(const RationalNumber&);
	bool operator>(const RationalNumber&);
	bool operator<=(const RationalNumber&);
	bool operator>=(const RationalNumber&);

	void Print();

private:
	T numerator;
	T denominator;
	void reduce();
	int GreatestCommonDenominator(T, T);


};