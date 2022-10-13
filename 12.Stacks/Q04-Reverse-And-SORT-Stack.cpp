// C++ code to reverse a
// stack using recursion
#include <bits/stdc++.h>
using namespace std;

// Below is a recursive function
// that inserts an element
// at the bottom of a stack.
void insert_at_bottom(stack<int>& st, int x)
{

	if (st.size() == 0) {
		st.push(x);
	}
	else {

		// All items are held in Function Call
		// Stack until we reach end of the stack
		// When the stack becomes empty, the
		// st.size() becomes 0, the above if
		// part is executed and the item is
		// inserted at the bottom

		int a = st.top();
		st.pop();
		insert_at_bottom(st, x);

		// push allthe items held in
		// Function Call Stack
		// once the item is inserted
		// at the bottom
		st.push(a);
	}
}

// Below is the function that
// reverses the given stack using
// insert_at_bottom()
void reverse(stack<int>& st)
{
	if (st.size() > 0) {

		// Hold all items in Function
		// Call Stack until we
		// reach end of the stack
		int x = st.top();
		st.pop();
		reverse(st);

		// Insert all the items held
		// in Function Call Stack
		// one by one from the bottom
		// to top. Every item is
		// inserted at the bottom
		insert_at_bottom(st, x);
	}
	return;
}



// Driver Code
int main()
{
	stack<int> st, st2;
	// push elements into
	// the stack
	for (int i = 1; i <= 4; i++) {
		st.push(i);
	}

	st2 = st;

	cout << "Original Stack" << endl;
	// printing the stack after reversal
	while (!st2.empty()) {
		cout << st2.top() << " ";
		st2.pop();
	}
	cout<<endl;

	// function to reverse
	// the stack
	reverse(st);
	cout << "Reversed Stack" << endl;
	// printing the stack after reversal
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}


// C++ program to sort a stack using recursion
#include <iostream>
using namespace std;

// Stack is represented using linked list
struct stack {
	int data;
	struct stack* next;
};

// Utility function to initialize stack
void initStack(struct stack** s) { *s = NULL; }

// Utility function to check if stack is empty
int isEmpty(struct stack* s)
{
	if (s == NULL)
		return 1;
	return 0;
}

// Utility function to push an item to stack
void push(struct stack** s, int x)
{
	struct stack* p = (struct stack*)malloc(sizeof(*p));

	if (p == NULL) {
		fprintf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

// Utility function to remove an item from stack
int pop(struct stack** s)
{
	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

// Function to find top item
int top(struct stack* s) { return (s->data); }

// Recursive function to insert an item x in sorted way
void sortedInsert(struct stack** s, int x)
{
	// Base case: Either stack is empty or newly inserted
	// item is greater than top (more than all existing)
	if (isEmpty(*s) or x > top(*s)) {
		push(s, x);
		return;
	}

	// If top is greater, remove the top item and recur
	int temp = pop(s);
	sortedInsert(s, x);

	// Put back the top item removed earlier
	push(s, temp);
}

// Function to sort stack
void sortStack(struct stack** s)
{
	// If stack is not empty
	if (!isEmpty(*s)) {
		// Remove the top item
		int x = pop(s);

		// Sort remaining stack
		sortStack(s);

		// Push the top item back in sorted stack
		sortedInsert(s, x);
	}
}

// Utility function to print contents of stack
void printStack(struct stack* s)
{
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << "\n";
}

// Driver code
int main(void)
{
	struct stack* top;

	initStack(&top);
	push(&top, 30);
	push(&top, -5);
	push(&top, 18);
	push(&top, 14);
	push(&top, -3);

	cout << "Stack elements before sorting:\n";
	printStack(top);

	sortStack(&top);
	cout << "\n";

	cout << "Stack elements after sorting:\n";
	printStack(top);

	return 0;
}





