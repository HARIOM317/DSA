#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// Function to get height of a tree
int getHeight(Node *node)
{
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int getBalanceFactor(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right Rotation (LL Rotation)
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x; // new root
}

// Left Rotation (RR Rotation)
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Perform Rotation
    y->left = x;
    x->right = T2;

    // Update height
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y; // new root
}

// To insert a new node in AVL Tree
Node *insert(Node *root, int data)
{
    // Step-1 : Normal BST insertion
    if (!root)
        return new Node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root; // No duplicate node allowed

    // Step-2 : Update Height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Step-3 : Get balance factor
    int balance = getBalanceFactor(root);

    // Step-4 : Perform rotation if needed
    if (balance > 1 && data < root->left->data)
    {
        return rightRotate(root); // LL Case (Right Rotation)
    }
    if (balance < -1 && data > root->right->data)
    {
        return leftRotate(root); // RR Case (Left Rotation)
    }
    if (balance > 1 && data > root->left->data)
    {
        // LR Rotation
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data < root->right->data)
    {
        // RL Case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// To get the node with minimum value (used in deletion)
Node *getMinValueNode(Node *root)
{
    Node *curr = root;
    while (curr->left)
    {
        curr = curr->left;
    }
    return curr;
}

// Delete function for AVL Tree
Node *deleteNode(Node *root, int data)
{
    if (!root)
        return root;

    // Step-1 : Normal BST Deletion
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // case-1 : 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // case-2 : 1 child
        if (root->left != nullptr && root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // case-3 : 2 childs
        if (root->left != nullptr && root->right != nullptr)
        {
            Node *temp = getMinValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // check if tree become empty
    if (!root)
        return root;

    // Step-2 : update height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Step-3 : get balance factor
    int balance = getBalanceFactor(root);

    // Step-4 : perform rotation if needed
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
    {
        // LL case
        return rightRotate(root);
    }
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        // LR case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
    {
        // RR case
        return leftRotate(root);
    }
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        // RL case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// To search a node
bool find(Node *root, int data)
{
    if (root == nullptr)
        return false;

    if (root->data == data)
        return true;
    else if (data < root->data)
        return find(root->left, data);
    else
        return find(root->right, data);
}

// tree traversal (sorted order)
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    // Insert nodes in AVL tree
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 50);
    root = insert(root, 5);

    cout << "Inorder Traversal : ";
    inorder(root);

    // Search operation
    int key = 25;
    cout << "\nIs " << key << " present : " << (find(root, key) ? "Yes" : "No") << endl;

    // Deletion
    root = deleteNode(root, 20);
    root = deleteNode(root, 5);

    cout << "Inorder Traversal after deletion : ";
    inorder(root);

    return 0;
}