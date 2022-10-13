/*
Count subtrees that sum up to a given value x only using single recursive function
Given a binary tree containing n nodes. The problem is to count subtrees having total node’s data sum equal to a given value using only single recursive functions.

Examples:

Input :
             5
           /   \
        -10     3

  /      /  \   /  \
       9    8 -4   7

       x = 7

Output : 2
There are 2 subtrees with sum 7.

1st one is leaf node:
7.

2nd one is:

      -10
     /   \
    9     8
*/

// C++ implementation to count subtrees that
// sum up to a given value x
#include <bits/stdc++.h>

using namespace std;

// structure of a node of binary tree
struct Node
{
    int data;
    Node *left, *right;
};

// function to get a new node
Node *getNode(int data)
{
    // allocate space
    Node *newNode = (Node *)malloc(sizeof(Node));

    // put in the data
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to count subtrees that
// sum up to a given value x
int countSubtreesWithSumX(Node *root,
                          int &count, int x)
{
    // if tree is empty
    if (!root)
        return 0;

    // sum of nodes in the left subtree
    int ls = countSubtreesWithSumX(root->left, count, x);

    // sum of nodes in the right subtree
    int rs = countSubtreesWithSumX(root->right, count, x);

    // sum of nodes in the subtree rooted
    // with 'root->data'
    int sum = ls + rs + root->data;

    // if true
    if (sum == x)
        count++;

    // return subtree's nodes sum
    return sum;
}

// utility function to count subtrees that
// sum up to a given value x
int countSubtreesWithSumXUtil(Node *root, int x)
{
    // if tree is empty
    if (!root)
        return 0;

    int count = 0;

    // sum of nodes in the left subtree
    int ls = countSubtreesWithSumX(root->left, count, x);

    // sum of nodes in the right subtree
    int rs = countSubtreesWithSumX(root->right, count, x);

    // if tree's nodes sum == x
    if ((ls + rs + root->data) == x)
        count++;

    // required count of subtrees
    return count;
}

// Driver program to test above
int main()
{
    /* binary tree creation
                5
            / \
        -10	 3
        / \ / \
        9 8 -4 7
    */
    Node *root = getNode(5);
    root->left = getNode(-10);
    root->right = getNode(3);
    root->left->left = getNode(9);
    root->left->right = getNode(8);
    root->right->left = getNode(-4);
    root->right->right = getNode(7);

    int x = 7;

    cout << "Count = "
         << countSubtreesWithSumXUtil(root, x);

    return 0;
}
