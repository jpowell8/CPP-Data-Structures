/*
 * AVL.cpp
 *
 *  Created on: Dec 9, 2013
 *      Author: jpowell8
 */

#include "AVL.h"
#include <iostream>



AVL::AVL() {
	// TODO Auto-generated constructor stub
	Root=NULL;
}

AVL::~AVL() {
	// TODO Auto-generated destructor stub
}

/* namespace std */


//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	 * Returns the root node for this tree
	 *
	 * @return the root node for this tree.
	 */
	NodeInterface * AVL::getRootNode(){
		return Root;
	}

	/*
	 * Attempts to add the given int to the AVL tree
	 * Rebalances the tree if data is successfully added
	 *
	 * @return true if added
	 * @return false if unsuccessful (i.e. the int is already in tree)
	 */

	Node* AVL::recAdd(Node*a, int x){
			if(a==NULL)
			{
				return new Node(NULL, NULL, NULL, x);
			}
			else if(a->Data > x)
			{
				a->LeftChild = recAdd(a->LeftChild,x);
				return rebalance(a);
			}
			else{
				a->RightChild= recAdd(a->RightChild,x);
				return rebalance(a);
			}
		}


	bool AVL::contains(Node* A, int data)
		{
			if (A->Data == data){return true;}
			if(A->Data > data){
				if(A->LeftChild==NULL){return false;}
				return contains(A->LeftChild, data);
			}
			if(A->Data < data){
				if(A->RightChild==NULL){return false;}
				return contains(A->RightChild, data);
			}
		}

	bool AVL::add(int data){
		//cout << "ADD " << data << endl;

		if (Root == NULL) {
				Root = new Node(NULL, NULL, NULL, data);
				return true;
			}

		if (contains(Root, data)){return false;}

		Root=recAdd(Root,data);
		Root->updateHeight();

		//cout << "ADDED VALUE " << data << " Root height is " << Root->height << " and balance is " << Root->getBalance()<< endl;

		if (Root->getBalance()>1||Root->getBalance()<-1){Root = rebalance(Root);}

		//cout << "ADDED VALUE " << data << " Root height is " << Root->height << " and balance is " << Root->getBalance()<< endl;

		//if(data==-48&&contains(Root, data)){cout << "-48 is to"<< endl;}


			return true;

	}


	Node* AVL::removeInOrder(Node* A, Node* BAD)
	{//cout << "entered IN ORDER"  << endl;

	if(A->RightChild==NULL){///IS IOP
		if(A->LeftChild==NULL){
			BAD->Data=A->Data;
			delete A;
			return NULL;
		}
		BAD->Data=A->Data;
		Node* TEMP = A->LeftChild;
		delete A;
		return rebalance(TEMP);
	}
	A->RightChild=rebalance(removeInOrder(A->RightChild, BAD));
	return rebalance(A);



		//if(A->RightChild==NULL){
		//	cout << "IN ORDER- Right is NULL"  << endl;
		//return A;}/////////WHAT IF THE LEFT HAS DATA!!!!!!!!

	//	if(A->RightChild->RightChild==NULL){
	//		cout << "IN ORDER, RIGHT RIGHT IS NULL" << endl;
	//		if(A->RightChild->LeftChild!=NULL)
	//		{cout << "IN ORDER, RIGHT RIGHT IS NULL Right left is not" << endl;
	//			Node* temp = A->RightChild;
	//			A->RightChild = A->RightChild->LeftChild;
	//			//rebalance(A);///////////DELETE LATER MAYBE
	//			return temp;
	//		}
	//		else
	//		{cout << "IN ORDER, RIGHT RIGHT IS NULL so is right left" << endl;
	//		Node* Temporary = A->RightChild;
	//		A->RightChild=NULL;
	//		//rebalance(A);//////////////ALSO DELETE MAYBE
	//		return Temporary;
	//		}
	//		cout << "IN ORDER, RIGHT RIGHT IS NULL reached statement at the Bottom" << endl;
	//		return removeInOrder(A->RightChild);
	//	}
	//	cout << "IN ORDER At the End where there is No return statement" << endl;
	//	if(A->RightChild->RightChild->RightChild==NULL){
	//	//	then As right right is the in order, and As right is the root of what will be balanced, so a->r should be set to a->rightbalanced after the in order is gone



	//		if(A->RightChild->RightChild->LeftChild!=NULL)//TRYING TO FIX THE PROBLEM WITH LONG LINE OF IN ORDER
	//					{//cout << "IN ORDER, RIGHT RIGHT IS NULL Right left is not" << endl;
	//						Node* temp3 = A->RightChild->RightChild;
	//						A->RightChild->RightChild = A->RightChild->RightChild->LeftChild;
	//						A->RightChild=rebalance(A->RightChild);///////////DELETE LATER MAYBE
	//						return temp3;
	//					}
	//					else
	//					{//cout << "IN ORDER, RIGHT RIGHT IS NULL so is right left" << endl;
	//					Node* Temporary3 = A->RightChild->RightChild;
	//					A->RightChild->RightChild=NULL;
	//					A->RightChild=rebalance(A->RightChild);//////////////ALSO DELETE MAYBE
	//					return Temporary3;
	//					}


	//	}
	//	Node* bal = removeInOrder(A->RightChild);
	//	rebalance(A);
	//	return bal;
	}

	Node* AVL::removeRecursive(Node* A, int data)
	{
		//cout << "ENTER removeRecursive " << data << endl;
		if(A==NULL){
			//cout << "removeRecursive- Node is NULL " << data << endl;
			return NULL;}

		//if(A->RightChild!=NULL){
		//	cout << "removeRecursive Right Child is NOT NULL" << data << endl;
		//if(A->RightChild->Data==data)
		//{cout << "removeRecursive Right Child data is data" << data << endl;
		//	if(A->RightChild->RightChild==NULL&&A->RightChild->LeftChild==NULL)
		//	{
		//		cout << "removeRecursive Right Child data is data and has no Children" << data << endl;
		//		Node* ONE = A->RightChild;
		//		A->RightChild=NULL;
		//		delete ONE;
		//		return NULL;
		//	}
		//}
		//}

		if(A->Data==data){
			if(A->LeftChild==NULL){
				if(A->RightChild==NULL){
					delete A;
					return NULL;
				}
				Node* rightside = rebalance(A->RightChild);
				return rightside;
			}
			A->LeftChild = rebalance(removeInOrder(A->LeftChild, A));
			return rebalance(A);

			//cout << "removeRecursive Data is data" << data << endl;
			//if(A->LeftChild==NULL){
			//	cout << "removeRecursive Data is data - Left NULL" << data << endl;
			//	if(A->RightChild==NULL){delete A;/////////leaves an arrow to nothing
			//	cout << "removeRecursive Data is data - Left and Right are NULL" << data << endl;
			//	return NULL;}
			//	else{
			//		cout << "removeRecursive Data is data, Left is NULL Righ tis NOT NULL" << data << endl;
			//	Node* Temp = A->RightChild;
			//	delete A;
			//	return rebalance(Temp);}
			}
			//if(A->LeftChild!=NULL){
			//	cout << "removeRecursive Data is data- LEFT NOT NULL" << data << endl;
				//Node* B =removeInOrder(A->LeftChild);
				//A->Data= B->Data;
				//delete B;
				//B->Parent->RightChild=NULL;
				//A->LeftChild=rebalance(A->LeftChild);
				//return rebalance(A);
			//}

		if(A->Data < data){	//cout << "removeRecursive Called Recursively at the Bottom Node Less" << data << endl;
			A->RightChild = removeRecursive(A->RightChild, data); return rebalance(A);}
		if(A->Data > data){ //cout << "removeRecursive Called Recursively at the Bottom Node Greater" << data << endl;
			A->LeftChild = removeRecursive(A->LeftChild, data); return rebalance(A);}
	}

	bool AVL::remove(int data)
	{

		//cout << "REMOVE " << data << endl;
		if(Root==NULL){
			//cout << "remove-Root==NULL " << data << endl;
			return false;}
		if(!contains(Root, data)){
			//cout << "remove- does not contain data " << data << endl;
			return false;}
		if(Root->RightChild==NULL&&Root->LeftChild==NULL)
		{
			//cout << "remove- both children NULL " << data << endl;
			if (Root->Data == data){delete Root;
			Root=NULL;
			//cout << "remove- Root data is data " << data << endl;
			return true;}
			return false;
		}
		if(data == Root->Data){
			//cout << "remove- Data matches for Root passing to the remove recursive " << data << endl;
			Root=removeRecursive(Root, data);}///Why do I do this?


		if(data > Root->Data){
			//cout << "remove- data greater than Root data " << data << endl;
			Root->RightChild=removeRecursive(Root->RightChild, data);
		Root=rebalance(Root);
		return true;}

		if(data < Root->Data){
			//cout << "remove- data less than Root Data " << data << endl;
			Root->LeftChild=removeRecursive(Root->LeftChild, data);
		Root=rebalance(Root);
		return true;}

	}

		void AVL::rightRight(Node* A){
			Node* B = A->RightChild;
			Node* C = B->RightChild;

			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

			A->RightChild=B->LeftChild;
			B->LeftChild=A;
			//Now for Parent stuff
			//A->RightChild->Parent = A;
			//A->Parent=B;




			C->updateHeight();
			A->updateHeight();
			B->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

			//cout<< "A Data is" << A->Data << "A height is" << A->height <<endl;
			//cout<< "B Data is" << B->Data << "B height is" << B->height<<endl;
			//cout<< "C Data is" << C->Data << "C height is" << C->height<<endl;

return;

		}
		void AVL::leftRight(Node* A){
			Node* B = A->LeftChild;
			Node* C = B->RightChild;

			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();


			A->LeftChild=C;
			B->RightChild=C->LeftChild;
			C->LeftChild=B;


			B->updateHeight();
			C->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

		//	cout<< "A Data is" << A->Data << "A height is" << A->height<<endl;
			//cout<< "B Data is" << B->Data << "B height is" << B->height<<endl;
		//	cout<< "C Data is" << C->Data << "C height is" << C->height<<endl;

			return;

		}
		void AVL::leftLeft(Node* A){
			Node* B = A->LeftChild;
			Node* C = B->LeftChild;

			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

			A->LeftChild=B->RightChild;
			B->RightChild=A;

			//Now for Parent stuff
			//A->LeftChild->Parent = A;
			//A->Parent=B;

			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

		//	cout<< "A Data is" << A->Data << "A height is" << A->height<<endl;
		//	cout<< "B Data is" << B->Data << "B height is" << B->height<<endl;
		//	cout<< "C Data is" << C->Data << "C height is" << C->height<<endl;
return;

		}
		void AVL::rightLeft(Node* A){
			Node* B = A->RightChild;
			Node* C = B->LeftChild;

			C->updateHeight();
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();//
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();

			A->RightChild=C;//
			B->LeftChild=C->RightChild;//
			C->RightChild=B;

			//if(C->RightChild==NULL)
			//{C->RightChild=B;}//
			//lse{C->RightChild->RightChild=B;
			//C->RightChild=rebalance(C->RightChild);}



			B->updateHeight();
			C->updateHeight();
			A->updateHeight();
			C->updateHeight();//JUST TRYING IT
			B->updateHeight();
			A->updateHeight();
			C->updateHeight();
						A->updateHeight();
						B->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();
						C->updateHeight();
						B->updateHeight();
						A->updateHeight();



		//	cout<< "A Data is" << A->Data << "A height is" << A->height<<endl;
		//	cout<< "B Data is" << B->Data << "B height is" << B->height<<endl;
		//	cout<< "C Data is" << C->Data << "C height is" << C->height<<endl;
			return;

		}
		Node* AVL::rebalance(Node* A){
			if(A==NULL){return NULL;}
			A->updateHeight();


			if(A->getBalance()>1)
			{
				Node* B = A->RightChild;
				if(B->getBalance()>1){A->RightChild=rebalance(B);}

				if (B->getBalance()<0)
				{
					Node* C = B->LeftChild;
					rightLeft(A);
					rightRight(A);
					return C;
				}
				else{
					rightRight(A);
					return B;
				}
			}
			else if(A->getBalance()<-1)
			{
				Node* B = A->LeftChild;
				if(B->getBalance()<-1){A->LeftChild=rebalance(B);}

				if (B->getBalance()<=0)
				{
					Node* C = B->LeftChild;
					leftLeft(A);
					return B;
				}
				else{
					Node* C = B->RightChild;
					leftRight(A);
					leftLeft(A);
					return C;
					}
			}
			return A;

		}
	/*
	 * ROTATIONS:
	 * 			LEFT
	 *
	 * 				IDENTIFY NODES TO ROTATE
	 *
	 * 				ROT.RIGHT=CUR.LEFT
	 * 				CUR.LEFT=ROT
	 * 				CUR=ROT
	 *
	 *
	 *
	 *
	 * 			RIGHT
	 *
	 *
	 *
	 */
