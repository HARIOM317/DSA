#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Deleted: " << value << endl;
    }
};

// function to insert new node at head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // creating new node
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

// __________ 1. INSERTION __________

// function to insert new node at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // creating new node
    Node *newNode = new Node(data);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// function to insert new node at given index
void insertAtIndex(Node *&head, Node *&tail, int data, int index)
{
    // case 1 - invalid index
    if (index < 0)
    {
        cout << "Invalid Index!" << endl;
        return;
    }

    // case 2 - insert at first
    if (index == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // traversing to get the index node
    Node *temp = head;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    // case 3 - index out of bound
    if (temp == NULL)
    {
        cout << "Index out of bound!" << endl;
        delete temp;
        return;
    }

    // case 4 - insert at last
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // case 5 - insert at middle
    // creating new node
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// __________ 2. TRAVERSAL __________

// function to print linked list
void print(Node *&head)
{
    Node *temp = head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
    delete temp;
}

// __________ 3. DELETION __________

void deleteHead(Node *&head)
{
    Node *toDelete = head;
    head = head->next;
    toDelete->next = NULL;
    delete toDelete;
}

void deleteAtIndex(Node *&head, Node *&tail, int index)
{
    // case 1 - invalid index
    if (index < 0)
    {
        cout << "Invalid index!" << endl;
        return;
    }

    // case 2 - delete first node
    if (index == 0)
    {
        deleteHead(head);
        return;
    }

    Node *prev = NULL;
    Node *curr = head;
    int i = 0;
    while (i < index && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    // case 3 - index out of bound
    if (curr == NULL)
    {
        cout << "Index out of bound!" << endl;
        return;
    }

    // case 4 - delete last node
    if (curr->next == NULL)
    {
        tail = prev;
    }

    // case 5 - delete middle node
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void deleteValue(Node *&head, Node *&tail, int value)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == value)
        {
            // case 1 : Deleting the head node
            if (curr == head)
            {
                head = head->next;

                // if list becomes empty
                if (head == NULL)
                {
                    tail = NULL;
                }
            }
            // case 2 : Deleting the middle or tail node
            else
            {
                prev->next = curr->next;

                if (curr->next == NULL)
                {
                    tail = prev;
                }
            }
            curr->next = NULL;
            delete curr;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << value << " not present in list!\n";
}

// __________ 4. SEARCHING __________

bool search(Node *&head, int target)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// __________ 4. REVERSE __________

void reverse(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *prev = NULL;
    Node *curr = head;
    Node *after = NULL;

    tail = curr;

    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }

    head = prev;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // INSERTION
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);

    insertAtIndex(head, tail, 200, 2);
    insertAtIndex(head, tail, 100, 6);
    insertAtTail(head, tail, 500);
    insertAtHead(head, tail, 5);

    print(head);

    // DELETION
    deleteHead(head);
    deleteHead(head);

    deleteAtIndex(head, tail, 2);
    deleteAtIndex(head, tail, 6);

    deleteValue(head, tail, 50);
    deleteValue(head, tail, 65);
    deleteValue(head, tail, 100);

    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    cout << "\nAfter reverse:\n";
    reverse(head, tail);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    // SEARCHING
    int target = 200;
    cout << "\n"
         << target << " is present: " << (search(head, target) ? "Yes" : "No") << endl;

    return 0;
}