/*
Given a binary tree, the task is to find the maximum width of the given
tree. Width of a tree is maximum of widths of all levels.

Example:

Input:
             1
          /   \
       2      3
    /   \       \
 4     5       8
              /     \
           6        7
Output:  3
Explanation: For the above tree,
width of level 1 is 1,
width of level 2 is 2,
width of level 3 is 3
width of level 4 is 2.
So the maximum width of the tree is 3.
*/

// C++ program to calculate width of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};

/*Function prototypes*/
int getWidth(node *root, int level);
int height(node *node);

/* Function to get the maximum width of a binary tree*/
int getMaxWidth(node *root)
{
    int maxWidth = 0;
    int width;
    int h = height(root);
    int i;

    /* Get width of each level and compare
        the width with maximum width so far */
    for (i = 1; i <= h; i++)
    {
        width = getWidth(root, i);
        if (width > maxWidth)
            maxWidth = width;
    }

    return maxWidth;
}

/* Get width of a given level */
int getWidth(node *root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
        return getWidth(root->left, level - 1) + getWidth(root->right, level - 1);
}

/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        /* use the larger one */

        return (lHeight > rHeight) ? (lHeight + 1)
                                   : (rHeight + 1);
    }
}

/* Driver code*/
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(8);
    root->right->right->left = new node(6);
    root->right->right->right = new node(7);

    /*
    Constructed binary tree is:
            1
            / \
        2 3
        / \ \
        4 5 8
                / \
                6 7
    */

    // Function call
    cout << "Maximum width is " << getMaxWidth(root)
         << endl;
    return 0;
}
