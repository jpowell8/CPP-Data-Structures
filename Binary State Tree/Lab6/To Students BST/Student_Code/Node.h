#pragma once
#include "NodeInterface.h"

class Node:public NodeInterface
{
public:
	Node(Node* Parent,  Node* rightChild, Node* leftChild, int data);
	~Node(void);

	/*
	 * Returns the data that is stored in this node
	 *
	 * @return the data that is stored in this node.
	 */
	int getData();

	/*
	 * Returns the left child of this node or null if it doesn't have one.
	 *
	 * @return the left child of this node or null if it doesn't have one.
	 */
	NodeInterface * getLeftChild();

	/*
	 * Returns the right child of this node or null if it doesn't have one.
	 *
	 * @return the right child of this node or null if it doesn't have one.
	 */
	NodeInterface * getRightChild();

	Node* Parent;
	Node* RightChild;
	Node* LeftChild;
	int Data;

};

