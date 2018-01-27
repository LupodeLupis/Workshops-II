/*
Name:ALBERTO LAURENZI
Student number:
Email:
Assignment: WorkshopHome1
Section:
Due date:09/20/2017 11:59
*/


#include <iostream>
#include "tools.h"
using namespace std;
namespace sict {
	// Definition of menu Function //
	int menu() {

		cout << "1- Number of Samples" << endl;
		cout << "2- Sample Entry" << endl;
		cout << "3- Draw Graph" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		return getInt(0, 3);
	}

	// Definition of getInt Function //
	int getInt(int min, int max) {

		int val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (val < min || val > max) {
					cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}
}
