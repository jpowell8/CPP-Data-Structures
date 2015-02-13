#include "Node.h"


Node::Node(Node* parent, Node* rightChild, Node* leftChild, int data)
{
	Parent = parent;
	RightChild = rightChild;
	LeftChild = leftChild;
	Data = data;
}


Node::~Node(void)
{
}

/*
	 * Returns the data that is stored in this node
	 *
	 * @return the data that is stored in this node.
	 */
int Node::getData()//Node* thisNode
{
return Data;
}

	/*
	 * Returns the left child of this node or null if it doesn't have one.
	 *
	 * @return the left child of this node or null if it doesn't have one.
	 */
NodeInterface* Node::getLeftChild()
{
	return LeftChild; 
}

	/*
	 * Returns the right child of this node or null if it doesn't have one.
	 *
	 * @return the right child of this node or null if it doesn't have one.
	 */
NodeInterface* Node::getRightChild()
{
	return RightChild;
}