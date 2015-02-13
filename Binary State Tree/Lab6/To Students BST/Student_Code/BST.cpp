#include "BST.h"

BST::BST(void) {
	Root=NULL;
}

BST::~BST(void) {
}

//Please note that the class that implements this interface must be made
//of objects which implement the NodeInterface

/*
 * Returns the root node for this tree
 *
 * @return the root node for this tree.
 */
NodeInterface* BST::getRootNode() {
	//cout << "running getRootNode"<< endl;
	return Root;
}

/*
 * Attempts to add the given int to the BST tree
 *
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree)
 */
bool BST::loopadd(int data, Node* node) {

	if (data == node->Data) {
		return false;
	}	//found duplicate
	if ((node->RightChild != NULL) && (data > node->Data)) {
		return loopadd(data, node->RightChild);
	}
	if ((node->LeftChild != NULL) && (data < node->Data)) {
		return loopadd(data, node->LeftChild);
	}

	if ((node->RightChild == NULL) && (data > node->Data)) {
		Node* pointer1 = new Node(node, NULL, NULL, data );
		node->RightChild = pointer1;
		return true;
	}

	if ((node->LeftChild == NULL) && (data < node->Data)) {
		Node* pointer2 = new Node(node, NULL, NULL, data);
		node->LeftChild = pointer2;
		return true;
	}

	return false;	//it should never get this far
}
bool BST::add(int data) {
	if (Root == NULL) {
		Root = new Node(NULL, NULL, NULL, data);
		return true;
	}

	if (data == Root->Data) {
		return false;
	}
	if (data < Root->Data) {
		return loopadd(data, Root);
	}	//look left
	if (data > Root->Data) {
		return loopadd(data, Root);
	}	//look right

	return false;
//	Root->Data
}

/*
 * Attempts to remove the given int from the BST tree
 *
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree)
 */
//bool repeatremover(int data, Node* node, Node* switcher)
Node* BST::FindToRemove(Node* current, int data)//always call passing the Root Node
		{
	//Node* current = Root;
	if (current == NULL) {
		return NULL;
	}

	if (current->Data == data) {
		return current;
	}
	if (current->Data > data && current->LeftChild != NULL) {
		return FindToRemove(current->LeftChild, data);
	}	//left branch
	if (data > current->Data && current->RightChild != NULL) {
		return FindToRemove(current->RightChild, data);
	}	//right branch
	return NULL;
}

Node* BST::FindSubRight(Node* node)	//Must call logic on left child first before calling this node. This Node is only for going right
		{
	if (node->RightChild == NULL) {
		return node;
	}
	if (node->RightChild != NULL) {
		//cout << "Value of SubRight->Right child is" << node->RightChild->Data<< endl;
		return FindSubRight(node->RightChild);
	}
	return node;
}

