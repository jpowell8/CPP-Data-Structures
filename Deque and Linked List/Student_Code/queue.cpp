#include "queue.h"


queue::queue(void)
{
	LinkedList QuList;
}
queue::~queue(void)
{
}
void queue::enqueue(int car)//inserts a new head
{
QuList.insertHead(car); 
return;
}
int queue::dequeue()//removes and returns tail
{
int size = QuList.size();//finds index of last node
int index = QuList.at((size-1));//uses index of last node to get value
QuList.remove(index);//deletes node with value of last/right node
return index;// returns value of deleted node
}
bool queue::duplicate(int car)
{
bool dup = QuList.checkDuplicates(car);
return dup;
}
int queue::size()
{
int size = QuList.size();
return size;
}
int queue::getValue(int index)
{
	return QuList.at(index);
}