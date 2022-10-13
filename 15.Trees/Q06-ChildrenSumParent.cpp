/*
Given a Binary Tree. Check whether all of its nodes have the value equal
to the sum of their child nodes.

Example 1:
Input:
     10
    /
  10
Output: 1
Explanation: Here, every node is sum of
its left and right child.
Example 2:

Input:
       1
     /   \
    4     3
   /  \
  5    N
Output: 0
Explanation: Here, 1 is the root node
and 4, 3 are its child nodes. 4 + 3 =
7 which is not equal to the value of
root node. Hence, this tree does not
satisfy the given conditions.

Your Task:
You don't need to read input or print anything. Your task is to complete the function isSumProperty() that takes the root Node of the Binary Tree as input and returns 1 if all the nodes in the tree satisfy the following properties. Else, it returns 0.
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

*/
Expected Time Complexiy : O(N).Expected Auxiliary Space : O(Height of the Tree).
/* Program to check children sum property */
#include <bits/stdc++.h>
                                                          using namespace std;

/* A binary tree node has data, left
child and right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* returns 1 if children sum property holds
for the given node and both of its children*/
int isSumProperty(struct node *node)
{
    /* left_data is left child data and
    right_data is for right child data*/
    int sum = 0;

    /* If node is NULL or it's a leaf node
    then return true */
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 1;
    else
    {
        /* If left child is not present then 0
        is used as data of left child */
        if (node->left != NULL)
            sum += node->left->data;

        /* If right child is not present then 0
        is used as data of right child */
        if (node->right != NULL)
            sum += node->right->data;

        /* if the node and both of its children
        satisfy the property return 1 else 0*/
        return ((node->data == sum) && isSumProperty(node->left) && isSumProperty(node->right));
    }
}

/*
Helper function that allocates a new node
with the given data and NULL left and right
pointers.
*/
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

// Driver Code
int main()
{
    struct node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->right = newNode(2);

    // Function call
    if (isSumProperty(root))
        cout << "The given tree satisfies "
             << "the children sum property ";
    else
        cout << "The given tree does not satisfy "
             << "the children sum property ";

    getchar();
    return 0;
}
