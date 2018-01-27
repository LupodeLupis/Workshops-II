/*******************************************************
// Workshop 3.Home: Classes and Privacy
// CRA_Account.h
// Version 2.0
// Date:2017/03/10
// Name:Alberto Laurenzi
// email:alaurenzi@myseneca.ca
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
/////////////////////////////////////////////////////////
***********************************************************/


#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {

	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;

	// Declaration Class CRA_Account
	class CRA_Account {

		//Data Member
		char*	pFlyName;
		char*	pGvnName;
		int		sinNum;
		int		aTaxReturnYears [max_yrs];
		double	aBalanceOw[max_yrs];
		int		numbYear;



	public:
		//Member Function 
		CRA_Account();
		~CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

		// Prototype Member Function declared for the Home portion
		void set(int year, double balance);
		bool isValidSin() const;

	};


}
#endif