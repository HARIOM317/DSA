#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int count(Node *root)
{
    if (root == NULL)
        return 0;

    int leftNodes = count(root->left);
    int rightNodes = count(root->right);

    return leftNodes + rightNodes + 1;
}

int main()
{
    // level 1
    Node *root = new Node(10);

    // level 2
    root->left = new Node(20);
    root->right = new Node(30);

    // level 3
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    // level 4
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right->left = new Node(100);

    cout << "Total Nodes in Tree: " << count(root) << endl;

    return 0;
}