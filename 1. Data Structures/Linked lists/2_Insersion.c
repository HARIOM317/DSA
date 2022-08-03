#include<stdio.h>
#include<stdlib.h>

struct Node{
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

// insersion at the beggining
struct Node * InserAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr;
}

// insersion at any index
struct Node * InserAtIndex(struct Node * head, int data, int index){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));   
    struct Node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    
    return head;
}

// insersion at the end
struct Node * InserAtEnd(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;
    
    return head;
}

// Insersion after any node
struct Node * InsertAfterNode(struct Node *head, struct Node *PrevNode, int data){
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = PrevNode->next;
    PrevNode->next = ptr;
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
    fifth->data = 90;
    fifth->next = NULL;

    system("cls");
    traversal(head);

    //Case 1:
    //printf("\n\nAfter Insertion at the first \n\n");
    //head = InserAtFirst(head, 58);
    //traversal(head);

    //Case 2:
    //printf("\n\nAfter Insertion in between \n\n");
    //head = InserAtIndex(head, 786, 3);
    //traversal(head);

    //Case 3:
    //printf("\n\nAfter Insertion at the end \n\n");
    //head = InserAtEnd(head, 420);
    //traversal(head);
    
    //Case 4:
    printf("\n\nInsertion after any Node \n\n");
    head = InsertAfterNode(head, third, 484);
    traversal(head);

    return 0;
}