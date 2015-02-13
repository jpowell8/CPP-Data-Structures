/*
 * Node.h
 *
 *  Created on: Sep 30, 2013
 *      Author: jpowell8
 */

#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	Node(int Data, Node* Next);
	virtual ~Node();

	friend class LinkedList;
	//int getData();
	//Node* getPointer();
	//void assignPointer(Node* newPointer);

protected:
	int data;
	Node* next;

};

#endif /* NODE_H_ */
