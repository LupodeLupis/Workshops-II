/***********************************************************
// OOP244 Workshop 8_Lab: Completed
// File Account.cpp
// Version 1.0
// Date 12/15/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#include "Account.h"

using namespace sict;


double Account::balance() const { return this->new_balance; }


Account::Account() { this->new_balance = 0.0; }


bool Account::credit(double credit_amount)
{
	return (credit_amount > 0) ? this->new_balance += credit_amount : false;	
}


bool Account::debit(double debit_amount)
{
	return (debit_amount > 0) ? this->new_balance -= debit_amount : false;
}


Account::Account(double initial_bal)
{
	if (initial_bal > 0) {

		this->new_balance = initial_bal;
	}
	else
	{
		this->new_balance = 0.0;
	}
}

