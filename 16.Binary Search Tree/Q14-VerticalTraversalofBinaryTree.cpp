/*
Print a Binary Tree in Vertical Order | Set 1

Given a binary tree, print it vertically. The following example
illustrates vertical order traversal.


           1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9


The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9


print-binary-tree-in-vertical-order
*/

#include <iostream>
using namespace std;

// A node of binary tree
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new Binary Tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to find min and max distances with respect
// to root.
void findMinMax(Node *node, int *min, int *max, int hd)
{
    // Base case
    if (node == NULL)
        return;

    // Update min and max
    if (hd < *min)
        *min = hd;
    else if (hd > *max)
        *max = hd;

    // Recur for left and right subtrees
    findMinMax(node->left, min, max, hd - 1);
    findMinMax(node->right, min, max, hd + 1);
}

// A utility function to print all nodes on a given line_no.
// hd is horizontal distance of current node with respect to root.
void printVerticalLine(Node *node, int line_no, int hd)
{
    // Base case
    if (node == NULL)
        return;

    // If this node is on the given line number
    if (hd == line_no)
        cout << node->data << " ";

    // Recur for left and right subtrees
    printVerticalLine(node->left, line_no, hd - 1);
    printVerticalLine(node->right, line_no, hd + 1);
}

// The main function that prints a given binary tree in
// vertical order
void verticalOrder(Node *root)
{
    // Find min and max distances with resepect to root
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);

    // Iterate through all possible vertical lines starting
    // from the leftmost line and print nodes line by line
    for (int line_no = min; line_no <= max; line_no++)
    {
        printVerticalLine(root, line_no, 0);
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    verticalOrder(root);

    return 0;
}

// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Utility function to store vertical order in map 'm'
// 'hd' is horizontal distance of current node from root.
// 'hd' is initially passed as 0
void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    // Base case
    if (root == NULL)
        return;

    // Store current node in map 'm'
    m[hd].push_back(root->key);

    // Store nodes in left subtree
    getVerticalOrder(root->left, hd - 1, m);

    // Store nodes in right subtree
    getVerticalOrder(root->right, hd + 1, m);
}

// The main function to print vertical order of a binary tree
// with the given root
void printVerticalOrder(Node *root)
{
    // Create a map and store vertical order in map using
    // function getVerticalOrder()
    map<int, vector<int>> m;
    int hd = 0;
    getVerticalOrder(root, hd, m);

    // Traverse the map and print nodes at every horizontal
    // distance (hd)
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n";
    printVerticalOrder(root);
    return 0;
}

// C++ program for printing vertical order
// of a given binary tree using BFS.
#include <bits/stdc++.h>

using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// The main function to print vertical order of a
// binary tree with given root
void printVerticalOrder(Node *root)
{
    // Base case
    if (!root)
        return;

    // Create a map and store vertical order in
    // map using function getVerticalOrder()
    map<int, vector<int>> m;
    int hd = 0;

    // Create queue to do level order traversal.
    // Every item of queue contains node and
    // horizontal distance.
    queue<pair<Node *, int>> que;
    que.push(make_pair(root, hd));

    while (!que.empty())
    {
        // pop from queue front
        pair<Node *, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node *node = temp.first;

        // insert this node's data in vector of hash
        m[hd].push_back(node->key);

        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }

    // Traverse the map and print nodes at
    // every horizontal distance (hd)
    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}
