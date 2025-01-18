#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void insert(Node *&root, int data)
{
    Node *newNode = new Node(data);

    if (root == NULL)
    {
        root = newNode;
        return;
    }

    if (data < root->data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void deleteTree(Node *&root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
    root = NULL;
}

int main()
{
    Node *root = NULL;
    insert(root, 20);
    insert(root, 30);
    insert(root, 10);
    insert(root, 15);
    insert(root, 5);
    insert(root, 25);
    insert(root, 35);
    insert(root, 45);
    insert(root, 40);
    insert(root, 50);

    cout << "Inorder of BST : ";
    inorder(root);

    // free allocated memory
    deleteTree(root);

    return 0;
}