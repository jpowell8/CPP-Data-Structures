#pragma once
#include <string>
#include <vector>

using namespace std;

class Pair
{
public:
	Pair(string key, string suffix);
	~Pair(void);

	string Key;
	vector<string> Suffix;
};

