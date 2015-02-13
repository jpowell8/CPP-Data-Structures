#pragma once
#include "LinkedList.h"


class stack
{
public:
	stack(void);
	~stack(void);

	void push(int car);
	int pop();
	bool duplicate(int car);
	int size();

private:
	LinkedList StList;

};

