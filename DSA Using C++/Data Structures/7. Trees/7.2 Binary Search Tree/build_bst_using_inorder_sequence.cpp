#include <iostream>
#include <vector>

using namespace std;

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

Node *buildBST(vector<int> &inorder, int st, int end)
{
    // base case
    if (st > end)
        return nullptr;

    int mid = st + (end - st) / 2;
    Node *root = new Node(inorder[mid]);

    root->left = buildBST(inorder, st, mid - 1);
    root->right = buildBST(inorder, mid + 1, end);

    return root;
}

Node *inorderToBST(vector<int> &inorder)
{
    Node *root = buildBST(inorder, 0, inorder.size() - 1);
    return root;
}

// Inorder sequence
void inorderSequence(Node *root)
{
    if (root == nullptr)
        return;

    inorderSequence(root->left);
    cout << root->data << " ";
    inorderSequence(root->right);
}

// Preorder sequence
void preorderSequence(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderSequence(root->left);
    preorderSequence(root->right);
}

// Postorder sequence
void postorderSequence(Node *root)
{
    if (root == nullptr)
        return;

    postorderSequence(root->left);
    postorderSequence(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> inorder = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Node *root = inorderToBST(inorder);

    cout << "\nInorder Sequence: ";
    inorderSequence(root);

    cout << "\nPreorder Sequence: ";
    preorderSequence(root);

    cout << "\nPostorder Sequence: ";
    postorderSequence(root);

    return 0;
}