#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void Traversal_front(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// insersion at the beggining
struct Node * InserAtFirst(struct Node * head, int data)
{
    struct Node * ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    head->prev = ptr;
    ptr->prev = NULL;
    head = ptr;
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
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * forth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;
    
    third->data = 30;
    third->next = forth;
    third->prev = second;

    forth->data = 40;
    forth->next = fifth;
    forth->prev = third;

    fifth->data = 50;
    fifth->next = sixth;
    fifth->prev = forth;

    sixth->data = 60;
    sixth->next = NULL;
    sixth->prev = fifth;

    system("cls");
    printf("\n\nBefore Insertion\n\n");
    Traversal_front(head);

    // Case 1:
    printf("\n\nAfter Insertion\n\n");
    head = InserAtFirst(head, 100);
    head = InserAtFirst(head, 500);
    head = InserAtFirst(head, 11);
    Traversal_front(head);

    // Case 2:
    // printf("\n\nAfter Insertion\n\n");
    // head = InserAtIndex(head, 101, 3);
    // head = InserAtIndex(head, 575, 2);
    // Traversal_front(head);

    // Case 3:
    // printf("\n\nAfter Insertion\n\n");
    // head = InserAtEnd(head, 1000);
    // head = InserAtEnd(head, 5000);
    // Traversal_front(head);

    // Case 4:
    // printf("\n\nAfter Insertion\n\n");
    // head = InsertAfterNode(head, second,1200);
    // head = InsertAfterNode(head, third,1500);
    // Traversal_front(head);

    return 0;
}