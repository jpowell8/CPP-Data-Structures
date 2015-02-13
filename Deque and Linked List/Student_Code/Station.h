#pragma once
#include "StationInterface.h"
#include "Deque.h"
#include "queue.h"
#include "stack.h"

class Station: public StationInterface
{
public:
	Station();
	~Station(void);

		bool addToStation(int car);
		int showCurrentCar();		
		bool removeFromStation();		
		bool addToStack();		
		bool removeFromStack();		
		int showTopOfStack();		
		int showSizeOfStack();		
		bool addToQueue();		
		bool removeFromQueue();		
		int showTopOfQueue();		
		int showSizeOfQueue();		
		bool addToDequeLeft();		
		bool addToDequeRight();		
		bool removeFromDequeLeft();		
		bool removeFromDequeRight();		
		int showTopOfDequeLeft();		
		int showTopOfDequeRight();		
		int showSizeOfDeque();

private:
	stack St;
	queue Qu;
	deque Dq;
	int current;
	const static int reset = -1;
};

