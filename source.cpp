#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

//Declare variables to store input

double initialInvestment;
double monthlyDeposit;
double annualInterest;
int numYears;
int numMonths;

// Output display 1 for getting information from the user

int display() {

	cout << fixed << setprecision(2);
	std::cout << std::string(32, '*') << endl;
	std::cout << std::string(10, '*') << " Data Input " << std::string(10, '*') << endl;
	cout << "Initial Investment Amount: $" << initialInvestment << endl;
	cout << "Monthly Deposit: $" << monthlyDeposit << endl;
	cout << fixed << setprecision(0);
	cout << "Annual Interest: %" << annualInterest << endl;
	cout << "Number of years: " << numYears << endl;
	
	return 0;
}

// Backend logic for display 1
// Exception Handling for input verification

int getInput() {

	system("pause");
	system("CLS");

	while (true) {
		try {

			display();
			cout << "\nEnter Initial Investment Amount" << endl;
			std::cin.clear();
			cin >> initialInvestment;
			if (initialInvestment <= 0) {
				throw 1;
			}
			system("CLS");

			display();
			cout << "\nEnter Monthly Deposit" << endl;
			cin >> monthlyDeposit;
			if (monthlyDeposit <= 0) {
				throw 2;
			}
			system("CLS");

			display();
			cout << "\nEnter Annual Interest" << endl;
			cin >> annualInterest;
			if (annualInterest <= 0) {
				throw 3;
			}
			system("CLS");

			display();
			cout << "\nEnter Number of years" << endl;
			cin >> numYears;
			if (numYears <= 0) {
				throw 4;
			}
			system("CLS");
			display();
			system("pause");
			system("CLS");
			break;
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a positive, real number." << endl;
			system("pause");
			system("CLS");

		}
	}

	return 0;
}

// Display 2 for data manipulation
// Back End Logic for Display 2

int finalOutput() {

	double yearEndBalance = initialInvestment;
	double yearEndInterest;

	cout << setw(60) << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(64, '=') << endl;
	cout << setw(6) << "Year" << setw(24) << "Year End Balance" << setw(29) << "Year End Earned Interest" << endl;
	cout << string(64, '-') << endl;

	for (int i = 1; i <= numYears; i++) {

		yearEndInterest = yearEndBalance * ((annualInterest / 100));
		yearEndBalance = yearEndBalance + yearEndInterest;

		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + yearEndBalance << " " << setw(23) << "$" << yearEndInterest << "\n" << endl;
		
	}

	system("pause");
	system("CLS");

	numMonths = 12;
	double monthEndInterest;
	double monthEndBalance = initialInvestment;
	yearEndBalance = initialInvestment;

	cout << setw(60) << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << string(64, '=') << endl;
	cout << setw(6) << "Year" << setw(24) << "Year End Balance" << setw(29) << "Year End Earned Interest" << endl;
	cout << string(64, '-') << endl;
	
	for (int i = 1; i <= numYears; i++) {
		yearEndInterest = 0; // for each iteration of numYears reset YearEndInterest
		for (int j = 1; j <= numMonths; j++) {

			// for each iteration of numMonths reset monthEndInterest

			monthEndInterest = 0;

			// get the initial value of the month balance

			monthEndBalance = monthEndBalance + monthlyDeposit;

			// calculate interest at the end of the month

			monthEndInterest = (monthEndBalance * ((annualInterest / 100) / numMonths));
			
			// add interest to yearly interest to output 

			yearEndInterest = yearEndInterest + monthEndInterest;
			
			// add monthly balance and interest for final value

			monthEndBalance = monthEndBalance + monthEndInterest;
			
			
			

		}
		cout << setprecision(2) << setw(6) << i << " " << setw(19) << "$" << 0.00 + monthEndBalance << " " << setw(20) << "$" << yearEndInterest << "\n" << endl;
	}

	system("pause");
	system("CLS");
	return 0;
}

int main() {
	display();
	getInput();
	finalOutput();
}
