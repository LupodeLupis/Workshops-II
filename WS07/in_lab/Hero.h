/***********************************************************
// OOP244 Workshop 7_Lab:
// File Hero.h
// Version 1.0
// Date 12/08/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Derived Class and I/O
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

namespace sict {
	const int size = 40;
	const int max_round = 100;

	class Hero {

		char name[size + 1];
		int health;
		int strength;

	public:
		Hero();
		Hero(const char* name, int health, int strenght);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);

	};

	const Hero& operator*(const Hero& first, const Hero& second);

}
#endif // !SICT_HERO_H

