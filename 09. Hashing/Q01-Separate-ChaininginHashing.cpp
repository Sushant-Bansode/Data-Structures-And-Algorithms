#include<iostream>
using namespace std;

struct node{
int data;
node* next;
};

node *chain[7];

void insertin( int value ){
 node* Newnode = new node;
 Newnode -> data = value;
 Newnode -> next = NULL;
 int key = value % 7;

 if(chain[key] == NULL )
 chain[key] = Newnode;
 else {
  node * temp = chain[key];

  while (temp -> next != NULL){
   temp = temp -> next;  }

   temp -> next = Newnode;
 }
}

void Print( ){
 for(int i = 0; i< 7; i++){
    node*temp = chain[i];
    cout << "chain[" << i << "]-->" ;

    while(temp != NULL){
        cout << temp ->data  << "-->";
        temp = temp ->next;
    }
 cout << "NULL\n";

 }

}

int main( ) {

for(int i =0; i<7;i++)
chain[i] = NULL;

int x;
for(int i =1; i<=7; i++){
cin >> x;
insertin(x);
}

Print ();
return 0;

}