/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File Account.h
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account :public iAccount {

		double new_balance;

	protected:
		double balance()const;


	public:
		Account();
		Account(double initial_bal);
		bool credit(double credit_amount);
		bool debit(double debit_amount);
	};
} // namespace sict



#endif
