/***********************************************************
// OOP244 Workshop 4_Home:
// File Fraction.h
// Version 1.0
// Date 10/18/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Member operator overloads
///////////////////////////////////////////////////////////
***********************************************************/

// Header file guard
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

//Create namespace
namespace sict {

	//Define the Fraction class
	class Fraction {

		// Declare instance variables 
		int numerator;
		int denominator;

		// Declare private member functions
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;

	public:
		// Declare public member functions
		Fraction();
		Fraction(int, int);
		bool isEmpty() const;
		void display() const;

		//Declare the + operator overload Lab_Portion
		Fraction operator+(const Fraction& rhs) const;

		//Declare the overloaded operator Home_Portion
		Fraction operator*(const Fraction&) const;
		bool operator==(const Fraction&) const;
		bool operator!=(const Fraction&) const;
		Fraction& operator+=(const Fraction&);
	};

} //namespace sict

#endif 
