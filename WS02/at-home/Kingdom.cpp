/***********************************************************
// OOP244 Workshop 2.Home: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 09/26/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description :practice in allocating and deallocating dynamic memory
///////////////////////////////////////////////////////////
***********************************************************/


//Included the necessary headers
#include <iostream>
#include "Kingdom.h"

//The sict namespace
using namespace std;

namespace sict {

	// Definition for display(...) 

	void display(const Kingdom& rKingdom) {

		cout << rKingdom.m_name << ", population " << rKingdom.m_population << endl;

	}


	// Definition of the Overloaded Function 
	void display(const Kingdom aKingdomOne[], int size) {

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		int tot_pop = 0;
		int i;

		for (i = 0; i < size; i++) {

			tot_pop += aKingdomOne[i].m_population;

			cout << i + 1 << ". ";

			sict::display(aKingdomOne[i]);

		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << tot_pop << endl;
		cout << "------------------------------" << endl;
	}
}