// Use any below method to implement Nodes of tree

// Method 1: Using "struct" to make
// user-define data type
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Method 2: Using "class" to make
// user-define data type
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *CreateNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert element in binary tree
Node *InsertNode(Node *root, int data)
{
    // If the tree is empty, assign new node address to root
    if (root == NULL)
    {
        root = CreateNode(data);
        return root;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL.
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = CreateNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

// Driver code
int main()
{
    Node *root = CreateNode(10);
    root->left = CreateNode(11);
    root->left->left = CreateNode(7);
    root->right = CreateNode(9);
    root->right->left = CreateNode(15);
    root->right->right = CreateNode(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key = 12;
    root = InsertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}

// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node
{
    int key;
    struct Node *left, *right;
};

/* function to create a new node of tree and
return pointer */
struct Node *newNode(int key)
{
    struct Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
};

/* Inorder traversal of a binary tree*/
void inorder(struct Node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

/* function to delete the given deepest node
(d_node) in binary tree */
void deletDeepest(struct Node *root,
                  struct Node *d_node)
{
    queue<struct Node *> q;
    q.push(root);

    // Do level order traversal until last node
    struct Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == d_node)
        {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

/* function to delete element in binary tree */
Node *deletion(struct Node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL)
    {
        if (root->key == key)
            return NULL;
        else
            return root;
    }

    queue<struct Node *> q;
    q.push(root);

    struct Node *temp;
    struct Node *key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->key == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL)
    {
        int x = temp->key;
        deletDeepest(root, temp);
        key_node->key = x;
    }
    return root;
}

// Driver code
int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);

    cout << "Inorder traversal before deletion : ";
    inorder(root);

    int key = 11;
    root = deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inorder(root);

    return 0;
}

// C++ implementation of tree using array
// numbering starting from 0 to n-1.
#include <bits/stdc++.h>
using namespace std;
char tree[10];
int root(char key)
{
    if (tree[0] != '\0')
        cout << "Tree already had root";
    else
        tree[0] = key;
    return 0;
}

int set_left(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "\nCan't set child at "
             << (parent * 2) + 1
             << " , no parent found";
    else
        tree[(parent * 2) + 1] = key;
    return 0;
}

int set_right(char key, int parent)
{
    if (tree[parent] == '\0')
        cout << "\nCan't set child at "
             << (parent * 2) + 2
             << " , no parent found";
    else
        tree[(parent * 2) + 2] = key;
    return 0;
}

int print_tree()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
    return 0;
}

// Driver Code
int main()
{
    root('A');
    set_left('B', 0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);
    print_tree();
    return 0;
}
