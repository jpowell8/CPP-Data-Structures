#include "Station.h"


Station::Station()
{
	stack St;
	queue Qu;
	deque Dq;
	current = reset;
}
Station::~Station(void)
{
}



//Part 1--------------------------------------------------------------
		/**
		 * Let another car arrive at the station and become the current car.
		 * Do not allow a new car to arrive if any of the following conditions apply:
		 * 1.	There is already a current car
		 * 2.	The new car's ID already exists in any structure
		 * 3.	The new car's ID is negative
		 *
		 * @param car the ID of the car arriving at the station
		 * @return true if the car successfully arrived; false otherwise
		 */
bool Station::addToStation(int car)
{
	if(car<0){return false;}//checks if the car ID is negative
	if(Dq.duplicate(car)){return false;}//if there is a duplicate of that car in one of the lists
	if(St.duplicate(car)){return false;}//if there is a duplicate of that car in one of the lists
	if(Qu.duplicate(car)){return false;}//if there is a duplicate of that car in one of the lists	
	if(current>0){return false;}//checks if there is a current car already
	current = car;
	return true;
	

}

		/**
		 * Returns the ID of the current car.
		 * Return -1 if there is no current car.
		 *
		 * @return the ID of the current car; -1 if there is no current car
		 */
int Station::showCurrentCar()
{
	return current;
}

		/**
		 * Removes the current car from the station.
		 * Does nothing if there is no current car.
		 *
		 * @return true if the current car successfully left; false otherwise
		 */
bool Station::removeFromStation()
{
	if (current == -1)//if there is no car I return False because I did not remove one
	{
		return false;
	}
	if(current != -1)// set car to empty
	{
		current = -1;
		return true;
	}
}

		//Part 2--------------------------------------------------------------
		/**
		 * Adds the current car to the stack.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the stack is already full.
		 *
		 * @return true if the car is successfully added to the stack; false otherwise
		 */
bool Station::addToStack()
{
	if(current == -1){return false;}
	if(St.size() >= 5){return false;}

	St.push(current);
	current = -1;
	return true;
}

		/**
		 * Removes the first car in the stack and makes it the current car.
		 * Does nothing if there is already a current car or if the stack already empty.
		 *
		 * @return true if the car is successfully removed from the stack; false otherwise
		 */
bool Station::removeFromStack()
{
	if(current != -1){return false;}
	if(St.size() <= 0){return false;}
	
	current = St.pop();
	return true;

}

		/**
		 * Returns the ID of the first car in the stack.
		 *
		 * @return the ID of the first car in the stack; -1 if the stack is empty
		 */
int Station::showTopOfStack()
{
	if(St.size() <= 0){return -1;}//returns -1 for empty stack
	int holder = St.pop();
	St.push(holder);
	return holder;
}

		/**
		 * Returns the number of cars in the stack.
		 *
		 * @return the number of cars in the stack
		 */
int Station::showSizeOfStack()
{
	return St.size();
}

		//Part 3--------------------------------------------------------------
		/**
		 * Adds the current car to the queue.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the queue is already full.
		 *
		 * @return true if the car is successfully added to the queue; false otherwise
		 */
bool Station::addToQueue()//copied code from addtoStack check for errors
{
	if(current == -1){return false;}
	if(Qu.size() >= 5){return false;}

	Qu.enqueue(current);
	current = -1;
	return true;
}

		/**
		 * Removes the first car in the queue and makes it the current car.
		 * Does nothing if there is already a current car or if the queue already empty.
		 *
		 * @return true if the car is successfully removed from the queue; false otherwise
		 */
bool Station::removeFromQueue()
{
	if(current != -1){return false;}
	if(Qu.size() <= 0){return false;}
	
	current = Qu.dequeue();
	return true;
}

		/**
		 * Returns the ID of the first car in the queue.
		 *
		 * @return the ID of the first car in the queue; -1 if the queue is empty
		 */
int Station::showTopOfQueue()
{
	if(Qu.size() <= 0){return -1;}//returns -1 for empty stack
	int quSize = Qu.size();
	int holder = Qu.getValue(quSize - 1);
	return holder;
}

		/**
		 * Returns the number of cars in the queue.
		 *
		 * @return the number of cars in the queue
		 */
int Station::showSizeOfQueue()
{
	return Qu.size();
}

		//Part 4--------------------------------------------------------------
		/**
		 * Adds the current car to the deque on the left side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the deque is already full.
		 *
		 * @return true if the car is successfully added to the deque; false otherwise
		 */
bool Station::addToDequeLeft()
{
	if(current == -1){return false;}
	if(Dq.size() >= 5){return false;}

	Dq.insertLeft(current);
	current = -1;
	return true;
}

		/**
		 * Adds the current car to the deque on the right side.  After this operation, there should be no current car.
		 * Does nothing if there is no current car or if the deque is already full.
		 *
		 * @return true if the car is successfully added to the deque; false otherwise
		 */
bool Station::addToDequeRight()
{
	if(current == -1){return false;}
	if(Dq.size() >= 5){return false;}

	Dq.insertRight(current);
	current = -1;
	return true;
}

		/**
		 * Removes the leftmost car in the deque and makes it the current car.
		 * Does nothing if there is already a current car or if the deque already empty.
		 *
		 * @return true if the car is successfully removed from the deque; false otherwise
		 */
bool Station::removeFromDequeLeft()
{
	if(current != -1){return false;}
	if(Dq.size() <= 0){return false;}
	
	current = Dq.removeLeft();
	return true;
}

		/**
		 * Removes the rightmost car in the deque and makes it the current car.
		 * Does nothing if there is already a current car or if the deque already empty.
		 *
		 * @return true if the car is successfully removed from the deque; false otherwise
		 */
bool Station::removeFromDequeRight()
{
	if(current != -1){return false;}
	if(Dq.size() <= 0){return false;}
	
	current = Dq.removeRight();
	return true;
}

		/**
		 * Returns the ID of the leftmost car in the deque.
		 *
		 * @return the ID of the leftmost car in the deque; -1 if the deque is empty
		 */
int Station::showTopOfDequeLeft()
{
	if(Dq.size() <= 0){return -1;}//returns -1 for empty stack
	int holder = Dq.removeLeft();
	Dq.insertLeft(holder);
	return holder;
}

		/**
		 * Returns the ID of the rightmost car in the deque.
		 *
		 * @return the ID of the rightmost car in the deque; -1 if the deque is empty
		 */
int Station::showTopOfDequeRight()
{
	if(Dq.size() <= 0){return -1;}//returns -1 for empty stack
	int holder = Dq.removeRight();
	Dq.insertRight(holder);
	return holder;
}

		/**
		 * Returns the number of cars in the deque.
		 *
		 * @return the number of cars in the deque
		 */
int Station::showSizeOfDeque()
{
	return Dq.size();
}