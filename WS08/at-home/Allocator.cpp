/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File Allocator.cpp
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#include "SavingsAccount.h"
#include"ChequingAccount.h"

namespace sict {

	const double rate = 0.05;
	const double fee = 0.50;
	const double monthly_fee = 2.00;


	/*This function create a new saving/chequing account using pointer notation of type iAccount and allocate memory
	using the SavingAccount/ChequingAccount Contructor and send the parameters */
	iAccount* CreateAccount(const char* cc_type, double initial_balance) {

		iAccount * cc_saving = nullptr;
		
		if (cc_type[0] == 'S') {

			cc_saving = new SavingsAccount(initial_balance, rate);
		}

		else if (cc_type[0] == 'C'){

			cc_saving = new ChequingAccount(initial_balance, fee , monthly_fee);
		}
		else
		{
			delete cc_saving;
			cc_saving = nullptr;
		}

		return cc_saving;
	}

}