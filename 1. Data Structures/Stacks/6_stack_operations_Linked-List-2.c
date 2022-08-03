#include <stdio.h>
#include <stdlib.h>

struct Node *top = NULL;  // Initialize top as a global variable

struct Node
{
    int data;
    struct Node *next;
};

void linkedList_Traversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element is : %d \n", ptr->data);
        ptr = ptr->next;
    }
    
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("stack Overflow! \n");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(struct Node *first)
{
    if (isEmpty(first))
    {
        printf("stack Underflow! \n");
    }
    else
    {
        struct Node *n = first;
        top = first->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(int pos){
    struct Node *ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
    
}

int stackTop(){
    return top->data;
}


int main()
{
    system("cls");
    printf("Before pushing any element (Empty) : %d \n", isEmpty(top));
    printf("Before pushing any element (Full) : %d \n", isFull(top));
    top = push(top, 78);
    top = push(top, 45);
    top = push(top, 76);
    top = push(top, 54);
    top = push(top, 98);
    top = push(top, 67);

    printf("\nBefore popped: \n\n");

    printf("Top element is %d \n", stackTop());
    
    for (int i = 1; i <= 6 ; i++)
    {
        printf("Value at position %d is %d \n", i, peek(i));
    }
    

    // linkedList_Traversal(top);
    printf("\nAfter pushing element (Empty) : %d \n", isEmpty(top));
    printf("After pushing element (Full) : %d \n\n", isFull(top));

    printf("Popped elements: \n");
    printf("Popped element is %d \n", pop(top));
    printf("Popped element is %d \n", pop(top));

    printf("\nAfter popped: \n\n");
    linkedList_Traversal(top);

    return 0;
}