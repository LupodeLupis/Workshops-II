/**********************************************************
// Workshop 3.Home: Classes and Privacy
// CRA_Account.cpp
// Version 2.0
// Date:2017/03/10
// Name:Alberto Laurenzi
// email:alaurenzi@myseneca.ca
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
		cout << " default Construct" << endl;
		pFlyName = nullptr;
		pGvnName = nullptr;
		sinNum = 0;

	}
	//Definition of Deconstructor
	CRA_Account::~CRA_Account() {

		cout << " deConstruct" << endl;
		//Deallocate memory for char* Family Name
		delete[] pFlyName;
		pFlyName = nullptr;

		//Deallocate memory for char* Given Name 
		delete[] pGvnName;
		pGvnName = nullptr;

	}


	//Defintion of set Function
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {

		// set a size of the char* Family Name and allocate memory
		int size = strlen(familyName);
		this->pFlyName = new char[size + 1];
		strcpy(pFlyName, familyName);


		// set a size of the char* Given Name and allocate memory
		int size1 = strlen(givenName);
		this->pGvnName = new char[size1 + 1];
		strcpy(pGvnName, givenName);

		sinNum = sin;

		if (isEmpty() == false) {

			numbYear = 0;
		}

		else {

			// EMPTY STATE 
			pFlyName = nullptr;
			pGvnName = nullptr;
			sinNum = 0;
		}


	}

	//Definition of isEmpty function
	bool CRA_Account::isEmpty() const {

		// Check if the SIN number is valid or not
		return ((sinNum < min_sin || sinNum > max_sin) || strlen(pFlyName) == 0
			|| (strlen(pGvnName) == 0) || (isValidSin() == false)) ? true : false;

	}

	//Definition of display Function to display the value of Balance owing and Refund due
	void CRA_Account::display() const {


		if (isEmpty() == false) {


			double due_refund = 0;
			double own_balance = 0;

			cout << "Family Name: " << pFlyName << endl;
			cout << "Given Name : " << pGvnName << endl;
			cout << "CRA Account: " << sinNum << endl;


			for (int i = 0; i < numbYear; i++)
			{
				own_balance += aBalanceOw[i];

				due_refund = (-aBalanceOw[i]);


				if (own_balance > 2)
				{
					cout << "Year (" << aTaxReturnYears[i] << ") balance owing: " <<
						aBalanceOw[i] << endl;

				}

				else if (due_refund > 2)
				{
					cout.setf(ios::fixed);
					cout.precision(2);

					cout << "Year (" << aTaxReturnYears[i] << ") refund due: "
						<< -aBalanceOw[i] << endl;

					cout.unsetf(ios::fixed);
					cout.precision(6);

				}
				else
				{
					cout << "Year (" << aTaxReturnYears[i] << ") No balance owing or refund due!" << endl;

				}


			}
		}
	}
	// Definition of Set function for storing data in the array TaxReturn and BalanceOwing 
	void CRA_Account::set(int year, double balance) {


		if (isEmpty() == false && numbYear < max_yrs)
		{
			aTaxReturnYears[numbYear] = year;
			aBalanceOw[numbYear] = balance;
			numbYear += 1;

		}

	}
	// Definition of function for checking the validity of the SIN
	bool CRA_Account::isValidSin() const {

		int numSin = sinNum % 10;
		int numSin1 = sinNum / 10;
		int alternum[8];
		int numEven;
		int sumEven = 0;
		int sumOdd = 0;
		int totSum = 0;

		for (int i = 0; i < 8; i++) {

			alternum[i] = numSin1 % 10;
			numSin1 /= 10;

			if (i % 2 == 0) {

				numEven = alternum[i] * 2;

				sumEven += (numEven % 10) + (numEven / 10);
			}
			else
			{
				sumOdd += alternum[i];
			}
		}

		totSum = sumEven + sumOdd + numSin;

		return (totSum % 10 == 0) ? true : false;

	}

}
