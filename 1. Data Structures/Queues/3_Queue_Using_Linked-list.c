#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("\nPrinting the elements of this Queue: \n\n");
    while (ptr != NULL)
    {
        printf("Element is :  %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *n = f;

    if (f == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        f = f->next;
        val = n->data;
        free(n);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element is %d \n\n", dequeue());
    printf("Enqueue the elements: \n");
    enqueue(36);
    enqueue(18);
    enqueue(57);
    enqueue(98);
    enqueue(67);
    linkedListTraversal(f);

    printf("\nDequeue the elements: \n");
    printf("Dequeuing element is %d \n", dequeue());
    printf("Dequeuing element is %d \n", dequeue());
    printf("Dequeuing element is %d \n", dequeue());

    linkedListTraversal(f);

    return 0;
}