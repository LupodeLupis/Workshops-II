/***********************************************************
// OOP244 Workshop 7_Home:Completed
// File SuperHero.h
// Version 1.0
// Date 12/12/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Derived Class and I/O
///////////////////////////////////////////////////////////
***********************************************************/

#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include <iostream>
#include "Hero.h"

namespace sict {

	class SuperHero : public Hero {


		int bonus;
		int def_strenght_sup;

	public:
		SuperHero();
		SuperHero(const char* name_SHero, int healthSup, int attackSup, int bonusSup, int defStrenghtSup);
		int attackStrength() const;
		int defend() const;

	};
	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
}
#endif // !SICT_SUPERHERO_H

