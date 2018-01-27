/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 09/21/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description : practise in allocating and deallocating dynamic memory
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H
#include <iostream>
#define SIZE 32


// Defined namespace and struct with its data member
namespace sict {


	struct Kingdom {

		char m_name[SIZE];
		int m_population;

	};


// Declaration of Display function prototype
 void display(const Kingdom &rKingdom);

// Overloded Display(..)

 void display(const Kingdom[], int size);

}
#endif // !KINGDOM
