/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File iAccount.h
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount {
	public:

		virtual bool credit(double add_positive) = 0;
		virtual bool debit(double sub_positive) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream& cc_info) = 0;
	};
	iAccount* CreateAccount(const char* cc_type, double balance);

} // namespace sict


#endif

