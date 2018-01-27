/***********************************************************
// OOP244 Workshop 2.Home: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date 09/26/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description : practice in allocating and deallocating dynamic memory
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H


// Defined namespace and struct with its data member
namespace sict {


	struct Kingdom {

		char m_name[32];
		int m_population;

	};


	// Declaration of Display function prototype
	void display(const Kingdom &rKingdom);

	// Overloded Display(..)

	void display(const Kingdom[], int size);

}
#endif // !KINGDOM
