#pragma once
#include "Fighter.h"
#include<math.h>

class Robot : public Fighter
{
public:
	Robot(string name, int MHP, int strength, int speed, int magic);
	virtual int getDamage();
	~Robot(void);
	bool useAbility();
	void reset();
protected:
	int Energy;
	int BonusDamage;
	int MaxEnergy;
};

