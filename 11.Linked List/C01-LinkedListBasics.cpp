#include <iostream>
using namespace std;

struct node {
int data;
struct node* next = NULL ;
};

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
middle -> next = last; // head -> next -> next = last;
last -> next = NULL;  //  head -> next -> next -> next = NULL;

// Printing the formed linked list forward
node *temp = head;
 while (temp != NULL){
   cout << temp -> data << endl;
   temp = temp -> next; 
 }

 node * temp = new node;
 temp -> data = 100;

 node *temp2 = temp;
 temp2 -> data = 100000;

 cout << temp -> data << endl;
 

}
// Remember Like in Array there's No way to Seek,an Element in linkedlist randomly
// like in Array, every element can be accessed in O(1) but here we need loop so O(n), 
// as Every element is connected, To each other through pointer, and Named Nodes, exist in Stack.
// There on Insertion between nodes in Heap everything preassumed here canbe changed, and unnamed Nodes can be there in Heap.
//    