#include <stdio.h>  
#define size 5    
int deque[size];  
int f=-1, r=-1;  
//  enqueue_front function will insert the value from the front  
void enqueue_front(int x)  
{  
    if((f==0 && r==size-1) || (f==r+1))  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        f=r=0;  
        deque[f]=x;  
    }  
    else if(f==0)  
    {  
        f=size-1;  
        deque[f]=x;  
    }  
    else  
    {  
        f=f-1;  
        deque[f]=x;  
    }  
}  
  
// enqueue_rear function will insert the value from the rear  
void enqueue_rear(int x)  
{  
    if((f==0 && r==size-1) || (f==r+1))  
    {  
        printf("deque is full");  
    }  
    else if((f==-1) && (r==-1))  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else if(r==size-1)  
    {  
        r=0;  
        deque[r]=x;  
    }  
    else  
    {  
        r++;  
        deque[r]=x;  
    }  
  
}  
  
// display function prints all the value of deque.  
void display()  
{  
    int i=f;  
    printf("\n Elements in a deque : ");  
      
    while(i!=r)  
    {  
        printf("%d ",deque[i]);  
        i=(i+1)%size;  
    }  
     printf("%d",deque[r]);  
}  
  
// getfront function retrieves the first value of the deque.  
void getfront()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else  
    {  
        printf("\nThe value of the front is: %d", deque[f]);  
    }  
      
}  
  
// getrear function retrieves the last value of the deque.  
void getrear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else  
    {  
        printf("\nThe value of the rear is: %d", deque[r]);  
    }  
      
}  
  
// dequeue_front() function deletes the element from the front  
void dequeue_front()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[f]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(f==(size-1))  
     {  
         printf("\nThe deleted element is %d", deque[f]);  
         f=0;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[f]);  
          f=f+1;  
     }  
}  
  
// dequeue_rear() function deletes the element from the rear  
void dequeue_rear()  
{  
    if((f==-1) && (r==-1))  
    {  
        printf("Deque is empty");  
    }  
    else if(f==r)  
    {  
        printf("\nThe deleted element is %d", deque[r]);  
        f=-1;  
        r=-1;  
          
    }  
     else if(r==0)  
     {  
         printf("\nThe deleted element is %d", deque[r]);  
         r=size-1;  
     }  
     else  
     {  
          printf("\nThe deleted element is %d", deque[r]);  
          r=r-1;  
     }  
}  
  
int main()  
{  
   // inserting a value from the front.  
    enqueue_front(2);  
  // inserting a value from the front.  
    enqueue_front(1);  
  // inserting a value from the rear.  
    enqueue_rear(3);  
  // inserting a value from the rear.  
    enqueue_rear(5);  
  // inserting a value from the rear.  
    enqueue_rear(8);  
  // Calling the display function to retrieve the values of deque  
    display();  
 // Retrieve the front value  
    getfront();  
// Retrieve the rear value.  
    getrear();  
// deleting a value from the front  
dequeue_front();  
//deleting a value from the rear  
dequeue_rear();  
 // Calling the display function to retrieve the values of deque  
 display();  
    return 0;  
}  