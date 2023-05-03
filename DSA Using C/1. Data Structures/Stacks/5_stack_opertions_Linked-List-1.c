#include <stdio.h>
#include <stdlib.h>

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

int pop(struct Node **top)
{
    if (isEmpty(*top))
    {
        printf("stack Underflow! \n");
    }
    else
    {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}


int main()
{
    struct Node *top = NULL;
    printf("Before pushing any element (Empty) : %d \n", isEmpty(top));
    printf("Before pushing any element (Full) : %d \n", isFull(top));
    top = push(top, 78);
    top = push(top, 45);
    top = push(top, 76);
    top = push(top, 54);
    top = push(top, 98);
    top = push(top, 67);

    printf("\nBefore popped: \n\n");
    linkedList_Traversal(top);
    printf("\nAfter pushing element (Empty) : %d \n", isEmpty(top));
    printf("After pushing element (Full) : %d \n\n", isFull(top));

    printf("Popped elements: \n");
    printf("Popped element is %d \n", pop(&top));
    printf("Popped element is %d \n", pop(&top));

    printf("\nAfter popped: \n\n");
    linkedList_Traversal(top);

    return 0;
}