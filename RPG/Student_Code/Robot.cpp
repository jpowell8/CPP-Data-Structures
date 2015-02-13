#include "Robot.h"


Robot::Robot(string name, int MHP, int strength, int speed, int magic) : Fighter(name, MHP, strength, speed, magic)
{
	Energy = (2*Magic);/////////This might need help!!!
	MaxEnergy = 2*Magic;///////////This might need help!!!!
	BonusDamage = 0;
	cout << "Robot created" << Name << speed << endl;
	cout << "contents of name " << Name << endl;
	cout << "contents of MPH " << MaximumHP << endl;
	cout << "contents of strength " << Strength << endl;
	cout << "contents of speed " << Speed << endl;
	cout << "contents of  magic" << Magic << endl;
}
int Robot::getDamage()
{

	//Do I need to include Use Abillity here?
	int AttackDamage =(Strength+BonusDamage);
	BonusDamage = 0;

	return AttackDamage;

}
void Robot::reset()
{ 
	Fighter::reset();
	Energy = (2*Magic);
	BonusDamage = 0;
}
bool Robot::useAbility()
{
	if (Energy >= ROBOT_ABILITY_COST)
	{
	BonusDamage = (Strength  * pow(((double)Energy/MaxEnergy), 4));

	Energy -= ROBOT_ABILITY_COST;
	return true;
	}
	return false;
}
Robot::~Robot(void)
{
}
