#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }

    // Destructor
    ~Node()
    {
        // cout << "\nDeleted: " << this->data;
        delete left;
        delete right;
    }
};

// To insert new Node
Node *insert(Node *root, int val)
{
    Node *newNode = new Node(val);
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
}

// To Build BST
Node *buildBST(int *arr, int n)
{
    Node *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    return root;
}

// To print its inorder traversal
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// To get inorder successor of a node
Node *getInorderSuccessor(Node *curr)
{
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}

// To delete a node
Node *deleteNode(Node *root, int target)
{
    if (root == nullptr)
        return nullptr;

    // find target node
    if (target < root->data)
    {
        root->left = deleteNode(root->left, target);
    }
    else if (target > root->data)
    {
        root->right = deleteNode(root->right, target);
    }
    else
    {
        // case-1: 0 child (delete leaf node)
        if (root->left == nullptr && root->right == nullptr)
        {
            root->left = root->right = nullptr;
            delete root;
            return nullptr;
        }

        // case-2: 1 child
        if (root->left == nullptr || root->right == nullptr)
        {

            Node *next = (root->left == nullptr) ? root->right : root->left;
            root->left = root->right = nullptr;
            delete root;
            return next;
        }

        // case-3: 2 child
        Node *inorderSuccessor = getInorderSuccessor(root->right);
        root->data = inorderSuccessor->data;
        root->right = deleteNode(root->right, inorderSuccessor->data);
    }

    return root;
}

int main()
{
    int arr[] = {6, 7, 3, 4, 8, 1, 5, 9, 10, 2};
    int n = sizeof(arr) / sizeof(int);

    Node *root = buildBST(arr, n);
    cout << "Inorder Sequence: ";
    inorder(root);

    // Delete nodes
    root = deleteNode(root, 2);  // leaf node
    root = deleteNode(root, 8);  // 1-child node
    root = deleteNode(root, 3);  // 2-child node
    root = deleteNode(root, 6);  // root node
    root = deleteNode(root, 11); // not present

    cout << "\nInorder Sequence: ";
    inorder(root);

    // delete remaining tree
    cout << "\n\nDeleting BST from memory...\n";
    delete root;

    return 0;
}