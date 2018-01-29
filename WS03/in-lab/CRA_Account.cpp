/**********************************************************
// Workshop 3.Lab: Classes and Privacy
// CRA_Account.cpp
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


#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;
namespace sict {

	//Definition of Constructors
	CRA_Account::CRA_Account() {

		pFlyName = nullptr;
		pGvnName = nullptr;
		sinNum = 0;

	}
	//Definition of Deconstructor
	CRA_Account::~CRA_Account() {

		//Deallocate memory for char* Family Name
		delete[] pFlyName;
		pFlyName = nullptr;
		//Deallocate memory for char* Given Name 
		delete[] pGvnName;
		pGvnName = nullptr;

	}

	//Defintion of set Function
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		sinNum = sin;

		if (isEmpty() == false) {

			// set a size of the char* Family Name and allocate memory
			int size = strlen(familyName);
			pFlyName = new char[size + 1];
			strcpy(pFlyName, familyName);

			// set a size of the char* Given Name and allocate memory
			int size1 = strlen(givenName);
			pGvnName = new char[size1 + 1];
			strcpy(pGvnName, givenName);

			sinNum = sin;
		}

		else {

			// EMPTY STATE 
			isEmpty();

		}
	}

	//Definition of isEmpty function
	bool CRA_Account::isEmpty() const {

		// Check if the SIN number is valid or not
	
			return (sinNum < min_sin || sinNum > max_sin) ? true : false;
		
	}

	//Definition of display Function
	void CRA_Account::display() const {

		// Display if data are valid
		if (isEmpty() == false) {    //== false

			cout << "Family Name: " << pFlyName << endl;
			cout << "Given Name : " << pGvnName << endl;
			cout << "CRA Account: " << sinNum   << endl;

		}
		else
		{
			// Dislapy if the data are invalid
			cout << "Account object is empty!" << endl;

		}

	}

}
