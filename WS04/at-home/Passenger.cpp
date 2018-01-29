/***********************************************************
// OOP244 Workshop 4_Lab:
// File Passenger.cpp
// Version 1.0
// Date 10/10/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Default Construct and Contruct with parameters
///////////////////////////////////////////////////////////
***********************************************************/

//add your headers here

#include <cstring>
#include <iostream>
#include "Passenger.h"

using namespace std;

namespace sict {

	//implement the default constructor here
	Passenger::Passenger() {
		cout << "default contruct" << endl;

		// Empty safe state of char arrays
		name_Pass[0] = '\0';
		destination[0] = '\0';
		// Empty safe state of int
		depYear = 0;
		depMonth = 0;
		depYear = 0;

	}

	//implement the constructor with 2 parameters here
	Passenger::Passenger(const char nameOne[], const char destinationOne[]) {

		//String compare Return 0 if the string are egual
		if (nameOne != nullptr && destinationOne != nullptr && strcmp(nameOne, "") != 0 && strcmp(destinationOne, "") != 0) 
		{

			strncpy(name_Pass, nameOne, MAX_LENGTH);
			// strncpy uses 3 parameters ( dest, source, max lenght) + set the last index of the string = \0;
			name_Pass[MAX_LENGTH -1] = '\0';
			strncpy(destination, destinationOne, MAX_LENGTH);
			destination[MAX_LENGTH -1] = '\0';
			depDay = 1;
			depMonth = 7;
			depYear = 2017;
		}
		else
		{
			*this = Passenger();
		}

	}

	//implement isEmpty query here
	bool Passenger::isEmpty()const {

		return (name_Pass[0] == '\0');
	}

	// Implementation of Construct with 5 parameters
	Passenger::Passenger(const char *passName, const char *passDest, int depYearOne, int depMonthOne, int depDayOne) {

		cout << "5 argument -  contruct" << endl;

		if (passName != nullptr && passDest != nullptr && strlen(passName) != 0 && strlen(passDest) != 0
			&& depYearOne >= 2017 && depYearOne <= 2020 && depMonthOne >= 1 && depMonthOne <= 12
			&& depDayOne >= 1 && depDayOne <= 31) {

			strncpy(name_Pass, passName, MAX_LENGTH);
			name_Pass[MAX_LENGTH -1] = '\0';
			//strcpy(name_Pass, passName); 
			strncpy(destination, passDest, MAX_LENGTH);
			destination[MAX_LENGTH -1] = '\0';
			//strcpy(destination, passDest);
			depYear = depYearOne;
			depMonth = depMonthOne;
			depDay = depDayOne;
		}
		else
		{
			*this = Passenger();
		}
	}

	// Implementation of query function that return the address of an empty String
	const char* Passenger::name() const {

		return name_Pass;
	}

	// Implementation of query function that retun a bool value
	bool Passenger::canTravelWith(const Passenger& travel) const {

		return (strcmp(destination, travel.destination) == 0
			&& (depDay == travel.depDay)); // if the condition is TRUE it returns TRUE If the condition is FALSE return FALSE
	}

	//Implementation display query here
	void Passenger::display()const {

		if (isEmpty() == false) {

			cout << name_Pass << " - " << destination << " on " << depYear << "/";

			cout.width(2);
			cout.fill('0');
			cout << depMonth << "/" << depDay << endl;
		}
		else
		{
			cout << "No passenger!" << endl;
		}
	}
};


