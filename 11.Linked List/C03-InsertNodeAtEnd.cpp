#include <iostream>
using namespace std;

struct node {
int data;
struct node* next;
};

// Function to Insert Node at the END.
node* AddLast(node *temp,int val){
  node *Newnode = new node; // Create a New Node
  Newnode -> data = val; // insert the Data init 
  while (temp -> next != NULL){  // Keep Loopin till I find the Last Node with NULL as its Pointer.
  temp = temp -> next; 
  }
  temp -> next = Newnode; // After Getting the Last Node Link its next pointer with the Newnode
  Newnode -> next = NULL;//Make the NewNodes Pointer to be Null. 
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

// Inserting 99 At the End of the Node
last = AddLast(head,99);
cout << last-> data << endl;
// Printing the formed linked list forward
node *temp = head;
 while (temp -> next != NULL){
   cout << temp -> data << endl;
   temp = temp -> next; 
 }

}
