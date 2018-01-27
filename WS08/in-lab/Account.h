/***********************************************************
// OOP244 Workshop 8_Lab: Completed
// File Account.h
// Version 1.0
// Date 12/15/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {

	class Account :public iAccount{

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
