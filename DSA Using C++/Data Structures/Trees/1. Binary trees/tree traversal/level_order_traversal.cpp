#include <iostream>
#include <queue>
#include <stack>

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

void printLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    // creating a queue for level order traversal
    queue<Node *> q;

    // enqueue root
    q.push(root);
    q.push(NULL); // initial separator for level 1

    while (!q.empty())
    {
        // print front of queue and remove it from queue
        Node *temp = q.front();
        q.pop();

        // to print next line
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // separator for next level
            }
        }
        else
        {
            cout << temp->data << " ";

            // enqueue left child
            if (temp->left)
                q.push(temp->left);

            // enqueue right child
            if (temp->right)
                q.push(temp->right);
        }
    }
}

void printReverseLevelOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    queue<Node *> q;
    q.push(root);
    q.push(NULL); // initial separator for level 1

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            st.push(NULL); // level separator
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // push curr node onto stack
            st.push(temp);

            // enqueue right child
            if (temp->right)
                q.push(temp->right);

            // enqueue left child
            if (temp->left)
                q.push(temp->left);
        }
    }

    // pop all items from stack one by one and print them
    while (!st.empty())
    {
        Node *temp = st.top();
        st.pop();

        if (temp == NULL)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
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

    cout << "\nLevel Order traversal - " << endl
         << endl;
    printLevelOrderTraversal(root); // level 1 -> level 2 -> ... -> level n

    cout << "\n\nReverse Level Order traversal - " << endl;
    printReverseLevelOrderTraversal(root); // level n -> level n-1 -> ... -> 1

    return 0;
}