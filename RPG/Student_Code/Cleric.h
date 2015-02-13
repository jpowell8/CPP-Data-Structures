#pragma once
#include "Fighter.h"

class Cleric : public Fighter
{
public:
	Cleric(string name, int MHP, int strength, int speed, int magic);
	virtual void regenerate();
	virtual int getDamage();
	bool useAbility();
	void reset();
	~Cleric(void);
protected:
	int Mana;
};

