/***********************************************************
// OOP244 Workshop 5_Lab:
// File Fraction.cpp
// Version 1.0
// Date 10/12/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Member operator overloads
///////////////////////////////////////////////////////////
***********************************************************/


//Insert header files
#include <iostream>
#include"Fraction.h"

using namespace std;
//Continue the namespace

namespace sict {

	//Implement the default constructor
	Fraction::Fraction() {

		numerator = 0;
		denominator = 0;

	}
	//Implement the two-argument constructor
	Fraction::Fraction(int numOne, int denOne) {

		if (denOne > 0 && numOne > 0) {

			numerator = numOne;
			denominator = denOne;
			reduce();
		}
		else
		{
			*this = Fraction();
		}	
	}

	//Implement the max query
	int Fraction::max()const {

		// Return the greater between the denominator and numerator
		return (denominator > numerator) ? denominator : numerator;

	}
	//Implement the min query
	int Fraction::min() const {

		// Return the lesser between the denominator and numerator
		return ( denominator > numerator) ?  numerator : denominator;
	}

	// gcd returns the greatest common divisor of num and denom
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	//Implement the reduce modifier	
	void Fraction::reduce() {
		
		// store value the return vale of the function  gcd() and divide the num and den with it.
		int redGcd = gcd();	
		numerator /= redGcd;
		denominator /= redGcd;
	}

	//Implement the display query
	void Fraction::display() const {

		// Display if the Object contain data and denominato is not equal to 1
		if (isEmpty() == false && denominator != 1) {

			cout << numerator << "/" << denominator;
		}

		// Display if the Object contains data and the denominator is equal to 1
		else if (isEmpty() == false && denominator == 1) {

			cout << numerator;
		}
		else if 

			(isEmpty()) {

			cout << "no fraction stored" ;
		}
	}

	// Implement the isEmpty query
	bool Fraction::isEmpty() const {

		return (denominator > 0 && numerator > 0) ? false : true;

	}

	//Implement the + operator
	Fraction Fraction::operator+(const Fraction& rhs) const {

		if (this->isEmpty() == false && rhs.isEmpty() == false) {

			//Create a new temporaty object
			Fraction Temp;
			
			// Apply the formula of addition between two fractions
			Temp.numerator = (this->numerator * rhs.denominator) + (this->denominator * rhs.numerator);
			Temp.denominator = (this->denominator * rhs.denominator);
			Temp.reduce();

			return Temp;
		}

		else {
			//Return the Object as safe empty state
			return Fraction();
		}
	}
};