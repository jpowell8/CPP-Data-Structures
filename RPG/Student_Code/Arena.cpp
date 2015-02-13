#include "Arena.h"

Arena::Arena(void)
{
}
Arena::~Arena(void)
{
}
bool Arena::addFighter(string info)
{
	string name = "";
	string type;
	int MHP;
	int strength;
	int speed;
	int magic;
	int test= 99;

	stringstream ss(info);
	
	
	if(ss>>name>>type>>MHP>>strength>>speed>>magic)
	{
	/*//cout << "contents of name " << name << endl;
	//cout << "contents of type " << type << endl;
	//cout << "contents of MPH " << MHP << endl;
	//cout << "contents of strength " << strength << endl;
	//cout << "contents of speed " << speed << endl;
	//cout << "contents of  magic" << magic << endl;
*/
	if(!ss.eof())
	{return false;}


	for(int i = 0; i < allFighters.size(); i++)
	{
		//cout << i << " " << allFighters[i]->getName();		
	}

	for(int i = 0; i < allFighters.size(); i++)
	{
		if (name == allFighters[i]->getName())
		{
			//cout << "Name " << name << " already exists"<< endl;
		return false;
		}
	}

	if (MHP <= 0)
	{
		return false;
	}

	if (strength <= 0)
	{
		return false;
	}

	if (speed <= 0)
	{
		return false;
	}

	if (magic <= 0)
	{
		return false;
	}

	if (type == "A")
	{	
		//cout << "About to make Archer" <<endl;
		allFighters.push_back(new Archer(name, MHP, strength, speed, magic));
		//cout << "Archer should be created" <<endl;
		return true;
	}

	if(type == "R")
	{	
		//cout << "About to make Robot" <<endl;
		allFighters.push_back(new Robot(name, MHP, strength, speed, magic));
	//cout << "Robot should be created" <<endl;
		return true;
	}
	if(type == "C")
	{
		//cout << "About to make Cleric" <<endl;
		allFighters.push_back(new Cleric(name, MHP, strength, speed, magic));
		//cout << "Cleric should be created" <<endl;
	return true;
	}


	return false;
	}
	//else{allFighters.popback()}
	return false;
}
bool Arena::removeFighter(string name)
{
	bool dropped = false;
	for(int i = 0; i < allFighters.size(); i++)
	{
		if (name == allFighters[i]->getName())
		{
		allFighters.erase(allFighters.begin()+i);////Is calling .erase on the fighter which is not a valid method

		dropped = true;
		}
	}
	return dropped;
}
FighterInterface* Arena::getFighter(string name) //FighterInterface*
{
	for(int i = 0; i < allFighters.size(); i++)//If Fighter is found return fighter
	{
		if (name == allFighters[i]->getName())
		{
		return allFighters[i];
		}
	}
		return NULL;//Else return NULL
}
int Arena::getSize()
{
	return allFighters.size(); //whatever the name of the vector is
}

//Most inportant thing to understand is how the Arena Works, and why we inherit from an arena interface. 