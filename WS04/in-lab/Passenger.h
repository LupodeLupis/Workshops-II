/***********************************************************
// OOP244 Workshop 4_Lab:
// File Passenger.h
// Version 1.0
// Date 10/05/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Constructor default and with parameters
///////////////////////////////////////////////////////////
***********************************************************/


//add file header comments here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	class Passenger {

		char name[32];
		char destination[32];

	public:
		//implement the default constructor here
		Passenger();
		Passenger( const char[], const char[]);
		bool isEmpty()const;
		void display()const;
	};
}

#endif // !SICT_PASSENGERS_H