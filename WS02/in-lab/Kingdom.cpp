/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 09/21/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description : practise in allocating and deallocating dynamic memory
///////////////////////////////////////////////////////////
***********************************************************/


//Included the necessary headers
#include <iostream>
#include "Kingdom.h"

//The sict namespace
using namespace std;

namespace sict {

	//Definition for display(...) 

	void display(const Kingdom &rKingdom) {

		cout << rKingdom.m_name << ", population " << rKingdom.m_population << endl;

	}

	void display(const Kingdom a_Newkingdom[], int size) {

		cout << "------------------------------" << endl;

		int tot_pop = 0;
		int i;
		for (i = 0; i < size, i++;) {

			tot_pop += a_Newkingdom[i].m_population;

			cout << i + 1 << endl;

			sict::display(a_Newkingdom[i]);

		}

		cout << "Total population of all Kingdoms:" << tot_pop << endl;
		cout << "------------------------------" << endl;
	}
}
