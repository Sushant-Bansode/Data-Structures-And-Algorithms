/*
Given two values k1 and k2 where k1 < k2 and a root pointer to a
Binary Search Tree. The task is to print all the keys of the tree
in the range k1 to k2 in increasing order.

Examples:
Input: k1 = 10 and k2 = 22

Output: 12, 20 and 22.
Explanation: The keys are 4, 8, 12, 20, and 22, So keys in range 10 to 22 is 12, 20 and 22.

Input: k1 = 1 and k2 = 10

Output: 8
Explanation: The key 8 is in the range 1 to 10
*/

// C++ program to print BST in given range
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
public:
    int data;
    node *left;
    node *right;
};

/* The functions prints all the keys
which in the given range [k1..k2].
    The function assumes than k1 < k2 */
void Print(node *root, int k1, int k2)
{
    /* base case */
    if (NULL == root)
        return;

    /* Since the desired o/p is sorted,
        recurse for left subtree first
        If root->data is greater than k1,
        then only we can get o/p keys
        in left subtree */
    if (k1 < root->data)
        Print(root->left, k1, k2);

    /* if root's data lies in range,
    then prints root's data */
    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    /* recursively call the right subtree */
    Print(root->right, k1, k2);
}

/* Utility function to create a new Binary Tree node */
node *newNode(int data)
{
    node *temp = new node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/* Driver code */
int main()
{
    node *root = new node();
    int k1 = 10, k2 = 25;

    /* Constructing tree given
    in the above figure */
    root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);

    Print(root, k1, k2);
    return 0;
}
