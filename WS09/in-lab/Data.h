// OOP244 Workshop 9: Function Templates
// File: Data.h
// Version: 2.0
// Date: 2017/12/15
// Author: ALBERTO LAURENZI
// Description:
// This file defines the templated functions and the answers prototype
///////////////////////////////////////////////////


#include <string>
#include <iostream>
#include <fstream>
#include<string.h>

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data
	template<typename T>
	T returnmax(const T* data, int n) {
		T t = SMALLEST_NUMBER;
		for (int i = 0; i < n; i++)
			if (data[i] > t && data[i]  < LARGEST_NUMBER)
				t = data[i];
		return t;
	}

	// min returns the smallest item in data
	template<typename T>
	T returnmin(const T* data, int n) {
		T t = LARGEST_NUMBER;
		for (int i = 0; i < n; i++)
			if (data[i] < t && data[i] > SMALLEST_NUMBER)
				t = data[i];
		return t;
	}

	// sum returns the sum of n items in data
	template<typename T>
	T returnsum(const T* data, int n) {
		T t = 0;
		for (int i = 0; i < n; i++)
			if (data[i] > SMALLEST_NUMBER && data[i] < LARGEST_NUMBER)
				t += data[i];
		return t;
	}

	// average returns the average of n items in data
	template<typename T>
	double returnavg(const T* data, int n) {
		T t = returnsum(data, n);
		return t / n;
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan
	template<typename T>
	bool read(std::istream& input, T* data, int n) {

		char c;
		for (int i = 0; i < n; i++) {
			input >> c;
			input >> data[i];
			
			if (input.fail())
				return false;
		}
		return true;
	}

	// display inserts n items of data into std::cout
	template<typename T>
	void display(const char* name, const T* data, int n) {
		if (data != nullptr) {
			std::cout.width(20);
			std::cout << name;
			for (int i = 0; i < n; i++) {
				std::cout.width(COLUMN_WIDTH);
				std::cout << data[i];
			}
			std::cout << std::endl;
		}
	};

	template<typename T>
	bool readRow(std::istream& input, const char* name, T* data, int n) {

		char rowname[2000];
		bool ok = !input.bad();

		// row format is 
		// name,1,2,3,4,5,6

		if (ok) {
			// read the name  first
			input.get(rowname, 2000, ',');
			// note: get will read a string upto the , character
			// it will leave the , character in the input buffer 

			// check that the caller is reading the correct row (name)
			// - if the user is reading the wrong row, return an error
			if (strcmp(rowname, name) != 0) {
				// wrong row
				std::cout << "Cannot parse row for " << name << std::endl;
				input.ignore(2000, '\n');
				ok = false;
			}
		}

		if (ok)
			// read the data array
			ok = read(input, data, n);

		// finish the line
		input.ignore(2000, '\n');
		return ok;
	}

	//bool readRow(std::istream& input, const char* name, int* data, int n);
	//bool readRow(std::istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

