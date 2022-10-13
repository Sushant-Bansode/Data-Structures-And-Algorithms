/*
Construct Binary Tree from given Parent Array representation

Given an array that represents a tree in such a way that array indexes
are values in tree nodes and array values give the parent node of that
particular index (or node). The value of the root node index would
always be -1 as there is no parent for root. Construct the standard
linked representation of given Binary Tree from this given representation.

Examples:

Input: parent[] = {1, 5, 5, 2, 2, -1, 3}
Output: root of below tree
          5
        /  \
       1    2
      /    / \
     0    3   4
         /
        6
Explanation:
Index of -1 is 5.  So 5 is root.
5 is present at indexes 1 and 2.  So 1 and 2 are
children of 5.
1 is present at index 0, so 0 is child of 1.
2 is present at indexes 3 and 4.  So 3 and 4 are
children of 2.
3 is present at index 6, so 6 is child of 3.


Input: parent[] = {-1, 0, 0, 1, 1, 3, 5};
Output: root of below tree
         0
       /   \
      1     2
     / \
    3   4
   /
  5
 /
6
Expected time complexity
is O(n) where n is number of elements in given array.
*/

// C++ program to construct a Binary Tree from parent array
#include <bits/stdc++.h>
using namespace std;

// A tree node
struct Node
{
    int key;
    struct Node *left, *right;
};

// Utility function to create new Node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}

// Creates a node with key as 'i'. If i is root, then it changes
// root. If parent of i is not created, then it creates parent first
void createNode(int parent[], int i, Node *created[], Node **root)
{
    // If this node is already created
    if (created[i] != NULL)
        return;

    // Create a new node and set created[i]
    created[i] = newNode(i);

    // If 'i' is root, change root pointer and return
    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }

    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);

    // Find parent pointer
    Node *p = created[parent[i]];

    // If this is first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // If second child
        p->right = created[i];
}

// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(int parent[], int n)
{
    // Create an array created[] to keep track
    // of created nodes, initialize all entries
    // as NULL
    Node *created[n];
    for (int i = 0; i < n; i++)
        created[i] = NULL;

    Node *root = NULL;
    for (int i = 0; i < n; i++)
        createNode(parent, i, created, &root);

    return root;
}

// For adding new line in a program
inline void newLine()
{
    cout << "\n";
}

// Utility function to do inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver method
int main()
{
    int parent[] = {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    newLine();
}
