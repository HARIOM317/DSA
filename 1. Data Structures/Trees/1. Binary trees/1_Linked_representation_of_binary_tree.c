#include<stdio.h>
#include<malloc.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

// Function for creating a new Node
struct Node * createNode(int data){
    struct Node * n;    //Creating a node pointer
    n = (struct Node *)malloc(sizeof(struct Node)); //Allocating memory in the heap
    n->data = data; //Setting the data
    n->left = NULL; //Setting the left children to NULL
    n->right = NULL; //Setting the right children to NULL
    return n;   //Finally returning the created node
}

int main(){
    /*
    **********THIS A THE WAY FOR CREATING A NEW NODE BUT IT IS REPEATING WAY*********

    // Constructing the root Node
    struct Node * p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 7;
    p->left = NULL;
    p->right = NULL;

    // Constructing the secondNode
    struct Node * p1;
    p1 = (struct Node *)malloc(sizeof(struct Node));
    p1->data = 35;
    p1->left = NULL;
    p1->right = NULL;
    
    // Constructing the third Node
    struct Node * p2;
    p2 = (struct Node *)malloc(sizeof(struct Node));
    p2->data = 9;
    p2->left = NULL;
    p2->right = NULL;

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    */

   // *********CREATING A NEW NODE BY USING FUNCTION********

   struct Node * p = createNode(5);
   struct Node * p1 = createNode(7);
   struct Node * p2 = createNode(9);

   // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}