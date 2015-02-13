#include "Pathfinder.h"



Pathfinder::Pathfinder(void)
{
	//int x;
	//int y;
	//int z;
	//Maze[5][5][5] = {{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}},{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}},{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}},{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}},{{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}}};

	
	int a=0;
	int b=0;
	int c=0;
	while(c<5){
		while(b<5){
		while(a<5)
		{
		Maze[a][b][c] = 1;
		TestMaze[a][b][c] = 1;
		a++;
		}
		a=0;
		b++;
	}
		b=0;
		c++;
	}
	
	(srand(time(0)));




}


Pathfinder::~Pathfinder(void)
{
}

int X = 0;
int Y = 0;
int Z = 0;
vector<string> path;
stack<string> st;

int Pathfinder::string_to_int(string s)
{

	//std::string myString = "45";
	//int value = atoi(myString.c_str()); //value = 45 
	//
	string myString = s;
	int value = atoi(myString.c_str());
	return value;
}
string Pathfinder::int_to_string(int n)
{
	ostringstream strm;
	strm << n;
	return strm.str();
}

//Part 1-----------------------------------------------------------------------------------
		/* 
		 * getMaze
		 * 
		 * Returns a string representation of the current maze. Returns a maze of all 1s if no maze
		 * has yet been generated or imported.
		 * 
		 * A valid string representation of a maze consists only of 125 1s and 0s (each separated 
		 * by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must 
		 * also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
		 *
		 * Cell (0, 0, 0) is represented by the first number in the string representation of the 
		 * maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
		 * number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the 
		 * sixth number. Increasing in z means moving downward to a new grid, meaning cell 
		 * (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
		 *
		 * Returns:		string
		 *				A single string representing the current maze
		 */
string Pathfinder::getMaze()
{

	//cout << "Maze[0][0][0] is " << Maze[0][0][0]<< endl;
	string MAZE = "";
	int x=0;
	int y=0;
	int z=0;
	while(z<5)
	{ 
		//cout << "Maze[x][y][z] is " << Maze[x][y][z]<< endl;
		while(y<5)
		{
		//	cout << "Maze[x][y][z] is " << Maze[x][y][z]<< endl;
		while(x<5)
		{
		//cout << "Maze[x][y][z] is " << Maze[x][y][z]<< endl;
		MAZE +=	int_to_string(Maze[x][y][z]);
		if((x<=4||y<=3||z<=4)&&x<4){MAZE += " ";}
		
		//if(y==4&&z==4){MAZE += " \n";}
		//if(y==4||z==4){MAZE += endl;;}
		x++;
		}
		//Maze += "\n";
		if(1){MAZE += "\n";}
		x=0;
		y++;
	}
		if(y!=4&&z<4){MAZE += "\n";}
		//Maze += "\n";
		y=0;
		z++;

	}

//cout << " MAZE Value is " << MAZE << endl;
	return MAZE;
}
		
		/* 
		 * createRandomMaze
		 * 
		 * Generates a random maze and stores it as the current maze.
		 * 
		 * The generated maze must contain a roughly equal number of 1s and 0s and must have a 1 
		 * in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be 
		 * solvable or unsolvable, and this method should be able to produce both kinds of mazes.
		 */
void Pathfinder::createRandomMaze()
{
	int d=0;
	int e=0;
	int f=0;
	while(f<5){
		while(e<5){
		while(d<5)
		{
		Maze[d][e][f] = (rand() % 2);
		d++;
		}
		d=0;
		e++;
	}
		e=0;
		f++;
	}
	Maze[0][0][0] = 1;
	Maze[4][4][4] = 1;

	//srand(time(0))%1;
	return;
}
		//-----------------------------------------------------------------------------------------

		//Part 2-----------------------------------------------------------------------------------
		/* 
		 * importMaze
		 * 
		 * Reads in a maze from a file with the given file name and stores it as the current maze.  
		 * Does nothing if the file does not exist or if the file's data does not represent a valid
		 * maze.
		 * 
		 * The file's contents must be of the format described above to be considered valid.
		 * 
		 * Parameter:	file_name
		 *				The name of the file containing a maze
		 * Returns:		bool
		 *				True if the maze is imported correctly; false otherwise
		 */
