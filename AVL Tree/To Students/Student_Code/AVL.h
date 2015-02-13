/*
 * AVL.h
 *
 *  Created on: Dec 9, 2013
 *      Author: jpowell8
 */
#include "AVLInterface.h"
#include "Node.h"

//using namespace std;

class AVL: public AVLInterface
{
public:
	AVL(void);
	~AVL(void);


	//Please note that the class that implements this interface must be made
		//of objects which implement the NodeInterface

		/*
		 * Returns the root node for this tree
		 *
		 * @return the root node for this tree.
		 */
		NodeInterface * getRootNode();

		/*
		 * Attempts to add the given int to the AVL tree
		 * Rebalances the tree if data is successfully added
		 *
		 * @return true if added
		 * @return false if unsuccessful (i.e. the int is already in tree)
		 */
		Node* recAdd(Node*a, int x);

		bool loopadd(int data, Node* node);

		bool add(int data);

		/*
		 * Attempts to remove the given int from the AVL tree
		 * Rebalances the tree if data is successfully removed
		 *
		 * @return true if successfully removed
		 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
		 */
		bool contains(Node* A, int data);
			Node* removeInOrder(Node* A, Node* BAD);
			Node* removeRecursive(Node* A, int data);


		//bool remove(int data);


		void rightRight(Node* A);
		void leftRight(Node* A);
		void leftLeft(Node* A);
		void rightLeft(Node* A);

		//Node* FindToRemove(Node* current, int data);//always call passing the Root Node
		//Node* FindSubRight(Node* node);	//Must call logic on left child first before calling this node. This Node is only for going right
		bool remove(int data);

		Node* rebalance(Node* A);

		//Node* FindSubRight(Node* node);
		//Node* FindToRemove(Node* current, int data);
		Node* Root;



};

