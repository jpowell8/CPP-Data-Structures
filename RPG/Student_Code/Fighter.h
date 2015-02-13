#pragma once
#include "FighterInterface.h"

class Fighter : public FighterInterface
{
public:
	Fighter(string name, int MHP, int strength, int speed, int magic);
	~Fighter(void);

		string getName();

		int getMaximumHP();

		int getCurrentHP();

		int getStrength();

		int getSpeed();

		int getMagic();

		virtual int getDamage() = 0;//calling damage a fighter can cause//do not include in Cpp at the Fighterlevel

		void takeDamage(int damage);

		virtual void reset();

		virtual void regenerate();//

		virtual bool useAbility() = 0;//

protected:
	string Name;
	int MaximumHP; //Hit Points
	int CurrentHP;
	int Strength;
 	int Speed;
 	int Magic; 
	

};

