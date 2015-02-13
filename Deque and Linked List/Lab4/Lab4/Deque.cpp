#include "Deque.h"


deque::deque(void)
{
	LinkedList DqList;
}
deque::~deque(void)
{
}

void deque::insertLeft(int car)
{
DqList.insertHead(car); 
return;
}
void deque::insertRight(int car)
{
DqList.insertTail(car);
return;
}
int deque::removeLeft()
{
int index = DqList.at(0);//gets value of head/left
DqList.remove(index);//removes Node with value of head/left
return index;//returns value of deleted node
}
int deque::removeRight()
{
int size = DqList.size();//finds index of last node
int index = DqList.at((size-1));//uses index of last node to get value
DqList.remove(index);//deletes node with value of last/right node
return index;// returns value of deleted node
}
bool deque::duplicate(int car)
{
bool dup = DqList.checkDuplicates(car);
return dup;
}
int deque::size()
{
int size = DqList.size();
return size;
}