/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File ChequingAccount.h
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account  {

		double trans_fee;
		double month_fees;

		public:
			ChequingAccount(double in_balance, double fee, double month_fee);

			bool credit(double add_amnt);
			bool debit(double deducion_amnt);
			void monthEnd();
			void display(std::ostream& obj);		
	};
}
#endif
