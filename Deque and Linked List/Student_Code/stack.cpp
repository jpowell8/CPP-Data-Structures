#include "stack.h"


stack::stack(void)
{
	LinkedList StList;
}
stack::~stack(void)
{
}
void stack::push(int car)
{
StList.insertHead(car);
return;
}
int stack::pop()
{
int index = StList.at(0);//gets value of head/left
StList.remove(index);//removes Node with value of head/left
return index;//returns value of deleted node
}
bool stack::duplicate(int car)
{
bool dup = StList.checkDuplicates(car);
return dup;
}
int stack::size()
{
int size = StList.size();
return size;
}