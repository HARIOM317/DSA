#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;
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

void push(struct stack *ptr, char value){
    if (isFull(ptr))
    {
        printf("Stack Overflow! Can't push %c to the stack \n", value);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
    
}

char pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Can't pop from the stack \n");
        return -1;
    }
    else{
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
    
}

int paranthisis(char * exp){
    //Create and initialize the stack
    struct stack * sp;
    sp->size = 30;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    
    for (int  i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
           push(sp, '(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char * exp = "8*9/(9-(7+2(-1)+9)/8)";
    if(paranthisis(exp))
    {
        printf("The paranthisis is matching \n");
    }
    else{
        printf("The paranthisis is not matching \n");
    }
    
    return 0;
}