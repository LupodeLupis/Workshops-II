/***********************************************************
// OOP244 Workshop 8_Lab: Completed
// File Allocator.cpp
// Version 1.0
// Date 12/15/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#include "SavingsAccount.h"

namespace sict {

	const double rate = 0.05;


	/*This function create a new saving account using pointer notation of type iAccount and allocate memory
	using the SavingAccount Contructor and set the parameters*/
	iAccount* CreateAccount(const char* cc_type, double initial_balance) {

		iAccount * cc_saving = nullptr;
		if (cc_type[0] == 'S') {

			cc_saving = new SavingsAccount(initial_balance, rate);
		}
		else {

			delete cc_saving;
			cc_saving = nullptr;
		}
		return cc_saving;
	}

}
