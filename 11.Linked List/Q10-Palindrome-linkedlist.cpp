/*
Given a singly linked list of characters, write a function that
 returns true if the given list is a palindrome, else false.
Examples:

Input: R->A->D->A->R->NULL
Output: Yes

Input: C->O->D->E->NULL
Output: No
*/

// C++ program to check if a linked list is palindrome Via Reversing the LL.
#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node
{
    char data;
    struct Node *next;
};

void reverse(struct Node **);
bool compareLists(struct Node *, struct Node *);

// Function to check if given linked list is
// palindrome or not
bool isPalindrome(struct Node *head)
{
    struct Node *slow_ptr = head, *fast_ptr = head;
    struct Node *second_half, *prev_of_slow_ptr = head;

    // To handle odd size list
    struct Node *midnode = NULL;

    // initialize result
    bool res = true;

    if (head != NULL && head->next != NULL)
    {

        // Get the middle of the list. Move slow_ptr by 1
        // and fast_ptr by 2, slow_ptr will have the middle
        // node
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;

            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // fast_ptr would become NULL when there
        // are even elements in list. And not NULL
        // for odd elements. We need to skip the
        // middle node for odd case and store it
        // somewhere so that we can restore the
        // original list
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;

        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;

        // Reverse the second half
        reverse(&second_half);

        // compare
        res = compareLists(head, second_half);

        // Construct the original list back
        reverse(
            &second_half); // Reverse the second half again

        // If there was a mid node (odd size case)
        // which was not part of either first half
        // or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}

// Function to reverse the linked list
// Note that this function may change
// the head
void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to check if two input
// lists have same data
bool compareLists(struct Node *head1, struct Node *head2)
{
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    // Will reach here when one is NULL
    // and other is not
    return 0;
}

// Push a node to linked list. Note
// that this function changes the head
void push(struct Node **head_ref, char new_data)
{

    // Allocate node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // Put in the data
    new_node->data = new_data;

    // Link the old list off the new node
    new_node->next = (*head_ref);

    // Move the head to point to the new node
    (*head_ref) = new_node;
}

// A utility function to print a given linked list
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL"
         << "\n";
}

// Driver code
int main()
{

    // Start with the empty list
    struct Node *head = NULL;
    char str[] = "abacaba";
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        push(&head, str[i]);
    }
    isPalindrome(head) ? cout << "Is Palindrome"
                              << "\n\n"
                       : cout << "Not Palindrome"
                              << "\n\n";
    return 0;
}

// Stack Approach.
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node(int d) { data = d; }
    Node *ptr;
};

// Function to check if the linked list
// is palindrome or not
bool isPalin(Node *head)
{

    // Temp pointer
    Node *slow = head;

    // Declare a stack
    stack<int> s;

    // Push all elements of the list
    // to the stack
    while (slow != NULL)
    {
        s.push(slow->data);

        // Move ahead
        slow = slow->ptr;
    }

    // Iterate in the list again and
    // check by popping from the stack
    while (head != NULL)
    {

        // Get the top most element
        int i = s.top();

        // Pop the element
        s.pop();

        // Check if data is not
        // same as popped element
        if (head->data != i)
        {
            return false;
        }

        // Move ahead
        head = head->ptr;
    }

    return true;
}

// Driver Code
int main()
{

    // Addition of linked list
    Node one = Node(1);
    Node two = Node(2);
    Node three = Node(3);
    Node four = Node(2);
    Node five = Node(1);

    // Initialize the next pointer
    // of every current pointer
    five.ptr = NULL;
    one.ptr = &two;
    two.ptr = &three;
    three.ptr = &four;
    four.ptr = &five;
    Node *temp = &one;

    // Call function to check palindrome or not
    int result = isPalin(&one);

    if (result == 1)
        cout << "isPalindrome is true\n";
    else
        cout << "isPalindrome is false\n";

    return 0;
}
