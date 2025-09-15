#include <iostream>

using namespace std;

// Node
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

// Inorder traversal (Sorted)
void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// To insert node
Node *insert(Node *root, int val)
{
    Node *newNode = new Node(val);

    if (root == nullptr)
    {
        root = newNode;
        return root;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// To build BST
Node *buildBST(int *arr, int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

// To find a node
bool search(Node *root, int val)
{
    if (root == nullptr)
        return false;
    if (root->data == val)
        return true;
    else if (root->data < val)
        return search(root->right, val);
    else
        return search(root->left, val);
}

int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7, 6, 9, 8, 12, 25, 15, 27, 20};
    int n = sizeof(arr) / sizeof(int);

    Node *root = buildBST(arr, n);
    cout << "Inorder: ";
    inorder(root);

    cout << "\nIs 6 found: " << (search(root, 6) ? "Yes" : "No") << endl;
    cout << "Is 21 found: " << (search(root, 21) ? "Yes" : "No") << endl;
    cout << "Is 15 found: " << (search(root, 15) ? "Yes" : "No") << endl;

    return 0;
}