#include "LinkedList.h"

/*
 * LinkedList.cpp
 *
 *  Created on: Sep 30, 2013
 *      Author: jpowell8
 */

#include "LinkedList.h"

LinkedList::LinkedList()
{
head = NULL;
}

LinkedList::~LinkedList() {clear();}


/*current = head;
int i = 1;
while(current->next != NULL)
{
current = current->next; // or current = current->next;
	i++	;
}
return i;*/

bool LinkedList::checkDuplicates(int value)
	{

	if(head==NULL)
	{return false;}


		Node* current = head;

		if (value < 0)
			{return true;}

		if(head == NULL)
		{return false;}

		if(head->data == value)
		{return true;}


		while(current->next != NULL)
		{
			current = current->next;
			if (current->data == value)
			{return true;}
		}

		if (current->data == value)
					{return true;}

		return false;
		//check for duplicates

		//if found return true or if negative integer

		//if duplicate not found return false

	}
/*
		insertHead

		A node with the given value should be inserted at the beginning of the list.

		Only non-negative values should be added to the list. Do not allow
		duplicate values in the list.
	 */
	void LinkedList::insertHead(int value)
	{
		if (value < 0)
		{
		//cout<<"cannot add a negative value"<<endl;
			return;
		}

		bool duplicate = checkDuplicates(value);

		if (duplicate == true)
		{
			//cout << "value already exists" << endl;
			return;
		}

		if(head == NULL)
		{
			Node* temp = new Node(value, NULL);//Figure out pointers
			head = temp; //how can i get a pointer to the Node I just made?? *this??
			return;
		}

		Node* temp = new Node(value, head);//Figure out pointers
		head = temp; //how can i get a pointer to the Node I just made?? *this??
		return;

	}

	/*
		insertTail

		A node with the given value should be inserted at the end of the list.

		Only non-negative values should be added to the list. Do not allow
		duplicate values in the list.
	 */
	void LinkedList::insertTail(int value)
	{
		if (value < 0)
				{return;}

				bool duplicate = checkDuplicates(value);

				if (duplicate == true)
				{
					//cout << "value already exists" << endl;
					return;
				}


				if (head == NULL)
				{insertHead(value);
				return;
				}

				Node*temp1 = head;
				Node*temp2 = temp1->next;

				while(temp1->next != NULL)
				{temp2 = temp1->next;
				temp1 = temp2;
				}

				temp1->next = new Node(value, NULL);

				//Node* temp = new Node(value, head->next);//Figure out pointers
					//	head = temp; //how can i get a pointer to the Node I just made?? *this??
						return;
	}


	/*
		insertAfter

		A node with the given value should be inserted immediately after the
		node whose value is equal to insertionNode.

		A node should only be added if the node whose value is equal to
		insertionNode is in the list. Only non-negative values should be
		added to the list. Do not allow duplicate values in the list.
	 */
	void LinkedList::insertAfter(int value, int insertionNode)
	/*{
		///could recycle code as a find function
		current = head;
				i=0
				while(current->next != NULL)
				{
				if (current->data == index)
				{
					return i;
				}
				else
				{
					i++;
					current = current->next;
				}
				}
				cout << "Number Not Found" << endl;
				return 0;
		/////////////////////////////


		current = head
				while (value != current.getvalue())//or until the end of the list also can current == value
				{current = current.getPointer();

					if(current.getPointer=NULL)
					{
					cout << "Action Failed, No Node with this value Exists" << endl;
					return;
					}

				} // make this function later to give next pointer from current

		if (value < 0)
						{return;}

		bool duplicate = checkDuplicates(int value);

		if (duplicate == true)
				{
					return;
				}

		new Node(value, NULL)//Figure out pointers
							//change the next pointer of the previous tail to it.
	}*/


	////////////////////////Run function to check for valid input

	{

		bool duplicate = checkDuplicates(value);

				if (duplicate == true)
				{
					//cout << "value already exists" << endl;
					return;
				}


	Node* temp = head;//maybe not necessary first clause
	if (head->data == insertionNode)
	{
		Node* temp2 = new Node(value, temp->next);
		temp->next = temp2;
		return;
	}
	while (temp->data != insertionNode && temp->next != NULL)
	{
		temp = temp->next;
	}
	if(temp->data == insertionNode)
	{
		Node* temp2 = new Node(value, temp->next);
		temp->next = temp2;
		return;
	}
	if(temp->next == NULL)
	{
		return;
	}

	}

	/*
		remove

		The node with the given value should be removed from the list.

		The list may or may not include a node with the given value.
	 */

	void LinkedList::remove(int value)//SHOULD WORK WHEN head is sorted out
	{
		if(head == NULL)
		{
			return;
		}

		Node* temp1 = head;
		Node* temp2 = head->next;

		if(head->data == value)
		{
			head = head->next;
			delete temp1;
			//head = temp2;
			return;
		}

		if(temp2 == NULL)
		{
			return;
		}

		while(temp2->data != value && temp2->next != NULL)
		{
			temp1 = temp2;
			temp2 = temp2->next;
		}

		if(temp2 == NULL)
				{
					return;
				}

		if(temp2->data == value)
		{
			temp1->next = temp2->next;
			delete temp2;
		}
		return;

	}



	/*
		clear

		Remove all nodes from the list.
	 */
	void LinkedList::clear()
	{
		if(head==NULL)
		{
			return;
		}


		Node* temp1 = head;
		Node* temp2 = head->next;

		while(temp2 != NULL)
		{
			delete temp1;
			temp1 = temp2;
			temp2 = temp2->next;
		}

		if (temp1 != NULL)
		{
			delete temp1;
		}

		head = NULL;
		return;

	}
	/*
		at

		Returns the value of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, return -1;
	 */
	int LinkedList::at(int index)
	{
		Node* current = head;
		int i=0;
		while (i != index && current->next != NULL)
		{
			current = current->next;
				i++;
		}
		if(i==index)
		{
		return current->data;
		}

		else
		{
			return -1;
		}

	}

	int LinkedList::size()
	{
		if(head == NULL)
		{
			return 0;
		}

		Node* current = head;
		int i = 1;
		while(current->next != NULL)
		{
		current = current->next;
			i++	;
		}
		return i;
	}

