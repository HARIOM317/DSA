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

Node *createTree(vector<int> &values)
{
    if (values.empty())
        return NULL;

    // create the root node
    Node *root = new Node(values[0]);

    // create queue to keep track of nodes
    queue<Node *> q;
    q.push(root);

    int i = 1; // index to track the next value in the array
    while (!q.empty() && i < values.size())
    {
        Node *curr = q.front();
        q.pop();

        // add the left child if it exist
        if (values[i] != -1)
        {
            curr->left = new Node(values[i]);
            q.push(curr->left);
        }
        i++;

        // add the right child if it exist
        if (i < values.size() && values[i] != -1)
        {
            curr->right = new Node(values[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

// function to print level order traversal
void printLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    // level order values (-1 indicates no child)
    vector<int> values = {1, 2, 3, 4, 5, 6, -1, 7};

    // create the tree
    Node *root = createTree(values);

    // print level order traversal
    cout << "Level order traversal: " << endl;
    printLevelOrderTraversal(root);

    return 0;
}