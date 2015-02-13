#include "Archer.h"


Archer::Archer(string name, int MHP, int strength, int speed, int magic): Fighter(name, MHP, strength, speed, magic)
{
	cout << "archer created" << Name << speed << endl;
	cout << "contents of name " << Name << endl;
	cout << "contents of MPH " << MaximumHP << endl;
	cout << "contents of strength " << Strength << endl;
	cout << "contents of speed " << Speed << endl;
	cout << "contents of  magic" << Magic << endl;
	OriginalSpeed=Speed;
}
bool Archer::useAbility()
{
Speed += 1;
return true;
}
int Archer::getDamage()
{
int AttackDamage = Speed;
return AttackDamage;
}
void Archer::reset()
{ 
	Fighter::reset();
	Speed = OriginalSpeed;
}
Archer::~Archer(void)
{
}
