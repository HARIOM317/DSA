#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
        return;
    }

    Node *temp = head;
    cout << endl
         << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

int length(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtFirst(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtLast(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtIndex(Node *&head, Node *&tail, int index, int data)
{
    if (index < 0)
    {
        cout << "Invalid index!\n";
        return;
    }

    if (index == 0)
    {
        insertAtFirst(head, tail, data);
        return;
    }

    Node *temp = head;
    int i = 0;
    while (i < index - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        cout << "Index out of bound!\n";
        delete temp;
        return;
    }

    if (temp->next == NULL)
    {
        insertAtLast(head, tail, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFirst(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }
    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}

void deleteIndex(Node *&head, Node *&tail, int index)
{
    if (index < 0)
    {
        cout << "Invalid index\n";
        return;
    }
    if (index == 0)
    { // delete first node
        deleteFirst(head, tail);
        return;
    }
    int i = 0;
    Node *temp = head;

    while (i < index && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        cout << "Index out of bound!\n";
        return;
    }

    if (temp->next == NULL)
    { // delete last node
        tail = temp->prev;
        tail->next = NULL;
        delete temp;
        return;
    }

    // delete a middle node
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

void deleteValue(Node *&head, Node *&tail, int value)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            // case 1 - delete first node
            if (temp == head)
            {
                deleteFirst(head, tail);
                return;
            }
            else
            {
                if (temp->next == NULL)
                {
                    tail = temp->prev;
                    tail->next = NULL;
                    delete temp;
                    return;
                }
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
        }
        temp = temp->next;
    }

    cout << value << " is not present in the list!\n";
}

void reverse(Node *&head, Node *&tail)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *temp = NULL;
    Node *curr = head;

    // traverse and swap temp and curr
    while (curr != NULL)
    {
        // swapping next and prev pointer
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    // updating head and tail pointer
    temp = head;
    head = tail;
    tail = temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtFirst(head, tail, 20);
    insertAtFirst(head, tail, 10);

    insertAtLast(head, tail, 30);
    insertAtLast(head, tail, 40);

    insertAtIndex(head, tail, 0, 5);
    insertAtIndex(head, tail, 5, 45);
    insertAtIndex(head, tail, 6, 70);

    print(head);

    deleteFirst(head, tail);
    deleteFirst(head, tail);

    deleteIndex(head, tail, 0);
    deleteIndex(head, tail, 2);

    deleteValue(head, tail, 70);

    print(head);

    int len = length(head);
    if (len != 0)
    {
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
    }

    cout << "\nAfter reverse:\n";
    reverse(head, tail);
    print(head);

    if (len != 0)
    {
        cout << "Head: " << head->data << endl;
        cout << "Tail: " << tail->data << endl;
    }

    cout << "Length of the list: " << len << endl;

    return 0;
}