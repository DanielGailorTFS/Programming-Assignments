/* Define a function hypotenuse that calculates the hypotenuse of a right triangle
when the other two sides are given. The function should take two double arguments
and return the hypotenuse as a double. Use this function in a program to determine
the hypotenuse for each of the triangles shown below. 

Triangle	Side 1		Side 2
1			3.0			4.0
2			5.0			12.0
3			8.0			15.0 */

#include <iostream>
#include <cmath>
using namespace std;

double hypCalc(double x, double y) {
	double z = 0;
	z = sqrt((pow(x, 2)) + (pow(y, 2)));
	return z;
}

int main() {
	double triangleLength[3][2];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {

			cout << "Please enter the length of side " << j + 1 << " of triangle " << ": " << endl;
			cin >> triangleLength[i][j];

		}
	}

	for (int i = 0; i < 3; i++) {
		cout << "The hypotenuse of triangle " << i + 1 << ": " << hypCalc(triangleLength[i][0], triangleLength[i][1]) << endl;
		}


}