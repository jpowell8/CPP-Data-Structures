#pragma once
#include "Fighter.h"

class Archer : public Fighter
{
public:
	Archer(string name, int MHP, int strength, int speed, int magic);
	virtual int getDamage();
	virtual bool useAbility();
	void reset();
	~Archer(void);
protected:
	int OriginalSpeed;

};

