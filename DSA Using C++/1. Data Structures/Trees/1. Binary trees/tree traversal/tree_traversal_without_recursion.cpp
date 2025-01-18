#include <iostream>
#include <stack>

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

void inOrderTraversal(Node *root)
{
    stack<Node *> st;
    Node *curr = root;

    while (!st.empty() || curr != NULL)
    {
        // Reach the left most node of the current node
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        // curr is NULL at this point
        curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // Move to the right sub tree
        curr = curr->right;
    }
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        // visit the node
        Node *curr = st.top();
        st.pop();
        cout << curr->data << " ";

        // push right child
        if (curr->right != NULL)
            st.push(curr->right);

        // push left chile
        if (curr->left != NULL)
            st.push(curr->left);
    }
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        Node *curr = st1.top();
        st1.pop();
        st2.push(curr);

        // push left child in st1
        if (curr->left != NULL)
            st1.push(curr->left);

        // push right child in st1
        if (curr->right != NULL)
            st1.push(curr->right);
    }

    // pop all elements from the second stack and print them to visit in post order
    while (!st2.empty())
    {
        Node *temp = st2.top();
        st2.pop();
        cout << temp->data << " ";
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

    // _____ Traversing Tree _____
    cout << "In Order Traversal : ";
    inOrderTraversal(root);

    cout << "\nPre Order Traversal : ";
    preOrderTraversal(root);

    cout << "\nPost Order Traversal : ";
    postOrderTraversal(root);

    return 0;
}