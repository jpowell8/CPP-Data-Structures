#pragma once
#include "LinkedList.h"

class deque
{
public:
	deque(void);
	~deque(void);
	void insertLeft(int car);
	void insertRight(int car);
	int removeLeft();
	int removeRight();
	bool duplicate(int car);
	int size();

private:
	LinkedList DqList;


};

