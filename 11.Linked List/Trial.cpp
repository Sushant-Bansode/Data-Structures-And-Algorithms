#include <iostream>
using namespace std;

struct node {
int data;
struct node* next;
node(int x){
   data = x;
   next = NULL; 
}
};

void Printlist(node*head ){
head = head -> next;   
cout << head -> data << endl;
}
int main ( ){

node* head = new node(10);
head -> next = new node(20); 
 Printlist(head);
cout << head -> data;

}    