bool Pathfinder::importMaze(string file_name)
{
	/*
	bool ExpressionManager::isBalanced(string expression){

	stringstream  s(expression);
	string token;
	stack<string> st;
	string top = "";
	while(s>>token)



	stringstream iss;
while(getline(file, line))
{
    iss << line;
    while(getline(iss,word, ' '))
    {

        size++;
    }

    iss.clear();
}


string s("Somewhere down the road");
    istringstream iss(s);

    do
    {
        string sub;
        iss >> sub;
        cout << "Substring: " << sub << endl;
    } while (iss);

	#include <iostream>
#include <fstream>
using namespace std;

int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}


string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

	{*/



	//int TestMaze[5][5][5];

	//cout<< "GETMAZE 1 " <<endl;
	getMaze();
	

	//cout << "FILE NAME IS " << file_name << endl;

	
	int value;
	int d=0;
	int e=0;
	int f=0;
	string data;
	int count=0;
	bool valid = false;


		string line;
		ifstream myfile (file_name);
		if (myfile.is_open())
		{
		while (getline (myfile,line) )
		{
		  valid = true;
		//string sub;
        //iss >> sub;
        //cout << "Substring: " << sub << endl;

		count++;

	//	cout << "Test line is " << line << endl;
	//string myString = data;
	//int value = atoi(myString.c_str());
	//cout << "value is " << value << endl;


		stringstream ss(line);

		while(ss >> data){

	//		cout << "Line 273 Data = " << data << endl;

			if (data != "0" && data != "1"){
	//		cout << "TestData(string) not 0 or 1, INVALID" << data << endl;
			return false;}

		value = string_to_int(data);
		
		if (value != 0 && value != 1){
	//		cout << "TestValue not 0 or 1, INVALID" << value << endl;
			return false;}

		if(d<4)
		{
			TestMaze[d][e][f] = value;
			d++;
		}
		else if(d==4&&e<4)
		{
		TestMaze[d][e][f] = value;
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
		TestMaze[d][e][f] = value;
			d=0;
			e=0;
			f++;
		}
		}
		}
		myfile.close();
		}
		if (valid==false||count<25||count>31)
		{
	//		cout << "Didnt read anything from the file" << endl;
			return false;
		}

		if(value==0){
		//cout << "AAAAAAAAAAHHHHHHHHHHHHHHH" << endl;
		return false;
		}

		//cout << "count is " << count << endl;
	if (count < 25 || count >31){
		//cout << "Returning false because the count is wrong" << endl;
		return false;}


	if(TestMaze[0][0][0] == 0){
		//cout << "            I AM DECLARING THAT " << file_name << " IS INVALID BECAUSE OF THE 000 ELEMENT ==0" << endl;
		return false;}
	
	if(TestMaze[4][4][4] == 0){
		//cout << "            I AM DECLARING THAT " << file_name << " IS INVALID BECAUSE OF THE 444 ELEMENT ==0" << endl;
		return false;}
	//if(TestMaze[3][4][4]==0&&TestMaze[4][3][4]==0&&TestMaze[4][4][3]==0){
	//	cout << "            I AM DECLARING THAT " << file_name << " IS INVALID BECAUSE OF a super specific case that I shouldnt need to check for" << endl;
	//	return false;}

	//cout<< "GETMAZE 2 " <<endl;
	getMaze();





















	////Copy the supposedly valid maze over

		d=0;
		e=0;
		f=0;

		while(d!=4||e!=4||f!=4){
		if(d<4)
		{
			Maze[d][e][f] = TestMaze[d][e][f];
			d++;
		}
		else if(d==4&&e<4)
		{
		Maze[d][e][f] = TestMaze[d][e][f];
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
		Maze[d][e][f] = TestMaze[d][e][f];
			d=0;
			e=0;
			f++;
		}
		}



		//cout<< "GETMAZE 3 " <<endl;
	getMaze();






		/*

	cout << "FILE NAME IS " << file_name << endl;

	
	value=0;
	d=0;
	e=0;
	f=0;
	data;
	//count=0;


		/////string line;
		/////ifstream 
			//myfile(file_name);
		if (1)///////(myfile.is_open())
		{
		while ( getline (myfile,line) )
		{
		  
		//string sub;
        //iss >> sub;
        //cout << "Substring: " << sub << endl;

		count++;

		cout << "line is " << line << endl;
	//string myString = data;
	//int value = atoi(myString.c_str());
	//cout << "value is " << value << endl;


		stringstream ss(line);

		while(ss >> data){
			if (data != "0" && data != "1"){
			cout << "Data(string) not 0 or 1, INVALID" << data << endl;
			return false;}

		value = string_to_int(data);
		
		if (value != 0 && value != 1){
			cout << "Value not 0 or 1, INVALID" << value << endl;
			return false;}

		if(d<4)
		{
			Maze[d][e][f] = value;
			d++;
		}
		else if(d==4&&e<4)
		{
		Maze[d][e][f] = value;
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
		Maze[d][e][f] = value;
			d=0;
			e=0;
			f++;
		}
		}
		}
		myfile.close();
		}

		*/
	
/*
	cout << "s is " << iss << endl;

	while(iss)
	{

		string sub;
        iss >> sub;
        cout << "Substring: " << sub << endl;

		count++;

		//cout << "data is " << data << endl;
	//string myString = data;
	//int value = atoi(myString.c_str());
	//cout << "value is " << value << endl;
		value = string_to_int(sub);
		
		if(d<4)
		{
			Maze[d][e][f] = value;
			d++;
		}
		else if(d==4&&e<4)
		{
		Maze[d][e][f] = value;
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
		Maze[d][e][f] = value;
			d=0;
			e=0;
			f++;
		}

	}

	*/
	
	//cout << "count is " << count << endl;
	//if (count < 25 || count >31){return false;}
	//if(Maze[0][0][0] != 1 || Maze[4][4][4] != 1){return false;}

	
	return true;
	
	
	
	//return false;
}
		//-----------------------------------------------------------------------------------------

		//Part 3-----------------------------------------------------------------------------------
		/* 
		 * solveMaze
		 * 
		 * Attempts to solve the current maze and returns a solution if one is found.
		 * 
		 * A solution to a maze is a list of coordinates for the path from the entrance to the exit
		 * (or an empty vector if no solution is found). This list cannot contain duplicates, and 
		 * any two consecutive coordinates in the list can only differ by 1 for only one 
		 * coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included 
		 * in the solution. Each string in the solution vector must be of the format "(x, y, z)", 
		 * where x, y, and z are the integer coordinates of a cell.
		 *
		 * Understand that most mazes will contain multiple solutions
		 * 
		 * Returns:		vector<string>
		 *				A solution to the current maze, or an empty vector if none exists
		 */





