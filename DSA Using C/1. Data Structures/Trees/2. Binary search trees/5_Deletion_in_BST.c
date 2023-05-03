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

struct Node * inOrderPredecessor(struct Node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node * delete_Node(struct Node * root, int value){
    struct Node * inPre;
   
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    
    //Search for the Node to be deleted
    if (value < root->data)
    {
        root->left = delete_Node(root->left, value);
    }
    else if (value > root->data)
    {
       root->right = delete_Node(root->right, value);
    }
    // Deletion strategy when the Node is found
    else{
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = delete_Node(root->left, inPre->data);
    }
    return root;
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

    printf("\nPre order Traversal before deletion:  ");
    preOrder_Traversal(p);
    printf("\nPost order Traversal before deletion:  ");
    postOrder_Traversal(p);
    printf("\nIn order Traversal before deletion:  ");
    inOrder_Traversal(p);

    delete_Node(p, 5);
    printf("\nData is: %d", p->data);

    printf("\n\nPre order Traversal after deletion:  ");
    preOrder_Traversal(p);
    printf("\nPost order Traversal after deletion:  ");
    postOrder_Traversal(p);
    printf("\nIn order Traversal after deletion:  ");
    inOrder_Traversal(p);

    return 0;
}