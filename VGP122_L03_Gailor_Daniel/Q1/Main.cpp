/* A parking garage charges a $20.00 minimum fee to park for up to three hours. The
garage charges an additional $5.00 per hour for each hour or part thereof in excess
of three hours. The maximum charge for any given 24-hour period is $50.00. Assume
that no car parks for longer than 24 hours at a time.
Write a program that calculates and prints the parking charges for each of three
customers who parked their cars in this garage yesterday. You should enter the
hours parked for each customer. Your program should print the results in a neat
tabular format and should calculate and print the total of yesterday’s receipts. The
program should use the function calculateCharges to determine the charge for each
customer. Your outputs should appear in the following format: 

Car		Hours		Charge
1		1.5			20.0
2		4.0			25.0
3		24.0		50.0
Total	29.5		95.50
*/

#include <iostream>
using namespace std;






float calculateCharges(float x){
	float totalCharge = 0.00f;

	if (x <= 3) {
		totalCharge = 20.00f;
	}

	else if (x > 3 && x <= 24) {
		float addHours = x - 3;
		float addCharge = 5.00f;
		totalCharge = 20.00f + (addHours * addCharge);

		if (totalCharge > 50) {
			totalCharge = 50;
		}

		}

	else {
		totalCharge = 50.00f;
		}
		return totalCharge;

	}

int main(){

	float hoursCar[3];
	float totalCharges = 0.00f, totalHours = 0.00f;

	for (int i = 0; i < 3; i++) {
		
		cout << "Enter the hours parked for car " << i + 1 << endl;
		cin >> hoursCar[i];
		totalCharges += calculateCharges(hoursCar[i]);
		totalHours += hoursCar[i];
	
	}

	cout << "car     Hours     Charge" << endl;

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "       " << hoursCar[i] << "       " << calculateCharges(hoursCar[i]) << endl;
		}

	cout << "Total:  " << totalHours << "      " << totalCharges << endl;



	return 0;
}