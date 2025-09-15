#include <iostream>
#include <queue>

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

void inOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // base case
    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();

        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
}

int main()
{
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(100);

    // _____ Traversing Tree _____
    cout << "In Order Traversal : ";
    inOrderTraversal(root);

    cout << "\nPre Order Traversal : ";
    preOrderTraversal(root);

    cout << "\nPost Order Traversal : ";
    postOrderTraversal(root);

    cout << "\nLevel Order Traversal : ";
    levelorderTraversal(root);

    return 0;
}