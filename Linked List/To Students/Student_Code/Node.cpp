/*
 * Node.cpp
 *
 *  Created on: Sep 30, 2013
 *      Author: jpowell8
 */

#include "Node.h"

Node::Node(int Data, Node* Next)
{
	data = Data;
	next = Next;
}

Node::~Node(){}

//int Node::getData()
//{
//	return data;
//}
//Node* Node::getPointer()
//{
//	return next;
//}
//void Node::assignPointer(Node * newPointer)
////{
//	next = newPointer;
//	return;
//}
