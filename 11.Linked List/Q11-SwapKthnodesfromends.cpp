/*0
Given a singly linked list, swap kth node from beginning with kth node from end. Swapping of data is not allowed, only pointers should be changed. This requirement may be logical in many situations where the linked list data part is huge (For example student details like Name, RollNo, Address, ..etc). The pointers are always fixed (4 bytes for most of the compilers)

Example:

Input: 5 -> 10 -> 8 -> 5 -> 9 -> 3, K = 2
Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
Explanation: The 2nd node from 1st is 10 and 2nd node from last is 9, so swap them.



Input: 1 -> 2 -> 3 -> 4 -> 5, K = 5
Output: 5 -> 2 -> 3 -> 4 -> 1
Explanation: The 5th node from 1st is 5 and 5th node from last is 1, so swap them.
*/

// A C++ program to swap Kth node from beginning with kth
// node from end
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Utility function to insert a node at the beginning
void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Utility function for displaying linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* Utility function for calculating
length of linked list */
int countNodes(struct Node *s)
{
    int count = 0;
    while (s != NULL)
    {
        count++;
        s = s->next;
    }
    return count;
}

// Utility function for calculating length of linked list
void swapKth(struct Node **head_ref, int k)
{
    // Count nodes in linked list
    int n = countNodes(*head_ref);
    // Check if k is valid
    if (n < k)
        return;
    // If x (kth node from start) and y(kth node from end)
    // are same
    if (2 * k - 1 == n)
        return;
    // Find the kth node from the beginning of the linked
    // list. We also find previous of kth node because we
    // need to update next pointer of the previous.
    Node *x = *head_ref;
    Node *x_prev = NULL;
    for (int i = 1; i < k; i++)
    {
        x_prev = x;
        x = x->next;
    }
    // Similarly, find the kth node from end and its
    // previous. kth node from end is (n-k+1)th node from
    // beginning
    Node *y = *head_ref;
    Node *y_prev = NULL;
    for (int i = 1; i < n - k + 1; i++)
    {
        y_prev = y;
        y = y->next;
    }
    // If x_prev exists, then new next of it will be y.
    // Consider the case when y->next is x, in this case,
    // x_prev and y are same. So the statement "x_prev->next
    // = y" creates a self loop. This self loop will be
    // broken when we change y->next.
    if (x_prev)
        x_prev->next = y;
    // Same thing applies to y_prev
    if (y_prev)
        y_prev->next = x;
    // Swap next pointers of x and y. These statements also
    // break self loop if x->next is y or y->next is x
    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;
    // Change head pointers when k is 1 or n
    if (k == 1)
        *head_ref = y;
    if (k == n)
        *head_ref = x;
}

// Driver code
int main()
{
    // Let us create the following linked list for testing
    // 1->2->3->4->5->6->7->8
    struct Node *head = NULL;
    for (int i = 8; i >= 1; i--)
        push(&head, i);
    cout << "Original Linked List: ";
    printList(head);
    for (int k = 1; k < 9; k++)
    {

        // Function call
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }
    return 0;
}
