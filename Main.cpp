#include "UserData.h"

UserData currUser;

using namespace std;

int main() {
	
	// Calls objects from UserData class

	currUser.Display(currUser.GetInit(), currUser.GetMonthDep(), currUser.GetAnnual(), currUser.GetYear());
	currUser.GetInput(currUser.GetInit(), currUser.GetMonthDep(), currUser.GetAnnual(), currUser.GetYear());
	currUser.BalanceNoMonthDep(currUser.GetInit(), currUser.GetAnnual(), currUser.GetYear());
	currUser.BalanceWithMonthDep(currUser.GetInit(), currUser.GetMonthDep(), currUser.GetAnnual(), currUser.GetYear());
}
