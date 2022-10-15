/*
Given a Balanced Binary Search Tree and a target sum, write a
function that returns true if there is a pair with sum equals to
target sum, otherwise return false. Expected time complexity is O(n)
and only O(Logn) extra space can be used. Any modification
to Binary Search Tree is not allowed.
Note that height of a Balanced BST is always O(Logn).
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{

    // Root of BST
public:
    Node *root;

    // Constructor
    BinarySearchTree()
    {
        root = NULL;
    }

    // Utility function for inorder traversal of the tree
    void inorderUtil(Node *node)
    {
        if (node == NULL)
            return;

        inorderUtil(node->left);
        cout << node->data << " ";
        inorderUtil(node->right);
    }

    // Inorder traversal of the tree
    void inorder()
    {
        inorderUtil(this->root);
    }

    /* A recursive function to insert a new key in BST */
    Node *insertRec(Node *root, int data)
    {

        /* If the tree is empty, return a new node */
        if (root == NULL)
        {
            root = new Node(data);
            return root;
        }

        /* Otherwise, recur down the tree */
        if (data < root->data)
            root->left = insertRec(root->left, data);
        else if (data > root->data)
            root->right = insertRec(root->right, data);

        return root;
    }

    // This method mainly calls insertRec()
    void insert(int key)
    {
        root = insertRec(root, key);
    }

    // Method that adds values of given BST into vector
    // and hence returns the vector
    vector<int> treeToList(Node *node, vector<int> &list)
    {
        // Base Case
        if (node == NULL)
            return list;

        treeToList(node->left, list);
        list.push_back(node->data);
        treeToList(node->right, list);

        return list;
    }

    // method that checks if there is a pair present
    bool isPairPresent(Node *node, int target)
    {
        // This list a1 is passed as an argument
        // in treeToList method
        // which is later on filled by the values of BST
        vector<int> a1;

        // a2 list contains all the values of BST
        // returned by treeToList method
        vector<int> a2 = treeToList(node, a1);

        int start = 0; // Starting index of a2

        int end = (int)a2.size() - 1; // Ending index of a2

        while (start < end)
        {

            if (a2[start] + a2[end] == target) // Target Found!
            {
                cout << "Pair Found: " << a2[start] << " + " << a2[end] << " = " << target << '\n';
                return true;
            }

            if (a2[start] + a2[end] > target) // decrements end
            {
                end--;
            }

            if (a2[start] + a2[end] < target) // increments start
            {
                start++;
            }
        }

        cout << "No such values are found!\n";
        return false;
    }
};

// Driver function
int main()
{
    BinarySearchTree *tree = new BinarySearchTree();
    /*
            15
            /	 \
        10	 20
        / \	 / \
        8 12 16 25 */
    tree->insert(15);
    tree->insert(10);
    tree->insert(20);
    tree->insert(8);
    tree->insert(12);
    tree->insert(16);
    tree->insert(25);

    tree->isPairPresent(tree->root, 33);
}
