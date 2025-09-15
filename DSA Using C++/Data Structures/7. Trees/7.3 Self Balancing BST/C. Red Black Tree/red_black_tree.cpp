#include <iostream>

using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        left = right = parent = nullptr;
        this->color = RED;
    }
};

class RedBlackTree
{
private:
    Node *root;

    void leftRotate(Node *&root, Node *&ptr)
    {
        Node *rightPtr = ptr->right;
        ptr->right = rightPtr->left;

        if (rightPtr->left != nullptr)
            rightPtr->left->parent = ptr;

        rightPtr->parent = ptr->parent;

        if (ptr->parent == nullptr)
            root = rightPtr;
        else if (ptr == ptr->parent->left)
            ptr->parent->left = rightPtr;
        else
            ptr->parent->right = rightPtr;

        rightPtr->left = ptr;
        ptr->parent = rightPtr;
    }

    void rightRotate(Node *&root, Node *&ptr)
    {
        Node *leftPtr = ptr->left;
        ptr->left = leftPtr->right;

        if (leftPtr->right != nullptr)
            leftPtr->right->parent = ptr;

        leftPtr->parent = ptr->parent;

        if (ptr->parent == nullptr)
            root = leftPtr;
        else if (ptr == ptr->parent->left)
            ptr->parent->left = leftPtr;
        else
            ptr->parent->right = leftPtr;

        leftPtr->right = ptr;
        ptr->parent = leftPtr;
    }

    void fixInsertViolation(Node *&root, Node *&ptr)
    {
        Node *parentPtr = nullptr;
        Node *grandParentPtr = nullptr;

        while ((ptr != root) && (ptr->color == RED) && (ptr->parent->color == RED))
        {
            parentPtr = ptr->parent;
            grandParentPtr = ptr->parent->parent;

            if (parentPtr == grandParentPtr->left)
            {
                Node *unclePtr = grandParentPtr->right;

                if (unclePtr != nullptr && unclePtr->color == RED)
                {
                    grandParentPtr->color = RED;
                    parentPtr->color = BLACK;
                    unclePtr->color = BLACK;
                    ptr = grandParentPtr; // Move up to fix further violations
                }
                else
                {
                    if (ptr == parentPtr->right)
                    {
                        leftRotate(root, parentPtr);
                        ptr = parentPtr;
                        parentPtr = ptr->parent;
                    }
                    rightRotate(root, grandParentPtr);
                    swap(parentPtr->color, grandParentPtr->color);
                    ptr = parentPtr;
                }
            }
            else
            {
                Node *unclePtr = grandParentPtr->left;

                if ((unclePtr != nullptr) && (unclePtr->color == RED))
                {
                    grandParentPtr->color = RED;
                    parentPtr->color = BLACK;
                    unclePtr->color = BLACK;
                    ptr = grandParentPtr; // Move up to fix further violations
                }
                else
                {
                    if (ptr == parentPtr->left)
                    {
                        rightRotate(root, parentPtr);
                        ptr = parentPtr;
                        parentPtr = ptr->parent;
                    }
                    leftRotate(root, grandParentPtr);
                    swap(parentPtr->color, grandParentPtr->color);
                    ptr = parentPtr;
                }
            }
        }
        root->color = BLACK;
    }

    Node *BSTInsert(Node *root, Node *ptr)
    {
        if (root == nullptr)
            return ptr;

        if (ptr->data < root->data)
        {
            root->left = BSTInsert(root->left, ptr);
            root->left->parent = root;
        }
        else if (ptr->data > root->data)
        {
            root->right = BSTInsert(root->right, ptr);
            root->right->parent = root;
        }

        return root;
    }

    void inorderHelper(Node *root)
    {
        if (root == nullptr)
            return;
        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

    Node *searchHelper(Node *root, int key)
    {
        if (root == nullptr || root->data == key)
            return root;
        if (key < root->data)
            return searchHelper(root->left, key);
        return searchHelper(root->right, key);
    }

    void freeMemory(Node *root)
    {
        if (root == nullptr)
            return;
        freeMemory(root->left);
        freeMemory(root->right);
        delete root;
    }

public:
    RedBlackTree() { root = nullptr; }

    ~RedBlackTree()
    {
        freeMemory(root);
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        root = BSTInsert(root, newNode);
        fixInsertViolation(root, newNode);
    }

    bool find(int key)
    {
        return searchHelper(root, key) != nullptr;
    }

    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }
};

int main()
{
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(35);

    cout << "Inorder Traversal : ";
    tree.inorder();

    int key = 15;
    cout << key << " is present : " << (tree.find(key) ? "Yes" : "No") << endl;

    key = 22;
    cout << key << " is present : " << (tree.find(key) ? "Yes" : "No") << endl;

    return 0;
}
