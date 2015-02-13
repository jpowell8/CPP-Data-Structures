#include "Node.h"


Node::Node(Node* parent, Node* rightChild, Node* leftChild, int data)
{
	Parent = parent;
	RightChild = rightChild;
	LeftChild = leftChild;
	Data = data;
	height = 0;
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

//int Node::getHeight()
//{
//	return height;
//}

void Node::updateHeight()
{
	int LH = (LeftChild==NULL)? 0 : LeftChild->height+1;
	int RH = (RightChild==NULL)? 0 : RightChild->height+1;
	height = max(LH,RH);
	return;
}

int Node::getBalance()
{
	int LH = (LeftChild==NULL)? -1 : LeftChild->height;
	int RH = (RightChild==NULL)? -1 : RightChild->height;
	return (RH-LH);

}
int Node::getHeight()
{
return height;
}

