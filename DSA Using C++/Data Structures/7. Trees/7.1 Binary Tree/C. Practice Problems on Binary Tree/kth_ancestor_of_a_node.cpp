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

// helper function
int getDistance(Node *root, int node, int k, int &ans)
{
    if (root == NULL)
        return -1;
    if (root->data == node)
        return 0;

    int leftDist = getDistance(root->left, node, k, ans);
    int rightDist = getDistance(root->right, node, k, ans);

    if (leftDist == -1 && rightDist == -1)
        return -1;

    int validDist = (leftDist == -1) ? rightDist : leftDist;
    if (validDist + 1 == k)
        ans = root->data;

    return validDist + 1;
}

int kthAncestor(Node *root, int node, int k)
{
    int ans = -1;
    getDistance(root, node, k, ans);
    return ans;
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

    cout << "1st Ancestor of Node 90: " << kthAncestor(root, 90, 1) << endl;
    cout << "2nd Ancestor of Node 90: " << kthAncestor(root, 90, 2) << endl;
    cout << "3rd Ancestor of Node 90: " << kthAncestor(root, 90, 3) << endl;
    cout << "4th Ancestor of Node 90: " << kthAncestor(root, 90, 4) << endl;

    return 0;
}