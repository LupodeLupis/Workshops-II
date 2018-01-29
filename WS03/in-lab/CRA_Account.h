/**********************************************************
// Workshop 3.Lab: Classes and Privacy
// CRA_Account.h
// Version 2.0
// Date:2017/09/28
// Name:Alberto Laurenzi
// email:
// Description
// This workshop demonstrates classes in C++ and
// how member variables are defined privately, but
// accessed through public member functions
///////////////////////////////////////////////////////////
**********************************************************/


#ifndef SICT_CRA_ACCOUNT_H
#define SICT_CRA_ACCOUNT_H


namespace sict {
	
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	// Declaration Class CRA_Account
	class CRA_Account {

		//Data Member
		char* pFlyName;
		char* pGvnName;
		int   sinNum;



	public:
		//Member Function 
		CRA_Account();
		~CRA_Account();
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

	};


}
#endif


