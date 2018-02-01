/***********************************************************
// OOP244 Workshop 7_Home:Completed
// File Hero.cpp
// Version 1.0
// Date 12/12/2017
// Student: ALBERTO LAURENZI
// ID:
// email:
// Description: Derived Class and I/O
///////////////////////////////////////////////////////////
***********************************************************/

#include <cstring>
#include "Hero.h"

using namespace std;
 namespace sict {
	
	Hero::Hero()
	{
		name[0] = '\0';
		strength = 0;
		health = 0;
	}

	Hero::Hero(const char * name_One, int health_One, int strength_One)
	{
		if (name_One != nullptr && health_One > 0 && strength_One > 0) {

			strcpy(name, name_One);
			health = health_One;
			strength = strength_One;
		}
		else
		{
			*this = Hero();
		}
	}

	void Hero::operator-=(int attack)
	{
		if (attack > 0)
			this->health -= attack;

		if (this - health < 0)
			this->health = 0;
	}

	bool Hero::isAlive() const
	{
		return (this->health > 0);
	}

	int Hero::attackStrength() const
	{
		return strength;
	}

	std::ostream & operator<<(std::ostream & os, const Hero & hero)
	{
		if (hero.name[0] != '\0') {
			os << hero.name;
		}
		else 
		{
			os << "No hero";
		}
		return os;
	}

	const Hero & operator*(const Hero & first, const Hero & second)
	{

		Hero a = first;
		Hero b = second;
		bool draw = false;
		int round = 0;

		const Hero *winner = nullptr;

		// check until the Hero A and Hero B are alive and round doent' reach the max.
		while (a.isAlive() && b.isAlive() && round <= max_round)
		{

			if (a.isAlive() && b.isAlive()) {
				// call the binary operator to substract the strengh of the Hero B to the health of Hero A ( the opposite in the following line).
				a -= b.attackStrength();
				b -= a.attackStrength();
			}
			round++;
		}

		// check if the Heros are both still alive
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

		cout << "Ancient Battle! " << first << " vs " << second << " : " << "Winner is " << *winner << " in " << round << " rounds." << endl;

		return *winner;
	}
}
