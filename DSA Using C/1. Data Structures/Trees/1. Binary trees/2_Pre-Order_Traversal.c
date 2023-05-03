#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function for creating a new Node
struct Node *createNode(int data)
{
    struct Node *n;                                 // Creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left children to NULL
    n->right = NULL;                                // Setting the right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrder_Traversal(struct Node * root){
    if (root!=NULL)
    {
        printf("%d ", root->data);
        preOrder_Traversal(root->left);
        preOrder_Traversal(root->right);
    }
    
}

int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder_Traversal(p);
    return 0;
}