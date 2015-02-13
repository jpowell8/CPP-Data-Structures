#pragma once
#include "PathfinderInterface.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <stack>
#include <string>
#include <cctype>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;




class Pathfinder: public PathfinderInterface
{
public:
	Pathfinder(void);
	~Pathfinder(void);

		int string_to_int(string s);

		string int_to_string(int n);

	
		string getMaze();	
		void createRandomMaze();
		bool importMaze(string file_name);
		bool solver(int X, int Y, int Z);
		vector<string> solveMaze();

private:
	int Maze[5][5][5];
	int TestMaze[5][5][5];

};

