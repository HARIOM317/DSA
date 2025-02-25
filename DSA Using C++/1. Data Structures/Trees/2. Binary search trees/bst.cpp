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

int min(Node *root)
{
    Node *curr = root;
    while (curr->left != NULL)
        curr = curr->left;
    return curr->data;
}

int max(Node *root)
{
    Node *curr = root;
    while (curr->right != NULL)
        curr = curr->right;
    return curr->data;
}

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

Node *deleteNode(Node *root, int value)
{
    // base case
    if (root == NULL)
        return root;

    if (root->data == value)
    {
        // case 1: 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // case 2: 1 child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case 3: 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minimum = min(root->right);
            root->data = minimum;
            root->right = deleteNode(root->right, minimum);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->left = deleteNode(root->left, value);
        return root;
    }
    else
    {
        root->right = deleteNode(root->right, value);
        return root;
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

bool find(Node *root, int data)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->data == data)
            return true;
        else if (curr->data > data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
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

int inorderPredecessor(Node *root, int data)
{
    Node *curr = root;
    int predecessor = -1;

    while (curr != NULL)
    {
        if (curr->data < data)
        {
            predecessor = curr->data;
            curr = curr->right;
        }
        else if (curr->data > data)
        {
            curr = curr->left;
        }
        else
        { // data node
            // find the maximum in the left subtree if available
            if (curr->left != NULL)
            {
                Node *temp = curr->left;
                while (temp->right != NULL)
                {
                    temp = temp->right;
                }
                predecessor = temp->data;
            }
            break;
        }
    }

    return predecessor;
}

int inorderSuccessor(Node *root, int data)
{
    Node *curr = root;
    int successor = -1;

    while (curr != NULL)
    {
        if (curr->data < data)
        {
            curr = curr->right;
        }
        else if (curr->data > data)
        {
            successor = curr->data;
            curr = curr->left;
        }
        else
        {
            // data node
            // find the minimum in the right subtree if available
            if (curr->right != NULL)
            {
                Node *temp = curr->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                successor = temp->data;
            }
            break;
        }
    }

    return successor;
}

int main()
{
    Node *root = NULL;

    // insertion
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

    // deletion
    root = deleteNode(root, 20);
    root = deleteNode(root, 30);
    root = deleteNode(root, 40);

    cout << "Inorder of BST : ";
    inorder(root);

    int n = 15;

    cout << "\nInorder Predecessor of " << n << " : " << inorderPredecessor(root, n) << endl;
    cout << "Inorder Successor of " << n << " : " << inorderSuccessor(root, n) << endl;

    cout << "\nIs " << n << " present : " << (find(root, 25) ? "Yes" : "No") << endl;

    cout << "Minimum : " << min(root) << endl;
    cout << "Maximum : " << max(root) << endl;

    // free allocated memory
    deleteTree(root);

    return 0;
}