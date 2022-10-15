/*
Special two digit numbers in a Binary Search Tree

Given a Binary Search Trees, the task is to count the number of nodes
which are having special two-digit numbers.

Examples :
Input : 15 7 987 21
Output : 0

Input : 19 99 57 1 22
Output : 2
*/

// C++ program to count number of nodes in
// BST containing two digit special number
#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node
{
    struct Node *left;
    int info;
    struct Node *right;
};

// Function to create a new node
void insert(struct Node **rt, int key)
{
    if (*rt == NULL)
    {
        (*rt) = new Node();
        (*rt)->left = NULL;
        (*rt)->right = NULL;
        (*rt)->info = key;
    }
    else if (key < ((*rt)->info))
        insert(&((*rt)->left), key);
    else
        insert(&(*rt)->right, key);
}

// Function to find if number
// is special or not
int check(int num)
{
    int sum = 0, i = num, sum_of_digits, prod_of_digits;

    // Check if number is two digit or not
    if (num < 10 || num > 99)
        return 0;
    else
    {
        sum_of_digits = (i % 10) + (i / 10);
        prod_of_digits = (i % 10) * (i / 10);
        sum = sum_of_digits + prod_of_digits;
    }

    if (sum == num)
        return 1;
    else
        return 0;
}

// Function to count number of special two digit number
void countSpecialDigit(struct Node *rt, int *c)
{
    int x;
    if (rt == NULL)
        return;
    else
    {
        x = check(rt->info);
        if (x == 1)
            *c = *c + 1;
        countSpecialDigit(rt->left, c);
        countSpecialDigit(rt->right, c);
    }
}

// Driver program to test
int main()
{
    struct Node *root = NULL;

    // Initialize result
    int count = 0;

    // Function call to insert() to insert nodes
    insert(&root, 50);
    insert(&root, 29);
    insert(&root, 59);
    insert(&root, 19);
    insert(&root, 53);
    insert(&root, 556);
    insert(&root, 56);
    insert(&root, 94);
    insert(&root, 13);

    // Function call, to check each node for
    // special two digit number
    countSpecialDigit(root, &count);
    cout << count;

    return 0;
}
