#pragma once
#include"ArenaInterface.h"
#include"FighterInterface.h"
#include"Cleric.h"
#include"Archer.h"
#include"Robot.h"
#include"Fighter.h"
#include<vector>
#include <sstream>

class Arena : public ArenaInterface
{
public:
	Arena();
	bool addFighter(string info);
	bool removeFighter(string name);
	virtual FighterInterface* getFighter(string name);
	int getSize();
	virtual ~Arena();

protected:
	vector<FighterInterface*> allFighters;

};

