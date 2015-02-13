#pragma once
#include "LinkedList.h"

class queue
{
public:
	queue(void);
	~queue(void);

	void enqueue(int car);
	int dequeue();
	bool duplicate(int car);
	int size();
	int getValue(int index);

private:
	LinkedList QuList;

};

