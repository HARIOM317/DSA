#include <iostream>

using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }

    // destructor
    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

// Circular List
class CircularList
{
    Node *tail;
    int length;

public:
    // constructor
    CircularList()
    {
        length = 0;
        tail = nullptr;
    }

    // destructor
    ~CircularList()
    {
        cout << "\nCleaning up list...\n";
        while (tail != nullptr)
        {
            deleteAtHead();
        }
    }

    // __________ INSERTION __________

    // 1. insert node at head
    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
        }

        length++;
    }

    // 2. insert node at tail
    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (tail == nullptr)
        {
            tail = newNode;
            tail->next = tail;
        }
        else
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    // 3. insert node at given index
    void insertAtIndex(int val, int index)
    {
        if (index < 0 || index > length)
        {
            cout << "Invalid index!\n";
        }
        else if (index == 0)
        {
            // case 1 : insert at head
            insertAtHead(val);
        }
        else if (index == length)
        {
            // case 2 : insert at tail
            insertAtTail(val);
        }
        else
        {
            // case 3 : insert at middle
            Node *newNode = new Node(val);

            Node *temp = tail->next;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

    // __________ DELETION __________

    // 1. delete first node
    void deleteAtHead()
    {
        if (tail == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        else if (tail->next == tail)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail->next;
            tail->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }

        length--;
    }

    // 2. delete last node
    void deleteAtTail()
    {
        if (tail == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        else if (tail->next == tail)
        {
            delete tail;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail->next;

            while (temp->next != tail)
            {
                temp = temp->next;
            }

            temp->next = tail->next;
            tail->next = nullptr;
            delete tail;
            tail = temp;
        }

        length--;
    }

    // 3. delete node at given index
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid index!\n";
            return;
        }
        else if (index == 0)
        {
            // case 1 : delete at head
            deleteAtHead();
        }
        else if (index == length - 1)
        {
            // case 2 : delete at tail
            deleteAtTail();
        }
        else
        {
            // case 3 : delete at middle
            Node *prev = nullptr;
            Node *curr = tail->next;

            for (int i = 0; i < index; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            curr->next = nullptr;
            delete curr;

            length--;
        }
    }

    // 4. delete node by node value
    void deleteValue(int val)
    {
        if (tail == nullptr)
        {
            return;
        }
        else if (tail->next == tail && tail->data == val)
        {
            // case 1 : single node in list
            delete tail;
            tail = nullptr;
            length--;
        }
        else
        {
            // case 2 : more than 1 node
            Node *prev = tail;
            Node *curr = tail->next;

            while (curr != tail)
            {
                if (curr->data == val)
                {
                    prev->next = curr->next;
                    curr->next = nullptr;
                    delete curr;
                    length--;
                    return;
                }

                prev = curr;
                curr = curr->next;
            }

            if (curr == tail && curr->data == val)
            {
                deleteAtTail();
                return;
            }
        }
    }

    // 5. to clear list
    void clear()
    {
        while (tail != nullptr)
            deleteAtHead();
    }

    // __________ OTHER OPERATIONS __________

    // 1. to print the circular list
    void print() const
    {
        if (tail == nullptr)
        {
            cout << "\nList is empty!\n\n";
            return;
        }

        Node *curr = tail->next;
        cout << "\n";

        do
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        } while (curr != tail->next);

        cout << tail->next->data << "\n\n";
    }

    // 2. to get first element of the circular list
    int front() const
    {
        if (tail == nullptr)
            return -1;
        return tail->next->data;
    }

    // 2. to get last element of the circular list
    int back() const
    {
        if (tail == nullptr)
            return -1;
        return tail->data;
    }

    // 1. to get size of the circular list
    int size() const
    {
        return length;
    }
};

int main()
{
    CircularList cll;

    // INSERTION
    cll.insertAtHead(30); // insert 30 at front
    cll.insertAtHead(20); // insert 20 at front
    cll.insertAtHead(10); // insert 10 at front

    cll.insertAtTail(40); // insert 40 at tail
    cll.insertAtTail(50); // insert 50 at tail
    cll.insertAtTail(60); // insert 60 at tail

    cll.insertAtIndex(100, 0); // insert 100 at index 0
    cll.insertAtIndex(200, 4); // insert 200 at index 4
    cll.insertAtIndex(500, 8); // insert 500 at index 8

    cll.print(); // 100->10->20->30->200->40->50->60->500->100

    // DELETION
    cll.deleteAtHead(); // delete 100
    cll.deleteAtHead(); // delete 10

    cll.deleteAtTail(); // delete 500
    cll.deleteAtTail(); // delete 60

    cll.print(); // 20->30->200->40->50->20

    cll.deleteAtIndex(0); // delete at index 0 (20)
    cll.deleteAtIndex(1); // delete at index 1 (200)
    cll.deleteAtIndex(2); // delete at index 2 (50)

    cll.print(); // 30->40->30

    // OTHER
    cout << "Front: " << cll.front() << endl; // 30
    cout << "Back: " << cll.back() << endl;   // 40
    cout << "Size: " << cll.size() << "\n\n"; // 2

    cll.deleteValue(30); // delete 30
    cll.deleteValue(40); // delete 40

    cll.print(); // List is empty!

    return 0;
}