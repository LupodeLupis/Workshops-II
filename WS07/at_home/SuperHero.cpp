/***********************************************************
// OOP244 Workshop 7_Home:Completed
// File SuperHero.cpp
// Version 1.0
// Date 12/12/2017
// Student: ALBERTO LAURENZI
// ID:150954162
// email:alaurenzi@myseneca.ca
// Description: Derived Class and I/O
///////////////////////////////////////////////////////////
***********************************************************/

#include "SuperHero.h"

using namespace std;
namespace sict {

	// SuperHero Deafult Destructor that call the Hero Default Construct to initialize the Base class Data Member
	SuperHero::SuperHero(): Hero()
	{
		bonus = 0;
		def_strenght_sup = 0;
	}

	// SuperHero Construct with arguments that call the Hero construct with argument to check the Base Class Data Member before accept any data
	SuperHero::SuperHero(const char* name_SHero, int healthSup, int attackSup, int bonusSup, int defStrenghtSup)
		: Hero(name_SHero,healthSup,attackSup)
	{
		if (defStrenghtSup != 0 && bonusSup != 0) {
	
			def_strenght_sup = defStrenghtSup;
			bonus = bonusSup;
		}
	}

	// The Hero member function that is shadowed by the SuperHero Member Function
	int SuperHero::attackStrength() const {return Hero::attackStrength() + this->bonus;}
		
	int SuperHero::defend() const { return def_strenght_sup; }

	const SuperHero & operator*(const SuperHero & first, const SuperHero & second)
	{
		SuperHero a = first;
		SuperHero b = second;
		const SuperHero *winner;
		int round = 0;
		bool draw = false;

		while (a.isAlive() && b.isAlive() && round < max_round)

		{
			if (a.isAlive() && b.isAlive()) {

				a -= b.attackStrength()  - a.defend();
				b -= a.attackStrength()  - b.defend();
			}
			round++;
		}
		if (a.isAlive() && b.isAlive()) {

			draw = true;
		}
		// if Hero are still alive by default the first Hero wins
		if (draw) {

			winner = &first;
		}
		else if (a.isAlive())
		{
			winner = &first;
		}
		else
		{
			winner = &second;
		}

		cout << "Super Fight! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;

		return *winner;
	}
}
