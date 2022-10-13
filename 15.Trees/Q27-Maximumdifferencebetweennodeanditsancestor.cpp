/*
Maximum difference between node and its ancestor in Binary Tree
Given a Binary tree, The task is to find the maximum value by
subtracting the value of node B from the value of node A, where
A and B are two nodes of the binary tree and A is an ancestor of B.

Examples:
Input:

tree

Output: 7
Explanation: We can have various ancestor-node difference, some of which are given below :
8 – 3 = 5 , 3 – 7 = -4, 8 – 1 = 7, 10 – 13 = -3
Among all those differences maximum value is 7 obtained by subtracting 1 from 8, which we need to return as result.

Input:
            9
          /  \
        6    3
            /  \
          1    4
Output: 8
*/

// C++ program to find maximum difference between node
// and its ancestor
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node
{
    int key;
    struct Node *left, *right;
};

/* To create a newNode of tree and return pointer */
struct Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

/* Recursive function to calculate maximum ancestor-node
difference in binary tree. It updates value at 'res'
to store the result. The returned value of this function
is minimum value in subtree rooted with 't' */
int maxDiffUtil(Node *t, int *res)
{
    /* Returning Maximum int value if node is not
    there (one child case) */
    if (t == NULL)
        return INT_MAX;

    /* If leaf node then just return node's value */
    if (t->left == NULL && t->right == NULL)
        return t->key;

    /* Recursively calling left and right subtree
    for minimum value */
    int val = min(maxDiffUtil(t->left, res),
                  maxDiffUtil(t->right, res));

    /* Updating res if (node value - minimum value
    from subtree) is bigger than res */
    *res = max(*res, t->key - val);

    /* Returning minimum value got so far */
    return min(val, t->key);
}

/* This function mainly calls maxDiffUtil() */
int maxDiff(Node *root)
{
    // Initialising result with minimum int value
    int res = INT_MIN;

    maxDiffUtil(root, &res);

    return res;
}

/* Helper function to print inorder traversal of
binary tree */
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver program to test above functions
int main()
{
    // Making above given diagram's binary tree
    Node *root;
    root = newNode(8);
    root->left = newNode(3);

    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);

    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);

    cout << maxDiff(root);
}
