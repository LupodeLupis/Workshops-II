/*
Name:ALBERTO LAURENZI
Student number:150954162
Email:alaurenzi@myseneca.ca
Assignment: WorkshopHome1
Section:A
Due date:09/20/2017 11:59
*/
#ifndef NAMESPACE_GRAPH_H
#define NAMESPACE_GRAPH_H
#include <iostream>


// In this header files are listed the function prototypes and pre-processor declaration
#define MAX_NO_OF_SAMPLES 20

namespace sict{
// getSamples function prototype
void getSamples(int samples[], int noOfSamples);

// findMax function prototype
int findMax(int samples[], int noOfSamples);

// printBar function prototype
void printBar(int val, int max);

// printGraph function prototype
void printGraph(int samples[], int noOfSamples);

};

#endif