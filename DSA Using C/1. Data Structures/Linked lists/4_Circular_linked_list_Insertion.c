#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node * head){
    struct Node *ptr = head;
    do
    {
        printf("Element is :  %d \n", ptr->data);
        ptr= ptr->next;
    } while (ptr!=head);
    
}

// Insertion at the first Node
struct Node * InsertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
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
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * forth;
    struct Node * fifth;
    struct Node * sixth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 20;
    head->next = second;
    
    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = forth;
    
    forth->data = 50;
    forth->next = fifth;
    
    fifth->data = 60;
    fifth->next = sixth;
    
    sixth->data = 70;
    sixth->next = head;

    system("cls");
    printf("Liked list Before Traversal\n\n");
    LinkedListTraversal(head);

    // Case 1:
    // printf("\n\nLinked List After insert at First Node\n\n");
    // head = InsertAtFirst(head, 10);
    // head = InsertAtFirst(head, 1);
    // head = InsertAtFirst(head, 0);
    // LinkedListTraversal(head);
    
    // Case 2:
    // printf("\n\nLinked List After insert at any Index\n\n");
    // head = InserAtIndex(head, 10, 1);
    // head = InserAtIndex(head, 33, 3);
    // head = InserAtIndex(head, 25, 5);
    // LinkedListTraversal(head);
    
    // Case 3:
    // printf("\n\nLinked List After insert at the last Node\n\n");
    // head = InserAtEnd(head, 100);
    // head = InserAtEnd(head, 200);
    // head = InserAtEnd(head, 300);
    // LinkedListTraversal(head);
    
    // Case 4:
    printf("\n\nLinked List After insertion at any Node\n\n");
    head = InsertAfterNode(head,third, 100);
    head = InsertAfterNode(head,forth, 200);
    head = InsertAfterNode(head,fifth, 300);
    LinkedListTraversal(head);
    return 0;
}