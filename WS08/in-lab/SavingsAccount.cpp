/***********************************************************
// OOP244 Workshop 8_Lab: Completed
// File SavingAccount.cpp
// Version 1.0
// Date 12/15/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"

using namespace std;
namespace sict {

	// SavingAccount Constructor with two parameters that call explicity the Account Construct sending in balance parameter
	SavingsAccount::SavingsAccount(double in_balance, double interest) : Account(in_balance)
	{
		if (interest > 0) {

			this->credit = interest;
		}
		else
		{
			this->credit = 0.0;
		}
	}
	
	// SavingAccount::monthEnd that calculates the interest and add it to the balance thrugh credit()
	void SavingsAccount::monthEnd()
	{
		double temp_balance = this->credit * this->balance();
		Account::credit(temp_balance);
	}

	// Function SavingAccount::display  to display the content
	void SavingsAccount::display(std::ostream & obj)
	{
		obj.setf(ios::fixed);
		obj << setprecision(2) << "Account type: Savings" << "\n" << "Balance: $" 
			<< balance() << "\n"  << "Interest Rate (%): " << credit * 100 << "\n";
		obj.unsetf(ios::fixed);
	}
}
