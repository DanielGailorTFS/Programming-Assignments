/* Create a SavingsAccount class. Use a static data member annualInterestRate to store the
annual interest rate for each of the savers. Each member of the class contains a private data
member savingsBalance indicating the amount the saver currently has on deposit. Provide
member function calculateMonthlyInterest that calculates the monthly interest by multiplying the
savingsBalance by annualInterestRate divided by 12; this interest should be added to
savingsBalance. Provide a static member function modifyInterestRate that sets the static
annualInterestRate to a new value. Write a driver program to test class SavingsAccount.
Instantiate two different objects of class SavingsAccount, saver1 and saver2, with balances of
$2000.00 and $3000.00, respectively. Set the annualInterestRate to 3 percent. Then calculate the
monthly interest and print the new balances for each of the savers. Then set the
annualInterestRate to 4 percent, calculate the next month’s interest and print the new balances for
each of the savers. */
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class SavingsAccount
{
	private:
		static double annualInterestRate;
		double savingsBalance;

	public:
		SavingsAccount(double savingsBalance)
		{
		setSavingsBalance(savingsBalance);
		}

		void setSavingsBalance(double savingsBalance)
		{
		this->savingsBalance = savingsBalance;
		}

		double getSavingsBalance()
		{
		return savingsBalance;
		}

		static void modifyInterestRate(double annualInterestRate)
		{
		SavingsAccount::annualInterestRate = annualInterestRate;
		}

		double calculateMonthlyInterest()
		{
		return savingsBalance * annualInterestRate / 12;
		}

		double calculateMonthlyInterestOverYear()
		{
			return savingsBalance * pow(1 + annualInterestRate / 12, 12);
		}
		double addMonthlyInterest()
		{
			return savingsBalance += calculateMonthlyInterest();
		}

		string toString()
		{
		stringstream ss;
		ss << fixed << setprecision(2) << savingsBalance;
		return ss.str();
		}


};

double SavingsAccount::annualInterestRate = 0.03;

int main()
{
	SavingsAccount saver1(2000.00);
	SavingsAccount saver2(3000.00);

	cout << "Saver 1's balance is $" << saver1.toString() << endl;
	cout << "Saver 2's balance is $" << saver2.toString() << endl;
	cout << "Projected balances after 1 month with accrued interest:" << endl;
	cout << "Saver 1: $" << saver1.addMonthlyInterest() << endl;
	cout << "Saver 2: $" << saver2.addMonthlyInterest() << endl;
	cout << "Projected balances after 1 year:" << endl;
	cout << "Saver 1's end of year balance is: $" << saver1.calculateMonthlyInterestOverYear() << endl;
	cout << "Saver 2's end of year balance is: $" << saver2.calculateMonthlyInterestOverYear() << endl;
	cout << endl;
	SavingsAccount::modifyInterestRate(0.04);
	cout << "Interest rate is now 4%" << endl;
	cout << "Projected balances after 1 month with accrued interest:" << endl;
	cout << "Saver 1: $" << saver1.addMonthlyInterest() << endl;
	cout << "Saver 2: $" << saver2.addMonthlyInterest() << endl;
	cout << "Projected balances after 1 year:" << endl;
	cout << "Saver 1's end of year balance is: $" << saver1.calculateMonthlyInterestOverYear() << endl;
	cout << "Saver 2's end of year balance is: $" << saver2.calculateMonthlyInterestOverYear() << endl;
	return 0;
}
