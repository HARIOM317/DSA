#include <iostream>
#include <queue>

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

// Iterative approach
void printKthLevel(Node *root, int k)
{
    queue<Node *> q;
    int level = 1;

    q.push(root);
    q.push(NULL); // to mark level

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            level++;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            if (level == k)
                cout << curr->data << " ";
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    cout << endl;
}

// Recursive approach
void printKthLevel2(Node *root, int x, int k)
{
    if (root == NULL || x > k)
        return;

    if (x == k)
        cout << root->data << " ";

    printKthLevel2(root->left, x + 1, k);
    printKthLevel2(root->right, x + 1, k);
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

    printKthLevel(root, 3);
    printKthLevel2(root, 1, 3);

    return 0;
}