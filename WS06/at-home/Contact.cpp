	/***********************************************************
// OOP244 Workshop 6_Home:
// File Contact.cpp
// Version 1.0
// Date 10/24/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Class with a Resource
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include <cstring>
#include "Contact.h"


using namespace std;

namespace sict {

	// Implement Default Constructor
	Contact::Contact() {
		a_nameCont[0] = '\0';
		p_PhoneNum = nullptr;
		numbersPhoneNum = 0;
	}

	// Implement of the private function to validate the Phone Numbers
	bool Contact::isValidPhone(long long phoneVal) {

		int phoneNumber = (phoneVal % 10000000);
		int areaCode = (phoneVal / 10000000) % 1000;
		long long countryCode = (phoneVal / 10000000000);

		return (phoneNumber >= 1000000 && areaCode >= 100 && countryCode >= 1 &&
			countryCode <= 99);
	}

	//Implementation of Custructor with three parameters
	Contact::Contact(const char* nameContact, const long long* phoneNums, short count) {


		if (nameContact != nullptr && strcmp(nameContact, "") != 0) {

			numbersPhoneNum = 0;

			strcpy(a_nameCont, nameContact);

			/*for (int i = 0; i < size; i++) {
			a_nameCont[i] = nameContact[i];

			}*/

			a_nameCont[19] = '\0';
			p_PhoneNum = new long long[count];

			for (int i = 0; i < count; i++) {

				if (isValidPhone(phoneNums[i])) {
					p_PhoneNum[numbersPhoneNum] = phoneNums[i];
					numbersPhoneNum++;
				}
			}
		}
		else
		{
			*this = Contact();
		}
	}

	//Implementation of the default Contruct
	Contact::~Contact() {

		delete[] p_PhoneNum;
		p_PhoneNum = nullptr;

	}

	//Implemetation of Empty function
	bool Contact::isEmpty() const {

		return (a_nameCont[0] == '\0' && p_PhoneNum == nullptr && numbersPhoneNum == 0) ? true : false;
	}

	// Implemenation Display function
	void Contact::display() const {

		if (isEmpty()) {

			cout << "Empty contact!" << endl;

		}
		else
		{
			cout << a_nameCont << endl;

			for (int i = 0; i < numbersPhoneNum; i++) {
				cout << "(+" << p_PhoneNum[i] / 10000000000 << ") ";
				cout << (p_PhoneNum[i] / 10000000) % 1000 << " ";
				cout << (p_PhoneNum[i] / 100) % 100000 / 100 << "-";
				cout.width(4);
				cout.fill('0');
				cout << (p_PhoneNum[i] % 10000) << endl;
			}
		}
	}
	// Implemetation of copy Contruct
	Contact::Contact(const Contact& cpyStr) {

		p_PhoneNum = nullptr;
		*this = cpyStr; // call the assigment operator
	}
	// Implementation of assignment operator
	Contact& Contact::operator=(const Contact& cpyAss)
	{

		if (this != &cpyAss)  // protect against invalid self-assignment
		{

			numbersPhoneNum = cpyAss.numbersPhoneNum; // shallow copy
			strcpy(a_nameCont, cpyAss.a_nameCont); // shallow copy
			delete[] p_PhoneNum;

			if (nullptr != cpyAss.p_PhoneNum) {

				p_PhoneNum = new long long[numbersPhoneNum]; // allocate memory 

				for (int i = 0; i < numbersPhoneNum; i++) {

					p_PhoneNum[i] = cpyAss.p_PhoneNum[i]; // deep copy
				}
			}
			else
			{
				p_PhoneNum = nullptr;
			}
		}
		return *this;
	}

	// implentation of binary operator
	Contact& Contact :: operator += (long long new_PhoneNum) {


		if (isValidPhone(new_PhoneNum) && isEmpty() == false) {

			long long* tempArr = nullptr;

			tempArr = new long long[numbersPhoneNum];

			for (int i = 0; i < numbersPhoneNum; i++) {

				tempArr[i] = p_PhoneNum[i];
			}

			delete[] p_PhoneNum;
			p_PhoneNum = new long long[numbersPhoneNum + 1];

			for (int i = 0; i < numbersPhoneNum; i++)
			{

				p_PhoneNum[i] = tempArr[i];

			}

			p_PhoneNum[numbersPhoneNum] = new_PhoneNum;
			numbersPhoneNum++;

			delete[] tempArr;
			
		}

		else
		{
			p_PhoneNum[numbersPhoneNum] = new_PhoneNum;
		}

		return *this;
		
	}
} // namespace sict







