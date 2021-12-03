#ifndef USER_DATA_H
#define USER_DATA_H

#include <iostream>
#include <string>

// initializes class functions, setters and getters

class UserData {
public:
	void SetInit(double initInvest);
	void SetMonth(double monthDeposit);
	void SetAnnual(double annualInterest);
	void SetYear(int numYears);
	double GetInit() const;
	double GetMonthDep() const;
	double GetAnnual() const;
	int GetYear() const;
	double BalanceNoMonthDep(double initInvest, double annualInterest, int numYears);
	double BalanceWithMonthDep(double initInvest, double monthDeposit, double annualInterest, int numYears);
	int Display(double initInvest, double monthDeposit, double annualInterest, int numYears);
	int GetInput(double initInvest, double monthDeposit, double annualInterest, int numYears);

 // sets variables to be private for user security

private:
	double init;
	double month;
	double annual;
	int year;
};

#endif /* USER_DATA_H */