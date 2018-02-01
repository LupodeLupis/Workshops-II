/***********************************************************
// OOP244 Workshop 8_Lab: Completed
// File SavingAccount.h
// Version 1.0
// Date 12/15/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account{

		double credit;
	public:
	
		SavingsAccount(double in_balance, double interest);
		void monthEnd();
		void display(std::ostream& obj);
		
	};
} // namespace sict
#endif
