#pragma once
#include <iostream>
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"

using namespace std;

class LinkedList

{
public:
friend class Node;

	LinkedList();
	virtual ~LinkedList();

		bool checkDuplicates(int value);

		void insertHead(int value);

		void insertTail(int value);

		void insertAfter(int value, int insertionNode);

		void remove(int value);

		void clear();

		int at(int index);

		int size();

private:
		Node* head;


};

#endif /* LINKEDLIST_H_ */



