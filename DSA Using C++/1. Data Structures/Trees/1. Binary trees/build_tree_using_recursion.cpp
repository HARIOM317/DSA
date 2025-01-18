#include <iostream>
#include <vector>
#include <queue>

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

Node *buildTreeRecursively(vector<int> &values, int index)
{
    // base case
    if (index >= values.size() || values[index] == -1)
        return NULL;

    // create the current node
    Node *root = new Node(values[index]);

    root->left = buildTreeRecursively(values, 2 * index + 1);
    root->right = buildTreeRecursively(values, 2 * index + 2);

    return root;
}

void printLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
}

int main()
{
    // level order values (-1 indicates no child)
    vector<int> values = {1, 2, 3, 4, 5, 6, -1, 7};

    // create the tree
    Node *root = buildTreeRecursively(values, 0);

    // print level order traversal
    cout << "Level order traversal: " << endl;
    printLevelOrderTraversal(root);

    return 0;
}