bool BST::remove(int data) {	//Call Remove on Root until Root == NULL
	if(Root==NULL){return false;}

	//cout << "Calling Remove Function on the integer" << data<< endl;
	//cout << "The Root is equal to " << Root->Data<< endl;

	Node* ToBeRemoved = FindToRemove(Root, data);
	Node* ToTakePlace = NULL;
	int storage = 0;

	//cout << "Value of ToBeRemoved in remove function is" << ToBeRemoved->Data<< endl;


	if (ToBeRemoved->LeftChild == NULL) {
		if (ToBeRemoved == Root && ToBeRemoved->RightChild != NULL) {
			Root = ToBeRemoved->RightChild;
		//	cout << "1 Actually Removed was " << ToBeRemoved->Data << endl;
			delete ToBeRemoved;
			return true;
		}	//Root Case
		if (ToBeRemoved->RightChild == NULL && ToBeRemoved == Root) {////remove bottem right leave node
			//cout << "2 Actually Removed was " << ToBeRemoved->Data << endl;
			delete ToBeRemoved;////
			Root=NULL;/////
			return true;//////
		}	//Leaf Case
if (ToBeRemoved->RightChild==NULL && ToBeRemoved->Parent->RightChild == ToBeRemoved){
	ToBeRemoved->Parent->RightChild=NULL;
	//cout << "3 Actually Removed was " << ToBeRemoved->Data << endl;
	delete ToBeRemoved;
	return true;
}

if (ToBeRemoved->RightChild==NULL && ToBeRemoved->Parent->LeftChild == ToBeRemoved){
	ToBeRemoved->Parent->LeftChild=NULL;
	//cout << "4 Actually Removed was " << ToBeRemoved->Data << endl;
	delete ToBeRemoved;
	return true;
}
if (ToBeRemoved->RightChild!=NULL){
	ToTakePlace=FindSubRight(ToBeRemoved);
	//cout << "I FOUND IT AT 732 Actually Removed was " << ToBeRemoved->Data << endl;
	ToBeRemoved->Data= ToTakePlace->Data;

	if(ToTakePlace->Parent->RightChild==ToTakePlace){ToTakePlace->Parent->RightChild=NULL;}
	if(ToTakePlace->Parent->LeftChild==ToTakePlace){ToTakePlace->Parent->LeftChild=NULL;}


	delete ToTakePlace;
	//ToBeRemoved->Parent->RightChild=NULL;
	//cout << "Josh was replaced by " << ToBeRemoved->Data << endl;
///	delete ToBeRemoved;
	return true;
}

if (ToBeRemoved->RightChild==NULL && ToBeRemoved->Parent->LeftChild == ToBeRemoved){
	///ToBeRemoved->Parent->LeftChild=NULL;
	///cout << "4 Actually Removed was " << ToBeRemoved->Data << endl;
///	delete ToBeRemoved;
///	return true;
}






		///ToBeRemoved->Data = ToBeRemoved->RightChild->Data;
		///ToBeRemoved->LeftChild = ToBeRemoved->RightChild->LeftChild;

		ToBeRemoved->Parent->RightChild = ToBeRemoved->RightChild;
		//cout << "5 Actually Removed was " << ToBeRemoved->Data << endl;
		delete ToBeRemoved;
		return true;
		//Code HERE for a straight line
	}





	if (ToBeRemoved->LeftChild != NULL) {
		ToTakePlace = FindSubRight(ToBeRemoved->LeftChild);//////////////////////////////////////////////////////////

		/*
		if (ToBeRemoved->LeftChild==ToTakePlace&& ToTakePlace->Data==2){
			//ADDED AT 10:08
				if(ToTakePlace->Parent->LeftChild!=NULL && ToTakePlace->LeftChild != NULL){
										if(ToTakePlace->Parent->LeftChild==ToTakePlace){
											ToTakePlace->Parent->LeftChild=ToTakePlace->LeftChild;
											ToTakePlace->LeftChild->Parent=ToTakePlace->Parent;/////////////////////////////////////
										delete ToTakePlace;
										return true;
										}
										}
							cout<< "EIGHT" << endl;
							if(ToTakePlace->Parent->RightChild!=NULL && ToTakePlace->RightChild != NULL){
								cout<< "NINE" << endl;
							if(ToTakePlace->Parent->RightChild==ToTakePlace){
								ToTakePlace->Parent->RightChild=ToTakePlace->LeftChild;
								ToTakePlace->LeftChild->Parent=ToTakePlace->Parent;//////////////////////////////


							delete ToTakePlace;
													return true;
							}
							}

		}
*/
		;}
//returns the bottom right node, now perform switch and then account for a left node on it


		//storage = ToBeRemoved->Data;
//	cout << "When ToBeRemove has a left child,  ToBeRemoved was " << ToBeRemoved->Data << endl;
	ToBeRemoved->Data = ToTakePlace->Data;
	//cout << "Its place will be taken by " << ToTakePlace->Data << endl;
	//ToTakePlace->Data = storage;	//switch complete

	//if (ToBeRemoved==Root){}













	//cout<< "ONE" << endl;


	if (ToTakePlace->Parent!=NULL){
		//cout<< "ONE.2" << endl;
	if (!((ToTakePlace->Parent)->RightChild==NULL)){
		//cout<< "TWO" << endl;
	if (ToTakePlace->LeftChild == NULL && ToTakePlace==ToTakePlace->Parent->RightChild){
		//cout<< "TWO.2" << endl;
		ToTakePlace->Parent->RightChild = NULL;
		//cout << "It appears ToTake Place Has No Left Child and is a Right Child itself, taking the place now" << ToBeRemoved->Data << endl;
		delete ToTakePlace;
		return true;
	} else if (ToTakePlace->LeftChild != NULL && ToTakePlace==ToTakePlace->Parent->RightChild) {
		//storage = ToTakePlace->Data;
		//cout<< "THREE" << endl;
		ToTakePlace->Data = ToTakePlace->LeftChild->Data;

		//cout << "To Take Place is a right CHild has a of value" << ToTakePlace->Data << endl;
		//cout << "To Take Place has a left child of value" << ToTakePlace->LeftChild->Data << endl;
		delete ToTakePlace->LeftChild;
		ToTakePlace->LeftChild = NULL;
		return true;
	}
	//cout<< "FOUR" << endl;
	}
	//cout<< "FOUR.5" << endl;
	}
	//cout<< "FIVE" << endl;

	if (ToTakePlace->LeftChild == NULL) {
		//cout<< "SIX" << endl;
			ToTakePlace->Parent->LeftChild = NULL;
			//cout << "It appears ToTake Place Has No Left Child and is a Left Child, taking the place now" << ToBeRemoved->Data << endl;
			delete ToTakePlace;
			return true;
		} else {
			//storage = ToTakePlace->Data;
			//cout<< "SEVEN" << endl;
			if(ToTakePlace->Parent->LeftChild!=NULL && ToTakePlace->LeftChild != NULL){
						if(ToTakePlace->Parent->LeftChild==ToTakePlace){ToTakePlace->Parent->LeftChild=ToTakePlace->LeftChild;
						ToTakePlace->LeftChild->Parent=ToTakePlace->Parent;//////////////////////////////////////////////////////////////
						delete ToTakePlace;
						return true;
						}
						}
			//cout<< "EIGHT" << endl;
			if(ToTakePlace->Parent->RightChild!=NULL && ToTakePlace->RightChild != NULL){
				//cout<< "NINE" << endl;
			if(ToTakePlace->Parent->RightChild==ToTakePlace){ToTakePlace->Parent->RightChild=ToTakePlace->LeftChild;
			ToTakePlace->LeftChild->Parent=ToTakePlace->Parent;///////////////////////////////////////////////////////////////////////

			delete ToTakePlace;
									return true;
			}
			}

			//cout<< "TEN" << endl;

			//ToTakePlace->Data = ToTakePlace->LeftChild->Data;
			//cout << "To Take Place is a left child  has a of value" << ToTakePlace->Data << endl;
			//cout << "To Take Place has a left child of value" << ToTakePlace->LeftChild->Data << endl;
			delete ToTakePlace;
			//ToTakePlace->LeftChild = NULL;
			return true;
		}


}
/*
 * Removes all nodes from the tree, resulting in an empty tree.
 */
//void BST::clear() {
	//while (Root != NULL) {
	//	int number = Root->Data;
	//	remove(number);
	//}
	//return;
	// if( Root != NULL )
	  //      {
	    //        clear( ptr->leftChild );
	      //      clear( ptr->rightChild );
	        //    delete ptr;
	 //       }
	   //     treeSize = 0;
	     //   ptr = NULL;
	       // delete ptr;
//	        rootNode = NULL;

//}

void BST::clearRecursively(Node* ptr) // goes through and deletes each node recursively
    {
        if( ptr != NULL )
        {
            clearRecursively( ptr->LeftChild );
            clearRecursively( ptr->RightChild );
            //cout << "Clear Recursively Called for " << ptr->Data << endl;
            delete ptr;
        }
        ptr = NULL;
        //cout << "Clear Recursively Called OUTSIDE THE LOOP " << endl;
       // delete ptr;
        Root = NULL;
    }
void BST::clear()//calls a recursive clear function starting with rootnode
    {
	//cout << "Clear Called " << endl;
        clearRecursively(Root);
    }

