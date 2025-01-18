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
        cout << "Deleted : " << this->data << endl;
    }
};

void print(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "Empty List!\n";
        return;
    }

    Node *current = tail->next;

    cout << endl;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);

    cout << endl
         << endl;
}

int size(Node *&tail)
{
    if (tail == NULL)
    {
        return 0;
    }

    Node *current = tail->next;
    int len = 0;
    do
    {
        current = current->next;
        len++;
    } while (current != tail->next);

    return len;
}

void insertAtFirst(Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // case 1 - Empty list
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
        return;
    }

    // case 2 - Not Empty List
    newNode->next = tail->next;
    tail->next = newNode;
}

void insertAtLast(Node *&tail, int data)
{
    Node *newNode = new Node(data);

    // case 1 - Empty list
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
        return;
    }

    // case 2 - Not Empty list
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertAtIndex(Node *&tail, int index, int data)
{
    if (index < 0)
    {
        cout << "Invalid Index!" << endl;
        return;
    }
    if (index == 0 || tail == NULL)
    {
        insertAtFirst(tail, data);
        return;
    }
    if (index > size(tail))
    {
        cout << "Index out of bound!" << endl;
        return;
    }

    Node *current = tail->next;
    int i = 1;
    while (i < index)
    {
        current = current->next;
        i++;
    }

    Node *newNode = new Node(data);
    newNode->next = current->next;
    current->next = newNode;

    if (current == tail)
    {
        tail = newNode;
    }
}

void deleteFirst(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "No element to delete!" << endl;
        return;
    }

    Node *temp = tail->next;

    if (temp == tail)
    {
        tail = NULL;
        delete temp;
        return;
    }

    tail->next = tail->next->next;
    delete temp;
}

void deleteIndex(Node *&tail, int index)
{
    if (tail == NULL)
    {
        cout << "No element to delete\n";
        return;
    }

    if (index < 0)
    {
        cout << "Invalid index\n";
        return;
    }

    if (index == 0)
    {
        deleteFirst(tail);
        return;
    }

    if (index >= size(tail))
    {
        cout << "Index out of bound!" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = tail->next;
    int i = 0;

    while (i < index)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    prev->next = curr->next;
    if (curr == tail)
    {
        tail = prev;
    }
    delete curr;
}

void deleteValue(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "No element to delete!" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = tail->next;

    // if single node present in list
    if (curr == tail && curr->data == value)
    {
        tail = NULL;
        delete curr;
        return;
    }

    do
    {
        if (curr->data == value)
        {
            prev->next = curr->next;
            if (curr == tail)
            {
                tail = prev;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != tail->next);

    cout << value << " is not present in the list to delete!" << endl;
}

int main()
{
    Node *tail = NULL;
    insertAtFirst(tail, 10);
    insertAtFirst(tail, 20);
    insertAtFirst(tail, 30);

    insertAtLast(tail, 40);
    insertAtLast(tail, 45);

    insertAtIndex(tail, 3, 50);
    insertAtIndex(tail, 6, 100);

    print(tail);

    deleteFirst(tail);     // deleting first element
    deleteIndex(tail, 5);  // deleting index 5 element
    deleteValue(tail, 50); // deleting element with value 50

    print(tail);

    int length = size(tail);
    cout << "Length of list : " << length << endl;
    if (length != 0)
    {
        cout << "Head: " << tail->next->data << endl;
        cout << "Tail: " << tail->data << endl;
    }
    return 0;
}