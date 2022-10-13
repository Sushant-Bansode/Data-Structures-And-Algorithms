/*
Print all nodes that are at distance k from a leaf node

Given a Binary Tree and a positive integer k, print all nodes that
are distance k from a leaf node.

Here the meaning of distance is different from previous post. Here k
distance from a leaf means k levels higher than a leaf node.
For example if k is more than height of Binary Tree, then nothing
should be printed. Expected time complexity is O(n) where n is the
number nodes in the given Binary Tree.

distKfromLeaf

The idea is to traverse the tree. Keep storing all ancestors till we
hit a leaf node. When we reach a leaf node, we print the ancestor at
distance k. We also need to keep track of nodes that are already
printed as output. For that we use a boolean array visited[].
*/

/* Program to print all nodes
which are at distance k from a leaf */
#include <iostream>
using namespace std;
#define MAX_HEIGHT 10000

struct Node
{
    int key;
    Node *left, *right;
};

/* utility that allocates a new Node with the given key */
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

/* This function prints all nodes that are distance k from a leaf node
path[] --> Store ancestors of a node
visited[] --> Stores true if a node is printed as output. A node may be k
                distance away from many leaves, we want to print it once */
void kDistantFromLeafUtil(Node *node, int path[], bool visited[],
                          int pathLen, int k)
{
    // Base case
    if (node == NULL)
        return;

    /* append this Node to the path array */
    path[pathLen] = node->key;
    visited[pathLen] = false;
    pathLen++;

    /* it's a leaf, so print the ancestor at distance k only
    if the ancestor is not already printed */
    if (node->left == NULL &&
        node->right == NULL &&
        pathLen - k - 1 >= 0 &&
        visited[pathLen - k - 1] == false)
    {
        cout << path[pathLen - k - 1] << " ";
        visited[pathLen - k - 1] = true;
        return;
    }

    /* If not leaf node, recur for left and right subtrees */
    kDistantFromLeafUtil(node->left, path, visited, pathLen, k);
    kDistantFromLeafUtil(node->right, path, visited, pathLen, k);
}

/* Given a binary tree and a number k, print all nodes that are k
distant from a leaf*/
void printKDistantfromLeaf(Node *node, int k)
{
    int path[MAX_HEIGHT];
    bool visited[MAX_HEIGHT] = {false};
    kDistantFromLeafUtil(node, path, visited, 0, k);
}

/* Driver code*/
int main()
{
    // Let us create binary tree
    // given in the above example
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    cout << "Nodes at distance 2 are: ";
    printKDistantfromLeaf(root, 2);

    return 0;
}
