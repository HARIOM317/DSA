#include <iostream>

using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

// Linked List
class List
{
    int length;
    Node *head;
    Node *tail;

public:
    List()
    {
        length = 0;
        head = nullptr;
        tail = nullptr;
    }

    // to print linked list
    void print()
    {
        Node *temp = head; // local pointer variable
        cout << "\n";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << "\n\n";
    }

    // _____ INSERTION OPERATION _____
    // 1. to insert at front
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        length++;
    }

    // 2. to insert at end
    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    // 3. to insert at given position
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid index" << endl;
            return;
        }

        if (pos == 0)
        {
            push_front(val);
            return;
        }

        if (pos == length)
        {
            push_back(val);
            return;
        }

        Node *newNode = new Node(val);

        Node *temp = head;
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "Invalid index" << endl;
                return;
            }
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
    }

    // _____ DELETION OPERATION _____

    // 1. to delete first element
    void pop_front()
    {
        if (head != nullptr)
        {
            Node *temp = head;
            head = temp->next;
            temp->next = nullptr;
            delete temp;
            length--;
        }
    }

    // 2. to delete last element
    void pop_back()
    {
        if (tail != nullptr)
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = nullptr;
            delete tail;
            tail = temp;
            length--;
        }
    }

    // 3. to delete element at given position
    void remove(int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 0)
        {
            pop_front();
            return;
        }

        if (pos == length - 1)
        {
            pop_back();
            return;
        }

        Node *prev = nullptr;
        Node *curr = head;

        for (int i = 0; i < pos; i++)
        {
            if (curr->next == nullptr)
            {
                cout << "Invalid position!" << endl;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        length--;
    }

    // _____ SEARCH OPERATIONS _____

    // 1. to search iteratively
    int search(int key)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return -1;
        }

        Node *temp = head;
        int pos = 0;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                return pos;
            }
            temp = temp->next;
            pos++;
        }

        return -1;
    }

    // 2. to search recursively
    int helper(int key, Node *ptr, int pos)
    {
        if (ptr == nullptr)
            return -1;
        if (ptr->data == key)
            return pos;

        helper(key, ptr->next, pos + 1);
    }

    int searchRecursive(int key)
    {
        Node *temp = head;
        return helper(key, temp, 0);
    }

    // _____ OTHER OPERATIONS _____

    // 1. to get first element
    int size()
    {
        return this->length;
    }

    int front()
    {
        if (head != nullptr)
            return head->data;
        return -1;
    }

    // 1. to get last element
    int back()
    {
        if (tail != nullptr)
            return tail->data;
        return -1;
    }

    // 3. to reverse linked list
    void reverse()
    {
        Node *prev = nullptr;
        Node *curr = head;
        tail = curr;

        while (curr != nullptr)
        {
            Node *next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main()
{
    List ll;

    ll.push_front(30); // 30->null
    ll.push_front(20); // 20->30->null
    ll.push_front(10); // 10->20->30->null

    ll.push_back(40); // 10->20->30->40->null
    ll.push_back(50); // 10->20->30->40->50->null
    ll.push_back(60); // 10->20->30->40->50->60->null

    ll.insert(5, 0);   // 5->10->20->30->40->50->60->null
    ll.insert(35, 4);  // 5->10->20->30->35->40->50->60->null
    ll.insert(100, 8); // 5->10->20->30->35->40->50->60->100->null

    ll.print();                                    // 5->10->20->30->35->40->50->60->100->null
    cout << "List size = " << ll.size() << "\n\n"; // 9

    ll.pop_front(); // delete 5
    ll.pop_front(); // delete 10
    ll.pop_back();  // delete 100
    ll.pop_back();  // delete 60

    ll.print(); // 20->30->35->40->50->null

    ll.remove(0); // delete 20
    ll.remove(1); // delete 35
    ll.remove(2); // delete 50

    ll.print(); // 30->40->null

    cout << "Found 10 at pos: " << ll.searchRecursive(10) << endl; // -1
    cout << "Found 40 at pos: " << ll.search(40) << endl;          // 1

    cout << "\nFront element = " << ll.front() << endl; // 30
    cout << "Back element = " << ll.back() << endl;     // 40

    ll.reverse();
    ll.print();                                  // 40->30->null
    cout << "List size = " << ll.size() << endl; // 2

    return 0;
}