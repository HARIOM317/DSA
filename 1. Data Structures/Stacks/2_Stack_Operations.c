#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if (ptr->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }   
}

int isFull(struct stack * ptr){
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else{
        return 0;
    }  
}

void push(struct stack *ptr, int value){
    if (isFull(ptr))
    {
        printf("Stack Overflow! Can't push %d to the stack \n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    
}

int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Can't pop from the stack \n");
        return -1;
    }
    else{
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
    
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));   

    printf("\nBefore Pushing (Full): %d \n", isFull(s));
    printf("Before Pushing (Empty): %d \n", isEmpty(s));
    push(s, 58);
    push(s, 23);
    push(s, 50);
    push(s, 34);
    push(s, 98);
    push(s, 57);
    push(s, 98);
    push(s, 50);
    push(s, 65);
    push(s, 59);     //Maximum elements has been pushed in the stack
    push(s, 509);    //Stack Overflow condition since 11th element.
    printf("\nAfter Pushing (Full): %d \n", isFull(s));
    printf("After Pushing (Empty): %d \n", isEmpty(s));

    printf("\nPopped %d from the Stack \n", pop(s));
    
    printf("\nAfter Popped 1 element (Full): %d \n", isFull(s));
    printf("After Popped 1 element (Empty): %d \n", isEmpty(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));
    printf("\nPopped %d from the Stack \n", pop(s));

    printf("\nAfter Popped all elements (Full): %d \n", isFull(s));
    printf("After Popped all elements (Empty): %d \n", isEmpty(s));
    
    printf("\nPopped %d from the Stack \n", pop(s));
    
    return 0;
}