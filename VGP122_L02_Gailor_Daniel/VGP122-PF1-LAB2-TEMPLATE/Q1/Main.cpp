/* Develop a C++ program that will determine whether a department-store customer has
exceeded the credit limit on a charge account. For each customer, the following facts are
available:
a. Account number (an integer)
b. Balance at the beginning of the month
c. Total of all items charged by this customer this month
d. Total of all credits applied to this customer's account this month
e. Allowed credit limit

The program should use a while statement to input each of these facts, calculate the new
balance (= beginning balance + charges � credits) and determine whether the new balance
exceeds the customer�s credit limit. For those customers whose credit limit is exceeded, the
program should display the customer�s account number, credit limit, new balance and the
message "Credit Limit Exceeded."

Enter account number (or -1 to quit): 100
Enter beginning balance: 5394.78
Enter total charges: 1000.00
Enter total credits: 500.00
Enter credit limit: 5500.00
New balance is 5894.78
Account: 100
Credit limit: 5500.00
Balance: 5894.78
Credit Limit Exceeded.
Enter Account Number (or -1 to quit): 200
Enter beginning balance: 1000.00
Enter total charges: 123.45
Enter total credits: 321.00
Enter credit limit: 1500.00
New balance is 802.45
Enter Account Number (or -1 to quit): -1 */

#include <iostream>
using namespace std;

int main() {

    int accNum;
    float startBalance;
    float totalCharges;
    float totalCredits;
    float creditLimit;
    float newBalance;

        cout << "Please enter your account number (Or type -1 to exit)";
        cin >> accNum;

        while (accNum != -1) {
            cout << "Enter starting balance: ";
            cin >> startBalance;

            cout << "Enter total charges due: ";
            cin >> totalCharges;

            cout << "Enter total credits to be applied: ";
            cin >> totalCredits;

            cout << "Enter credit limit: ";
            cin >> creditLimit;

            newBalance = startBalance + totalCharges - totalCredits;
            cout << "Your new balance is: " << newBalance << endl;

            if (newBalance > creditLimit) {
                cout << "Credit limit exceeded on account number: " << accNum << endl;
            }
        }

        return 0;




        }