#include <iostream>
using namespace std;

static int index = -1;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// build tree using preorder sequence
Node *buildTree(int *preorder)
{
    index++;

    // base case
    if (preorder[index] == -1)
        return nullptr;

    // create Node
    Node *root = new Node(preorder[index]);

    root->left = buildTree(preorder);  // build left subtree
    root->right = buildTree(preorder); // build right subtree

    return root; // return root of tree
}

// print preorder sequence
void preorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    int preorder[] = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(preorder);
    preorderTraversal(root);

    return 0;
}