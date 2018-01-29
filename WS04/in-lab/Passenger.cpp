/***********************************************************
// OOP244 Workshop 4_Lab: 
// File Passenger.cpp
// Version 1.0
// Date 10/05/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Constructor default and with parameters
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: add your headers here
#include <iostream>
#include <cstring>
#include "Passenger.h"


using namespace std;

namespace sict {

	//implement the default constructor here
	Passenger::Passenger() {

		// Empty state of char arrays
		name[0] = '\0' ;
		destination[0] =  '\0' ;

	}

	//implement the constructor with 2 parameters here
	Passenger::Passenger(const char nameOne[], const char destinationOne[]) {

		//String compare Return 0 if the string are egual
		if (nameOne != nullptr && destinationOne != nullptr && strcmp(nameOne, "") != 0 
			&& strcmp(destinationOne, "") != 0) {

			strcpy(this->name, nameOne);
			strcpy(this->destination, destinationOne);
		}
		else
		{
			*this = Passenger();
		}

	}

	//implement isEmpty query here
	bool Passenger::isEmpty()const {

		return (name[0] == '\0' && destination[0] == '\0') ? true : false;
	}

	//implement display query here
	void Passenger::display()const {

		if (isEmpty() == false) {

			cout << name << " - " << destination << endl;
		}

		else

		{
			cout << "No passenger!" << endl;

		}
	}
};


