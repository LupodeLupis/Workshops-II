/***********************************************************
// OOP244 Workshop 8_Home: Completed
// File ChequingAccount.cpp
// Version 1.0
// Date 12/17/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Virtual Functions and Abstract Base Classes
///////////////////////////////////////////////////////////
***********************************************************/

#include <iomanip>
#include "ChequingAccount.h"

using namespace std;

namespace sict {
	
	// ChequingAcconut construct that accept 3 arguments and pass one argument to the base class construct
	ChequingAccount::ChequingAccount(double in_balance, double fee, double month_fee) : Account(in_balance)
	{
		if (fee > 0) {

			this->trans_fee = fee;
		}
		else {

			this->trans_fee = 0.0;
		}

		if (month_fee > 0) {

			this->month_fees = month_fee;
		}

		else {

			this->trans_fee = 0.0;
		}
	}

	/*ChequingAccount::credit Function that shadow the Account credit and debit function to add the amount 
	received and deduct the transanction fee = 0.50 from the balance*/
	bool ChequingAccount::credit(double add_amnt)
	{

		if (add_amnt > 0) {

			Account::credit(add_amnt);
			
			Account::debit(this->trans_fee);

			return true;
			
		}
		else
		{
			return false;
		}
	
	}
	/*ChequingAccount::debit Function that shadow the Account and debit function to deduct the amount
	received and the transanction fee = 0.50 to the balance*/
	bool ChequingAccount::debit(double deduction_amnt)

	{
		if (deduction_amnt > 0) {

			Account::debit(deduction_amnt);
			Account::debit(this->trans_fee);

			return true;
		}
		else
		{
			return false;
		}
	}
	// ChequingAccount::monthEnd functin that deduct the monthly fee = 2.00 from the balance
	void ChequingAccount::monthEnd()
	{
		Account::debit(this->month_fees);
		Account::debit(this->trans_fee);
	}

	void ChequingAccount::display(std::ostream& obj)
	{
		obj.setf(ios::fixed);
		obj << setprecision(2) << "Account type: Chequing" << endl << "Balance: $"
			<< balance() << endl << "Per Transaction Fee: " << this->trans_fee << endl << "Monthly Fee: " << this->month_fees << endl;
		obj.unsetf(ios::fixed);
	}
	
} // namespace sict;
