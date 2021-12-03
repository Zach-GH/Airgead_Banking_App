#include "UserData.h"
#include <iomanip>

using namespace std;

/*
* outputs Balance and Interest Without Additional Monthly Deposits display screen
* calculates the backend mathematics using a for loop less than or equal to the number of years
* outputs updated variables in a graph
*/

double UserData::BalanceNoMonthDep(double initInvest, double annualInterest, int numYears) {
	unsigned int i;
	double yearEndInterest;
	double yearEndBalance = initInvest;

	cout << setw(60) << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(64, '=') << endl;
	cout << setw(6) << "Year" << setw(24) << "Year End Balance" << setw(29) << "Year End Earned Interest" << endl;
	cout << string(64, '-') << endl;

	for (i = 1; i <= numYears; i++) {
		yearEndInterest = yearEndBalance * ((annualInterest / 100));
		yearEndBalance = yearEndBalance + yearEndInterest;

		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + yearEndBalance << " " << setw(23) << "$" << yearEndInterest << "\n" << endl;
	}
	system("pause");
	system("CLS");
}

/*
* outputs Balance and Interest With Additional Monthly Deposits display screen
* calculates the backend mathematics using a for loop less than or equal to the number of years
* uses a second for loop set to less than or equal to months to calculate the month by month data
* uses the second for loop to update the first in order to update the variables for output
* outputs updated variables in a graph
*/

double UserData::BalanceWithMonthDep(double initInvest, double monthDeposit, double annualInterest, int numYears) {
	unsigned int i;
	unsigned int j;
	double yearEndInterest;
	double monthEndInterest;
	double monthEndBalance = initInvest;
	double yearEndBalance = initInvest;
	const int months = 12;

	cout << setw(60) << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << string(64, '=') << endl;
	cout << setw(6) << "Year" << setw(24) << "Year End Balance" << setw(29) << "Year End Earned Interest" << endl;
	cout << string(64, '-') << endl;

	for (i = 1; i <= numYears; i++) {
		yearEndInterest = 0;
		for (j = 1; j <= months; j++) {
			monthEndInterest = 0;
			monthEndBalance = monthEndBalance + monthDeposit;
			monthEndInterest = (monthEndBalance * ((annualInterest / 100) / months));
			yearEndInterest = yearEndInterest + monthEndInterest;
			monthEndBalance = monthEndBalance + monthEndInterest;

		}
		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + monthEndBalance << " " << setw(20) << "$" << yearEndInterest << "\n" << endl;
	}
	system("pause");
	system("CLS");
	return 0;
}