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

int peek(struct stack * sp, int i){
    int arr_index = sp->top - i + 1;
    if (arr_index < 0)
    {
        printf("\n Not a valid position for the stack \n");
        return -1;
    }
    else{
        return sp->arr[arr_index];
    }
    
}

int main(){
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));   

    // printf("\nBefore Pushing (Full): %d \n", isFull(s));
    // printf("Before Pushing (Empty): %d \n", isEmpty(s));

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
   
    
    // printf("\nAfter Pushing (Full): %d \n", isFull(s));
    // printf("After Pushing (Empty): %d \n", isEmpty(s));

    // printf("\nPopped %d from the Stack \n", pop(s));
    // printf("Popped %d from the Stack \n", pop(s));
    // printf("Popped %d from the Stack \n", pop(s));
    // printf("Popped %d from the Stack \n\n", pop(s));

    for(int j = 1 ; j <= s->top + 1; j++){
        printf("The value at position %d is %d \n", j, peek(s, j));
    }
      
    return 0;
}