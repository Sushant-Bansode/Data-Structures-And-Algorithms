/*
Given a binary tree and a key(node) value, find the floor and ceil value for that particular key value.

Floor Value Node: Node with the greatest data lesser than or equal to the key value.
Ceil Value Node: Node with the smallest data larger than or equal to the key value.
For example, Let’s consider the Binary Tree below –

          8
        /   \
      4      12
    /  \    /  \
   2    6  10   14

Key: 11  Floor: 10  Ceil: 12
Key: 1   Floor: -1  Ceil: 2
Key: 6   Floor: 6   Ceil: 6
Key: 15  Floor: 14  Ceil: -1
There are numerous applications where we need to find the floor/ceil value of a key in a binary search tree or sorted array. For example, consider designing a memory management system in which free nodes
are arranged in BST. Find the best fit for the input request.
*/

// Program to find floor of a given value in BST
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, left child and right child */
class node
{
public:
    int key;
    node *left;
    node *right;
};

/* Helper function that allocates a new node with the given key and
NULL left and right pointers.*/
node *newNode(int key)
{
    node *Node = new node();
    Node->key = key;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// Function to find floor of a given input in BST. If input is more
// than the min key in BST, return -1
int Floor(node *root, int input)
{
    // Base case
    if (root == NULL)
        return -1;

    // We found equal key
    if (root->key == input)
        return root->key;

    // If root's key is larger, floor must be in left subtree
    if (root->key > input)
        return Floor(root->left, input);

    // Else, either right subtree or root has the floor value
    else
    {
        int floor = Floor(root->right, input);
        // exception for -1 because it is being returned in base case
        return (floor <= input && floor != -1) ? floor : root->key;
    }
}

// Driver program to test above function
int main()
{
    node *root = newNode(8);

    root->left = newNode(4);
    root->right = newNode(12);

    root->left->left = newNode(2);
    root->left->right = newNode(6);

    root->right->left = newNode(10);
    root->right->right = newNode(14);

    for (int i = 0; i < 16; i++)
        cout << i << " " << Floor(root, i) << endl;

    return 0;
}
