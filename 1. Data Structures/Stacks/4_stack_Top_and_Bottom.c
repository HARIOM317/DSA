#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack * ptr){
    if (ptr->top == ptr->size-1)
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

int stack_Top(struct stack * ptr){
    return ptr->arr[ptr->top];
}

int stack_Bottom(struct stack * ptr){
    return ptr->arr[0];
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 58);
    push(s, 23);
    push(s, 50);
    push(s, 34);
    push(s, 98);
    push(s, 57);
    push(s, 98);
    push(s, 50);
    push(s, 65);
    push(s, 45);
    push(s, 75);
    push(s, 658);
    push(s, 605);
    push(s, 657);

    pop(s);
    pop(s);
    pop(s);

    printf("The top most element of stack is: %d \n", stack_Top(s));
    printf("The bottom most element of stack is: %d \n", stack_Bottom(s));

    return 0;
}