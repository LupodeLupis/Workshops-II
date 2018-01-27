/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File SavingAccount.cpp
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
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
		obj << setprecision(2) << "Account type: Savings" << endl << "Balance: $"
			<< balance() << endl << "Interest Rate (%): " << credit * 100 << endl;
		obj.unsetf(ios::fixed);
	}
}