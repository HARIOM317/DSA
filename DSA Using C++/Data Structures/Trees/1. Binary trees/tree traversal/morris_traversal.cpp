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
        left = right = nullptr;
    }
};

void inorderByMorrisTheorem(Node *root)
{
    Node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left)
        {
            // find predecessor
            Node *pred = curr->left;
            while (pred->right != nullptr && pred->right != curr)
            {
                pred = pred->right;
            }

            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
        else
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
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

    cout << "Inorder Traversal using Morris Traversal : ";
    inorderByMorrisTheorem(root);

    return 0;
}