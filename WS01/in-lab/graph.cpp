/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseneca.ca
Assignment: WorkshopHome1
Section:A
Due date:09/20/2017 11:59
*/

#include <iostream>
#include "graph.h"
#include "tools.h"
using namespace std;

namespace sict {

	// Definition of getSamples Function 
	void getSamples(int samples[], int noOfSamples) {

		int i;
		for (i = 0; i < noOfSamples; i++) {
			cout << (i + 1) << "/" << noOfSamples << ": ";
			samples[i] = getInt(1, 1000000);
		}
	}

	// Definition of getSamples Function
	int findMax(int samples[], int noOfSamples) {

		int max = samples[0];
		int i;
		for (i = 1; i < noOfSamples; i++) {
			if (max < samples[i]) max = samples[i];
		}
		return max < 70 ? 70 : max;
	}

	// Definition of printBar Function
	void printBar(int val, int max) {

		int i;
		for (i = 0; i < 70 * val / max; i++) {
			cout << "*";
		}
		cout << " " << val << endl;
	}

	// Definition of printGraph Function
	void printGraph(int samples[], int noOfSamples) {

		int max = findMax(samples, noOfSamples);
		cout << "Graph:" << endl;
		for (int i = 0; i < noOfSamples; i++) {
			printBar(samples[i], max);
		}
	}
}