bool Pathfinder::solver(int X, int Y, int Z)
{
	if(X<0||Y<0||Z<0||X>4||Y>4||Z>4){return false;}
	if(Maze[X][Y][Z]==2){return false;}
	//cout << "entering solver" << endl;

	string stuff;
	int j;

	if(X<0||Y<0||Z<0||X>4||Y>4||Z>4){return false;}

	if(Maze[X][Y][Z]==0){return false;}
	
	if(X==4&&Y==4&&Z==4&&Maze[4][4][4]==1){
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		//j=path.begin();
		st.push(stuff);
		return true;}
	if(X==4&&Y==4&&Z==4&&Maze[4][4][4]==0){return false;}

	Maze[X][Y][Z]=2;

	if(solver(X+1, Y, Z))
	{
		//cout << "x+1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}
	if(solver(X-1, Y, Z))
	{
		//cout << "x-1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}
	if(solver(X, Y+1, Z))
	{
//cout << "y+1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}
	if(solver(X, Y-1, Z))
	{
		//cout << "y-1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}
	if(solver(X, Y, Z+1))
	{
		//cout << "z+1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}
	if(solver(X, Y, Z-1))
	{
		//cout << "z-1" << endl;
		stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
		//cout << "stuff is  "<< stuff << endl;
		st.push(stuff);
		return true;
	}

	return false;


}

/*	
void Pathfinder::solver(int X, int Y, int Z){


	
		




	


	cout << "Entered solver function" << endl;
	cout << "X Y Z are " << X << Y << Z << endl;
	//cout << "Entered solver function" << endl;
	//cout << "Entered solver function" << endl;

	string stuff = "";

	//BASE CASES

	if(X==4&&Y==4&&Z==4){
	//	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	//path.push_back (stuff);
		return;}

	if(Maze[0][0][0]==0){return;}
	if(Maze[4][4][4]==0){return;}

	if(X<0||X>4||Y<0||Y>4||Z<0||Z>4){return;}


	if(X<4){
	if(Maze[X+1][Y][Z]==1)//recreate for all cases
	{
		cout << "Looking right" << endl;

	Maze[X][Y][Z]=2;
	X += 1;//maybe want to put before stuff statement
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	
	solver(X, Y, Z);
	return;
	}
	}


	if(Y<4){
	if(Maze[X][Y+1][Z]==1)//recreate for all cases
	{
		cout << "looking down" << endl;

	Maze[X][Y][Z]=2;
	Y += 1;
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	solver(X, Y, Z);
	return;
	}
	}

	if(Z<4){
	if(Maze[X][Y][Z+1]==1)//recreate for all cases
	{
		cout << "looking back" << endl;

	Maze[X][Y][Z]=2;
	Z += 1;
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	solver(X, Y, Z);
	return;
	}
	}


	if(X>0){
	if(Maze[X-1][Y][Z]==1)//recreate for all cases
	{
		cout << "looking left" << endl;

	Maze[X][Y][Z]=2;
	X -= 1;
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	solver(X, Y, Z);
	return;
	}
	}


	if(Y>0){
	if(Maze[X][Y-1][Z]==1)//recreate for all cases
	{
		cout << "looking up" << endl;

	Maze[X][Y][Z]=2;
	Y -= 1;
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	solver(X, Y, Z);
	return;
	}
	}


	if(Z>0){
	if(Maze[X][Y][Z-1]==1)//recreate for all cases
	{
	cout << "looking forward" << endl;
		
	Maze[X][Y][Z]=2;
	Z -= 1;
	stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
	path.push_back (stuff);
	solver(X, Y, Z);
	return;
	}
	}
	//i AM DELIBERATING RETURNING SOLVER(XYZ), IT CHANGES A GLOBAL VARIABLE, i GUESS I WILL WATCH IT GO FIRST

	if(X==4&&Y==4&&Z==4){return;}
	if(X==0&&Y==0&&Z==0){
		path.clear();
		return;}

	Maze[X][Y][Z]=0;
	Maze[0][0][0]=2;
	path.clear();
	
	solver(0, 0, 0);

	return;


	/*
vector<string> test;
//vector<string> path;
string stuff;


if(Maze[0][0][0]==0&&Maze[1][0][0]!=1&&Maze[0][1][0]!=1&&Maze[0][0][1]!=1)
{
	cout << "Maze000 =0" << endl;

	return false;
}

if(X<0||Y<0||Z<0)
{
///out of lower bounds
//test.clear();
	cout << "out of lower bounds" << endl;

return false;
}
if(X>4||Y>4||Z>4)
{
cout << "out of upper bounds" << endl;
//test.clear();
return false;
}
if(X==4&&Y==4&&Z==4&&Maze[X][Y][Z]==1)
{
	cout << "reached the final square, maze should be solved now" << endl;

stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
	return true;
}




//LOOK IN ALL DIRECTIONS RECURSIVELY be aware of edge cases
//left x-1
if (X>0)
{
	cout << "XYZ are " << X << Y << Z << endl;
if(Maze[X-1][Y][Z]==1)
{
	Maze[X][Y][Z]=2;
	return solver(X-1,Y,Z);

X -= 1; 
cout << "Case 1 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
}
//else//Eliminate going down a dead end path by assigning zeros to failed paths
//{
//Maze[X-1][Y][Z]=4;
//}
}

//right x+1
if (X<4)
{
	cout << "2XYZ are " << X << Y << Z << endl;
if(Maze[X+1][Y][Z]==1)
{
	Maze[X][Y][Z]=2;
	if(solver(X+1,Y,Z))
	{
X += 1; 
cout << "Case 2 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
//solver();
}
}
//else
//{
//Maze[X+1][Y][Z]=4;
//}
}

//forward y+1
if (Y<4)
{
	cout << "3XYZ are " << X << Y << Z << endl;
if(Maze[X][Y+1][Z]==1)
{	Maze[X][Y][Z]=2;
	if (solver(X,Y+1,Z))
	{
Y += 1; 
cout << "Case 3 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
//solver();
}
}
//else
//{
//Maze[X][Y+1][Z]=4;
//}
}

//backward y-1
if (Y>0)
{
	cout << "4XYZ are " << X << Y << Z << endl;
if(Maze[X][Y-1][Z]==1)
{
	Maze[X][Y][Z]=2;
	if (solver(X,Y-1,Z))
	{
Y -= 1; 
cout << "Case 4 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
//solver();
}
}
//else
//{
//Maze[X][Y-1][Z]=4;
//}
}

//down z-1
if (Z>0)
{
	cout << "5XYZ are " << X << Y << Z << endl;
if(Maze[X][Y][Z-1]==1)
{
	Maze[X][Y][Z]=2;
	if (solver(X,Y,Z-1))
	{
Z -= 1; 
cout << "Case 5 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
//solver();
}
}
//else
//{
//Maze[X][Y][Z-1]=4;
//}
}

//up z+1
if (Z<4)
{
	cout << "6XYZ are " << X << Y << Z << endl;
if(Maze[X][Y][Z+1]==1)
{
Maze[X][Y][Z]=2;
	if (solver(X,Y,Z+1))
	{
Z += 1; 
cout << "Case 6 assign to 2" << endl;

//Maze[X][Y][Z]=2;
stuff = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
path.push_back (stuff);
//solver();
}
}
//else
//{
//Maze[X][Y][Z+1]=4;
//}
}
*/
//Maze[X][Y][Z]=3;

//	X=0;
//	Y=0;
//	Z=0;
//Maze[X][Y][Z]=1;

//cout << "Reached end of solver function about to return solver" << endl;

//if(solver(X,Y,Z)==false){return false;}



//if(X!==4||Y!==4||Z!==4)
//{
//It did not get to the end of the maze return false
//test.clear();
//return test;
//}


		 
vector<string> Pathfinder::solveMaze()///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{
//	cout << "Beginnig MazeSolve" << endl;

/*
if the program wants me to find a path through the maze without altering the maze I think I will need to copy 
the maze using an inverse of the copy function I am pasting below

Also I will need to define another function which will actually solve the maze so that I can encorporate my 
function copying without it copying everytime I call the solve function recursively

////Copy the supposedly valid maze over

		d=0;
		e=0;
		f=0;

		while(d!=4||e!=4||f!=4){
		if(d<4)
		{
		TestMaze[d][e][f] = Maze[d][e][f];
			d++;
		}
		else if(d==4&&e<4)
		{
		TestMaze[d][e][f] = Maze[d][e][f];
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
		TestMaze[d][e][f] = Maze[d][e][f];
			d=0;
			e=0;
			f++;
		}
		}





*/

//vector<string> path;

//path.push_back( "(0, 0, 0)");

path.clear();
while(!st.empty())
{
	st.pop();
}

//cout << "Path cleared" << endl;


X = 0;
Y = 0;
Z = 0;

//cout << "Variables assigned zero" << endl;


///if(Maze[0][0][0]==1)
///{
///	string base;
///	base = ("(" + int_to_string(X) + " ," + int_to_string(Y) + " ," + int_to_string(Z) + ")");
///	path.push_back (base);
///}

if (solver(X, Y, Z))
{

	int d=0;
		int e=0;
		int f=0;

		while(d!=4||e!=4||f!=4){
		if(d<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d++;
		}
		else if(d==4&&e<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d=0;
			e=0;
			f++;
		}
		}

		if(Maze[4][4][4]==2){
				Maze[4][4][4] = 1;}

		int p = st.size();
		for(int i = 0; i < p; i++)
		{
		path.push_back(st.top());
		st.pop();
		}


return path;
}
else{

	int d=0;
		int e=0;
		int f=0;

		while(d!=4||e!=4||f!=4){
		if(d<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d++;
		}
		else if(d==4&&e<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d=0;
			e=0;
			f++;
		}
		}

		if(Maze[4][4][4]==2){
				Maze[4][4][4] = 1;}

path.clear();
return path;
}

/*

		int d=0;
		int e=0;
		int f=0;

		while(d!=4||e!=4||f!=4){
		if(d<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d++;
		}
		else if(d==4&&e<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			e++;
			d=0;
		}
		else if(d==4&&e==4&&f<4)
		{
			if(Maze[d][e][f]==2){
				Maze[d][e][f] = 1;}
			d=0;
			e=0;
			f++;
		}
		}



return path;
//{
//	cout << "solver is apparently true, about to return path" << endl;

//	return path;
//}
//else
//{
//	cout << "solver appears false clearing path and about to return blank path" << endl;

//	path.clear();
//	return path;
//}
//vector<string> MAP = solver(X,Y,Z);
//cout << "Passed solver function returned to MazeSolve" << endl;



//BASE CASES

*/


	
	//return MAP;

}
		//-----------------------------------------------------------------------------------------