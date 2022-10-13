/*
1) Delete from Beginning:
Point head to the next node i.e. second node
    temp = head
    head = head->next
    
Make sure to free unused memory
    free(temp); or delete temp;
2) Delete from End:
Point head to the previous element i.e. last second element
    Change next pointer to null
    struct node *end = head;
    struct node *prev = NULL;
    while(end->next)
    {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
    
Make sure to free unused memory
    free(end); or delete end;
3) Delete from Middle:
Keeps track of pointer before node to delete and pointer to node to delete
    temp = head;
    prev = head;
    for(int i = 0; i < position; i++)
    {
        if(i == 0 && position == 1)
            head = head->next;
            free(temp)
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;
                if(prev == NULL) // position was greater than number of nodes in the list
                    break;
                temp = temp->next; 
            }
        }
    }
*/

// A complete working C++ program to
// demonstrate deletion in singly
// linked list with class
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node {
public:
	int data;
	Node* next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int,
// inserts a new node on the front of the
// list.
void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{

	// Store head node
	Node* temp = *head_ref;
	Node* prev = NULL;

	// If head node itself holds
	// the key to be deleted
	if (temp != NULL && temp->data == key) {
	
	// Changed head
		*head_ref = temp->next;
	
	// free old head
		delete temp;
		return;
	}

	// Else Search for the key to be
	// deleted, keep track of the
	// previous node as we need to
	// change 'prev->next'
	else {
		while (temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}

		// If key was not present in linked list
		if (temp == NULL)
			return;

		// Unlink the node from linked list
		prev->next = temp->next;

		// Free memory
		delete temp;
	}
}

// This function prints contents of
// linked list starting from the
// given node
void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}

// Driver code
int main()
{

	// Start with the empty list
	Node* head = NULL;

	// Add elements in linked list
	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List: ");
	printList(head);

	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1: ");

	printList(head);

	return 0;
}

// C++ program to delete a node in
// singly linked list recursively

#include <bits/stdc++.h>
using namespace std;

struct node {
	int info;
	node* link = NULL;
	node() {}
	node(int a)
		: info(a)
	{
	}
};

// Deletes the node containing 'info'
// part as val and alter the head of
// the linked list (recursive method)
void deleteNode(node*& head, int val)
{

	// Check if list is empty or we
	// reach at the end of the
	// list.
	if (head == NULL) {
		cout << "Element not present in the list\n";
		return;
	}

	// If current node is the
	// node to be deleted
	if (head->info == val) {
		node* t = head;

		// If it's start of the node head
		// node points to second node
		head = head->link;

		// Else changes previous node's
		// link to current node's link
		delete (t);
		return;
	}
	deleteNode(head->link, val);
}

// Utility function to add a
// node in the linked list
// Here we are passing head by
// reference thus no need to
// return it to the main function
void push(node*& head, int data)
{
	node* newNode = new node(data);
	newNode->link = head;
	head = newNode;
}

// Utility function to print
// the linked list (recursive
// method)
void print(node* head)
{

	// cout<<endl gets implicitly
	// typecasted to bool value
	// 'true'
	if (head == NULL and cout << endl)
		return;
	cout << head->info << ' ';
	print(head->link);
}

int main()
{

	// Starting with an empty linked list
	node* head = NULL;

	// Adds new element at the
	// beginning of the list
	push(head, 10);
	push(head, 12);
	push(head, 14);
	push(head, 15);

	// original list
	print(head);

	// Call to delete function
	deleteNode(head, 20);

	// 20 is not present thus no change
	// in the list
	print(head);

	deleteNode(head, 10);
	print(head);

	deleteNode(head, 14);
	print(head);

	return 0;
}
