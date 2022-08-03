#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void traversal(struct Node * ptr){
    while (ptr != NULL)
    {
        printf("Element :  %d\n", ptr->data);
        ptr = ptr->next;
    }   
}

// Case 1: For deleting first element of the linked list
struct Node * DeleteAtFirst(struct Node * head)
{
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node * DeleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3: For deleting last element of the linked list
struct Node * DeleteAtLast(struct Node * head){
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
    
}

//Deleting a element with a given value from linked list
struct Node * DeleteValue(struct Node * head, int value){
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    
    return head;
    
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fifth;

     // Allocate memory for nodes in the linked list in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second Nodes
    head->data = 84;
    head->next = second;

    // Link second and third Nodes
    second->data = 101;
    second->next = third;

    // Link third and forth Nodes
    third->data = 534;
    third->next = forth;

    // Link forth and fifth Nodes
    forth->data = 504;
    forth->next = fifth;

    // Terminate the list at the fifth node
    fifth->data = 101;
    fifth->next = NULL;

    system("cls");
    printf("\n\nBefore Deletion:\n\n");
    traversal(head);

    // Case 1:
    // printf("\n\nAfter Deletion:\n\n");
    // head = DeleteAtFirst(head);
    // traversal(head);

    // Case 2:
    // printf("\n\nAfter Deletion:\n\n");
    // head = DeleteAtIndex(head, 2);
    // traversal(head);
    
    // Case 3:
    // printf("\n\nAfter Deletion:\n\n");
    // head = DeleteAtLast(head);
    // traversal(head);
    
    // Case 4:
    printf("\n\nAfter Deletion:\n\n");
    head = DeleteValue(head, 101);
    traversal(head);
    return 0;
}