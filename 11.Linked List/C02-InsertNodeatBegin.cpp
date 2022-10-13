#include <iostream>
using namespace std;

struct node {
int data;
struct node* next = NULL ;
};

// Function to Insert Node at the beginning.
node* AddFirst(node *head , int val){
  node *Newnode = new node; // Create a New Node
  Newnode -> data = val; // insert the Data init
  Newnode -> next = head; // Make It point to Head
  return Newnode;  
}

int main ( ){
 struct node *head,*middle,*last;
// declaring the linked list nodes.
 head = new node;
 middle = new node;
 last = new node;

// Initialising the Values 
head -> data = 100;
middle -> data = 200;
last -> data = 300;

// linking the linked list
head -> next = middle;
middle -> next = last;
last -> next = NULL;

// Inserting 99 At the Begining of the Node
head = AddFirst(head , 99);

// Printing the formed linked list forward
node *temp = head;
 while (temp != NULL){
   cout << temp -> data << endl;
   temp = temp -> next; 
 }

}
