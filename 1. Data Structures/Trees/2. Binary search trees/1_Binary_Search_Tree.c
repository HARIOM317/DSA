#include <stdio.h>
#include<stdlib.h>

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

int isBST(struct Node *root)
{
    static struct Node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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

    if (isBST(p))
    {
        printf("This is a binary search tree! \n");
    }
    else{
        printf("This is not a binary search tree! \n");
    }
    
    return 0;
}