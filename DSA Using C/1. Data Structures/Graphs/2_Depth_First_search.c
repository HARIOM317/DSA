#include <stdio.h>
#include <stdlib.h>

// DFS Implementation

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue Overflow! \n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqueue element: %d \n", val);
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue Underflow! \n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }   
    }
}

int main()
{
    printf("DFS Traversal of tree is: \n");
    // printf("From 0: ");
    // DFS(0);
    // printf("\nFrom 1: ");
    // DFS(1);
    printf("\nFrom 4: ");
    DFS(4);

    return 0;
}