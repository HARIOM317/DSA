#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct Queue * q){
    if (q->r == q->f)
    {
        return 1;
    }
        
    return 0;
}

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int value){
    if(isFull(q)){
        printf("Queue Overflow! \n");
    }
    else{
        q->r++;
        q->arr[q->r] = value;
        printf("Enqueue element is : %d \n", value);
    }
}

int dequeue(struct Queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue Underflow! \n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}


int main(){
    struct Queue q;
    q.size = 10;
    q.f = -1;
    q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("\n Before enqueue ! \n");
    if (isEmpty(&q))
    {
        printf("Queue is empty \n");
    }
    else{
        printf("Queue is not empty \n");
    }

    if (isFull(&q))
    {
        printf("Queue is full \n");
    }
    else{
        printf("Queue is not full \n");
    }
    
    // Enqueue Operations
    enqueue(&q, 78);
    enqueue(&q, 34);
    enqueue(&q, 98);
    enqueue(&q, 90);
    enqueue(&q, 34);
    enqueue(&q, 17);
    enqueue(&q, 10);
    enqueue(&q, 30);
    enqueue(&q, 27);
    enqueue(&q, 58);

    printf("\n After enqueue ! \n");
    if (isEmpty(&q))
    {
        printf("Queue is empty \n");
    }
    else{
        printf("Queue is not empty \n");
    }

    if (isFull(&q))
    {
        printf("Queue is full \n");
    }
    else{
        printf("Queue is not full \n");
    }

    // Dequeue operation
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    printf("Dequeuing element is %d \n", dequeue(&q));
    
    printf("\n After dequeue ! \n");
     if (isEmpty(&q))
    {
        printf("Queue is empty \n");
    }
    else{
        printf("Queue is not empty \n");
    }

    if (isFull(&q))
    {
        printf("Queue is full \n");
    }
    else{
        printf("Queue is not full \n");
    }

    enqueue(&q, 27);
   
    return 0;
}