#include "UserData.h"
#include <iomanip>

using namespace std;

// First display the user sees and updates with GetInput class function

int UserData::Display(double initInvest, double monthDeposit, double annualInterest, int numYears) {
		cout << fixed << setprecision(2);
		std::cout << std::string(32, '*') << endl;
		std::cout << std::string(10, '*') << " Data Input " << std::string(10, '*') << endl;
		cout << "Initial Investment Amount: $" << initInvest << endl;
		cout << "Monthly Deposit: $" << monthDeposit << endl;
		cout << fixed << setprecision(0);
		cout << "Annual Interest: %" << annualInterest << endl;
		cout << "Number of years: " << numYears << endl;
		return 0;
	}

 /* 
 *  Calls Display class function and gets user data
 *  Uses a throw catch clause to secure input
 *  Throws error and outputs message telling user to input the correct data
 *  Updates display screen so user can see input as they enter it
 *  Sets user data into private variables for user data security
 */ 

int UserData::GetInput(double initInvest, double monthDeposit, double annualInterest, int numYears) {
	UserData userData{};
	system("pause");
	system("CLS");

	while (true) {
		try {

			userData.Display(initInvest, monthDeposit, annualInterest, numYears);
			cout << "\nEnter Initial Investment Amount" << endl;
			std::cin.clear();
			cin >> initInvest;
			if (initInvest <= 0) {
				throw 1;
			}
			UserData::SetInit(initInvest);
			system("CLS");

			userData.Display(initInvest, monthDeposit, annualInterest, numYears);
			cout << "\nEnter Monthly Deposit" << endl;
			cin >> monthDeposit;
			if (monthDeposit <= 0) {
				throw 2;
			}
			UserData::SetMonth(monthDeposit);
			system("CLS");

			userData.Display(initInvest, monthDeposit, annualInterest, numYears);
			cout << "\nEnter Annual Interest" << endl;
			cin >> annualInterest;
			if (annualInterest <= 0) {
				throw 3;
			}
			UserData::SetAnnual(annualInterest);
			system("CLS");

			userData.Display(initInvest, monthDeposit, annualInterest, numYears);
			cout << "\nEnter Number of years" << endl;
			cin >> numYears;
			if (numYears <= 0) {
				throw 4;
			}
			UserData::SetYear(numYears);
			system("CLS");
			userData.Display(initInvest, monthDeposit, annualInterest, numYears);
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