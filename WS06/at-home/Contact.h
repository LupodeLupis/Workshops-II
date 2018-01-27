/***********************************************************
// OOP244 Workshop 6_Home:
// File Contact.h
// Version 1.0
// Date 10/24/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Class with a Resource
///////////////////////////////////////////////////////////
***********************************************************/


#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H


namespace sict {

	const char size = 20;

	class Contact {
		char a_nameCont[size];
		long long* p_PhoneNum;
		int	 numbersPhoneNum;
		bool isValidPhone(long long phoneVal);


	public:
		Contact();
		Contact(const char*, const long long*, short);
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact(const Contact&);
		Contact& operator=(const Contact&);
		Contact& operator+= (long long);


	};
} // namespace sict

#endif // !SICT_CONTACT_H


