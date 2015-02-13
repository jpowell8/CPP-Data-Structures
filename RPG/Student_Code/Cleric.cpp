#include "Cleric.h"


Cleric::Cleric(string name, int MHP, int strength, int speed, int magic): Fighter(name, MHP, strength, speed, magic)
{
	Mana = 5*Magic;
	cout << "Cleric created" << Name << speed << endl;
	cout << "contents of name " << Name << endl;
	cout << "contents of Mana " << Mana << endl;
	cout << "contents of MPH " << MaximumHP << endl;
	cout << "contents of strength " << Strength << endl;
	cout << "contents of speed " << Speed << endl;
	cout << "contents of  magic" << Magic << endl;
}
void Cleric::regenerate()
{ Fighter::regenerate();
//Also increases a Cleric's current mana by an amount equal to one fifth of the 
	//	 *	Cleric's magic.  This method must increase the Cleric's current mana by at 
		// *	least one.  Do not allow the current mana to exceed the maximum mana.

	int ManaIncrease = ((double)Magic/5);
	if (ManaIncrease < 1)
	{
		ManaIncrease = 1;
	}
	
	if (ManaIncrease + Mana >=  5*Magic)
	{
		Mana = 5*Magic;
	}
	else
	{
		Mana += ManaIncrease;
	}
}
bool Cleric::useAbility()
{
	if (Mana >= CLERIC_ABILITY_COST)
	{
	int AmountToRegenerate = (Magic/3);
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

	Mana -= CLERIC_ABILITY_COST;
	return true;
	}

	return false;
}
int Cleric::getDamage()
{
	int AttackDamage = Magic;
	return AttackDamage;
}
void Cleric::reset()
{
	Fighter::reset();
	Mana = (5*Magic);
}
Cleric::~Cleric(void)
{
}
