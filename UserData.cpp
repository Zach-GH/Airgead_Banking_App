#include "UserData.h"

using namespace std;

// setters and getters for UserData class
// getters allow the private variables to be called and utilized in the program

void UserData::SetInit(double initInvest) {
	init = initInvest;
}
void UserData::SetMonth(double monthDeposit) {
	month = monthDeposit;
}
void UserData::SetAnnual(double annualInterest) {
	annual = annualInterest;
}
void UserData::SetYear(int numYears) {
	year = numYears;
}
double UserData::GetInit() const {
	return init;
}
double UserData::GetMonthDep() const {
	return month;
}
double UserData::GetAnnual() const {
	return annual;
}
int UserData::GetYear() const {
	return year;
}