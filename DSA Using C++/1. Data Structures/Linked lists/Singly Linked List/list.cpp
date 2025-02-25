#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    // list operations or methods

    // _____ INSERTION OPERATION _____

    // push_front() - to insert element at the start of linked list
    void push_front(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    // push_back() - to insert element at the end of linked list
    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (tail == NULL)
        {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    // insert() - to insert element at given index or pos
    void insert(int value, int pos)
    {
        // case 1 - invalid pos
        if (pos < 0)
        {
            cout << "Invalue index!" << endl;
            return;
        }

        // case 2 - pos is 0
        if (pos == 0)
        {
            push_front(value);
            return;
        }

        // case 3 - pos = size of list
        int n = size();
        if (pos == n)
        {
            push_back(value);
            return;
        }

        // case 4 - pos is more than size of list
        if (pos > n)
        {
            cout << "Index out of bound!" << endl;
            return;
        }

        // case 5: Insert in middle (General case)
        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // _____ DELETION OPERATION _____

    // pop_front() - to delete first element
    void pop_front()
    {
        if (head == NULL)
        {
            cout << "No element to be pop!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // pop_back() - to delete last element
    void pop_back()
    {
        // case 1: If the list is empty
        if (tail == NULL)
        {
            cout << "No element to be pop!" << endl;
            return;
        }

        // case-2: If there is only one node
        if (tail == head)
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        // case-3: When there is multiple nodes
        Node *curr = head;
        while (curr->next != tail)
        {
            curr = curr->next;
        }

        curr->next = NULL;
        delete tail;
        tail = curr;
    }

    // remove() - to remove element at given pos or index
    void remove(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid index to pop element!" << endl;
            return;
        }
        if (pos == 0)
        {
            pop_front();
            return;
        }
        if (pos == size() - 1)
        {
            pop_back();
            return;
        }
        if (pos >= size())
        {
            cout << "Index out of bound to pop element!" << endl;
            return;
        }

        Node *prev = NULL;
        Node *curr = head;
        for (int i = 0; i < pos; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    // _____ OTHER OPERATIONS _____

    // printLL() - to print all elements of linked list
    void printLL()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // find() - to check wether a element is present in linked list or not
    bool find(int target)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == target)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // size() - to get size of linked list
    int size()
    {
        if (head == NULL)
            return 0;
        int len = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }

    int getHead()
    {
        if (head != NULL)
            return head->data;
        return -1;
    }

    int getTail()
    {
        if (tail != NULL)
            return tail->data;
        return -1;
    }
};

int main()
{
    List l;

    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);

    l.push_back(50);
    l.push_back(60);
    l.push_back(70);
    l.push_back(80);

    l.insert(90, 0);
    l.insert(45, 5);
    l.insert(100, 10);

    cout << "\nLinked List: ";
    l.printLL();
    cout << "Head: " << l.getHead() << endl;
    cout << "Tail: " << l.getTail() << endl
         << endl;

    l.pop_front();
    l.pop_front();
    l.pop_back();
    l.pop_back();
    l.remove(4);

    cout << "\nLinked List: ";
    l.printLL();
    cout << "Head: " << l.getHead() << endl;
    cout << "Tail: " << l.getTail() << endl
         << endl;

    int target = 45;
    cout << "Found " << target << ": " << (l.find(target) ? "Yes" : "No") << endl;

    return 0;
}