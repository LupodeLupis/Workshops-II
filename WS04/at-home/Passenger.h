/***********************************************************
// OOP244 Workshop 4_Home:
// File Passenger.h
// Version 1.0
// Date 10/10/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Default Construct and Contruct with parameters
///////////////////////////////////////////////////////////
***********************************************************/


//add file header comments here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define MAX_LENGTH  32


namespace sict {

	class Passenger {

		char name_Pass[MAX_LENGTH];
		char destination[MAX_LENGTH];
		int depYear;
		int depMonth;
		int depDay;

	public:
		//Member function implemention Lab_Portion the default constructor here
		Passenger();
		Passenger(const char[], const char[]);
		bool isEmpty()const;
		void display()const;

		//Member function implementation of Home_Portion
		Passenger(const char *passName, const char *passDest, int depYearOne, int depMonthOne, int depDayOne);
		const char* name() const; 
		bool canTravelWith(const Passenger&) const;	

	};
}

#endif // !SICT_PASSENGERS_H
