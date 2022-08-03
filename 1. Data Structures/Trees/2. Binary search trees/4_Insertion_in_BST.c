#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n;                                 // Creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left children to NULL
    n->right = NULL;                                // Setting the right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder_Traversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder_Traversal(root->left);
        preOrder_Traversal(root->right);
    }
}

void postOrder_Traversal(struct Node *root)
{
    if (root != NULL)
    {
        postOrder_Traversal(root->left);
        postOrder_Traversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrder_Traversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrder_Traversal(root->left);
        printf("%d ", root->data);
        inOrder_Traversal(root->right);
    }
}

void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("\n\nCannot insert %d, it already exist in BST! \n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *New_Node = createNode(key);
    if (key < prev->data)
    {
        prev->left = New_Node;
    }
    else
    {
        prev->right = New_Node;
    }
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    /*
        Binary Search Tree
                5
               / \
              3   6
             / \
            1   4
    */

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("\nPre order Traversal before insertion:  ");
    preOrder_Traversal(p);
    printf("\nPost order Traversal before insertion:  ");
    postOrder_Traversal(p);
    printf("\nIn order Traversal before insertion:  ");
    inOrder_Traversal(p);

    insert(p, 7);
    insert(p, 3);
    insert(p, 14);
    insert(p, 15);
    insert(p, 8);
    insert(p, 35);
    // printf("%d \n", p->right->right->data);

    printf("\n\nPre order Traversal after insertion:  ");
    preOrder_Traversal(p);
    printf("\nPost order Traversal after insertion:  ");
    postOrder_Traversal(p);
    printf("\nIn order Traversal after insertion:  ");
    inOrder_Traversal(p);

    return 0;
}