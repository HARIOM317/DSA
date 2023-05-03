#include <iostream>

using namespace std;

// class for creating nodes
class node{
    public:
    int data;
    node * next;

    node (int val){
        data = val;
        next = NULL;
    }
};

// Insertion at the end of the linked list
void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if (head==NULL)
    {
        head = n;
        return;
    }
    
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

// Insertion at the front of the linked list
void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n->next = head;
    head = n;
}

// Traversal linked list
void display(node* head){
    node* temp = head;
    cout<<"\n\n";
    while (temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool search(node* head, int key){
    node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

void deletion(node* &head, int val){
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    
    
    node* temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

int main(){
    node* head = NULL;
    // inserting node at the end of the list
    insertAtTail(head, 1);
    insertAtTail(head, 4);
    insertAtTail(head, 16);
    insertAtTail(head, 9);
    insertAtTail(head, 11);
    insertAtTail(head, 5);

    // inserting node at the front of the list
    insertAtHead(head, 10);
    insertAtHead(head, 100);
    insertAtHead(head, 50);
    insertAtHead(head, 6);

    display(head);

    // searching element
    cout<<"\n"<<search(head, 100);

    deletion(head,10);
    deleteAtHead(head);
    display(head);

    return 0;
}