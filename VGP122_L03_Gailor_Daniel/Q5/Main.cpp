/* Implement the following integer functions:
a. Function celsius returns the Celsius equivalent of a Fahrenheit temperature.
b. Function fahrenheit returns the Fahrenheit equivalent of a Celsius
temperature.
c. Use these functions to write a program that prints charts showing the
Fahrenheit equivalents of all Celsius temperatures from 0 to 100 degrees, and
the Celsius equivalents of all Fahrenheit temperatures from 32 to 212 degrees.

Print the outputs in a neat tabular format that minimizes the number of lines of
output while remaining readable. */

#include <iostream>
using namespace std;

float fahrToCel(float fahr) {
	fahr = (fahr - 32) * 5 / 9;
	return floor(fahr * 100 + 0.5) / 100;
}

float celToFahr(float cel) {
	cel = (cel * 9 / 5) + 32;
	return floor(cel * 100 + 0.5) / 100;
}

int main() {

	cout << "Celcius || Fahrenheit    Fahrenheit || Celcius" << endl;

	for (int c = 0, f = 32; c <= 100 && f <= 212; c++, f++) {
		float fahr = celToFahr(c);
		float cel = fahrToCel(f);

		cout << c << " || " << fahr << "                  " << f << " || " << cel << endl;
	
	}
	return 0;
}