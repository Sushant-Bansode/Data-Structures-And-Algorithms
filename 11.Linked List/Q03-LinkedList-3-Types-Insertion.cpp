// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of
// the list.


/*Approach: The new node is always added before the head of the given
Linked List. And newly added node becomes the new head of the Linked
List. For example, if the given Linked List is 10->15->20->25 and 
we add an item 5 at the front, then the Linked List becomes 
5->10->15->20->25. Let us call the function that adds at the 
front of the list is push(). The push() must receive a pointer 
to the head pointer because the 
push must change the head pointer to point to the new node */


/*
Add a node after a given node: (5 steps process) 
Approach: We are given a pointer to a node, and the new node is inserted after the given node.

Follow the steps to add a node after a given node:

Firstly, check if the given previous node is NULL or not.
Then, allocate a new node and
Assign the data to the new node
And then make the next of new node as the next of previous node. 
Finally, move the next of the previous node as a new node.
*/ 

/*
Add a node at the end: (6 steps process) 
The new node is always added after the last node of the given 
Linked List. For example if the given 
Linked List is 5->10->15->20->25 and we add an item 30 at the end, 
then the Linked List becomes 5->10->15->20->25->30. 
Since a Linked List is typically represented by the head of it, 
we have to traverse the list till the end and then
change the next to last node to a new node. */

// A complete working C++ program to
// demonstrate all insertion methods
// on Linked List
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point
	// to the new node
	(*head_ref) = new_node;
}

// Given a node prev_node, insert a new
// node after the given prev_node
void insertAfter(Node* prev_node, int new_data)
{
	// 1. check if the given prev_node
	// is NULL
	if (prev_node == NULL)
	{
		cout<<"The given previous node cannot be NULL";
		return;
	}

	// 2. allocate new node
	Node* new_node = new Node();

	// 3. put in the data
	new_node->data = new_data;

	// 4. Make next of new node
	// as next of prev_node
	new_node->next = prev_node->next;

	// 5. move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// appends a new node at the end
void append(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	//used in step 5
	Node *last = *head_ref;

	// 2. put in the data
	new_node->data = new_data;

	/* 3. This new node is going to be
	the last node, so make next of
	it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty,
	then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
	{
		last = last->next;
	}

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

// Driver code
int main()
{

	// Start with the empty list
	Node* head = NULL;
	
	// Insert 6. So linked list becomes 6->NULL
	append(&head, 6);
	
	// Insert 7 at the beginning.
	// So linked list becomes 7->6->NULL
	push(&head, 7);
	
	// Insert 1 at the beginning.
	// So linked list becomes 1->7->6->NULL
	push(&head, 1);
	
	// Insert 4 at the end. So
	// linked list becomes 1->7->6->4->NULL
	append(&head, 4);
	
	// Insert 8, after 7. So linked
	// list becomes 1->7->8->6->4->NULL
	insertAfter(head->next, 8);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}

