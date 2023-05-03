#include<stdio.h>
#include<stdlib.h>

struct stack{
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

int main(){
    // struct stack s;
    // s.size = 80;
    // s.top =-1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

                    // OR

    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    s->arr[0] = 6;
    s->top++;
    s->arr[1] = 12;
    s->top++;
    s->arr[2] = 18;
    s->top++;
    s->arr[3] = 24;
    s->top++;
    s->arr[4] = 30;
    s->top++;
    // s->arr[5] = 60;
    // s->top++;


    
    // Check if Stack is Empty or not
    if(isEmpty(s)){
        printf("Stack is Empty\n");
    }
    else{
        printf("Stack is not Empty\n");
    }
    
    if(isFull(s)){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is not Full\n");
    }
    return 0;
}