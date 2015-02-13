#include "Fighter.h"


Fighter::Fighter(string name, int MHP, int strength, int speed, int magic)// Is this a valid constructor?
{
		Name = name;
		MaximumHP = MHP;
		CurrentHP = MHP;
		Strength = strength;
		Speed = speed;
		Magic = magic;
}
Fighter::~Fighter(void)
{
}
string Fighter::getName()
{
return Name;
}
int Fighter::getMaximumHP()
{
return MaximumHP;
}
int Fighter::getCurrentHP()
{
return CurrentHP;
}
int Fighter::getStrength()
{
return Strength;
}
int Fighter::getSpeed()
{
return Speed;
}
int Fighter::getMagic()
{
return Magic;
}
//int getDamage() = 0;//calling damage a fighter can cause//do not include in Cpp at the Fighterlevel

void Fighter::takeDamage(int damage)
{
	int DamageTaken = damage - (Speed/4);
	if (DamageTaken <= 1)
	{
	DamageTaken = 1;
	}
	CurrentHP -= DamageTaken;
}
void Fighter::reset()
{
CurrentHP = MaximumHP;
}
void Fighter::regenerate()
{
	int AmountToRegenerate = (Strength/6);
	if (AmountToRegenerate <= 1)
	{
		AmountToRegenerate = 1;
	}

	if (AmountToRegenerate + CurrentHP > MaximumHP)
	{
		CurrentHP = MaximumHP;
	}
	else 
	{
		CurrentHP += AmountToRegenerate;
	}
}
