#include <iostream>

using namespace std;

// Node
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // Constructor
    Node(int val)
    {
        this->data = val;
        this->prev = this->next = nullptr;
    }

    // Destructor
    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

// Doubly Linked List
class DoublyList
{
    int length;
    Node *head;
    Node *tail;

public:
    // constructor
    DoublyList()
    {
        length = 0;
        head = tail = nullptr;
    }

    // destructor
    ~DoublyList()
    {
        cout << "\nCleaning up list...\n";
        while (head != nullptr)
        {
            pop_front();
        }
    }

    // __________ INSERTION __________

    // 1. insert node at front
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        length++;
    }

    // 2. insert node at back
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        length++;
    }

    // 3. insert node at given position
    void insert(int val, int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid position!\n";
        }
        else if (pos == 0)
        {
            // case 1 : insert at first
            push_front(val);
        }
        else if (pos == length)
        {
            // case 2 : insert at last
            push_back(val);
        }
        else
        {
            // case 3 : insert at middle
            Node *newNode = new Node(val);

            Node *temp = head;

            for (int i = 0; i < pos; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp;
            newNode->prev = temp->prev;
            temp->prev->next = newNode;
            temp->prev = newNode;

            length++;
        }
    }

    // __________ DELETION __________
    // 1. remove first node
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = head;
            head = head->next;

            head->prev = nullptr;
            temp->next = nullptr;
            delete temp;
        }

        length--;
    }

    // 2. remove last node
    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        else if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev;

            tail->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }

        length--;
    }

    // 3. remove node at given position
    void remove(int pos)
    {
        if (pos < 0 || pos >= length)
        {
            cout << "Invalid position!\n";
        }
        else if (pos == 0)
        {
            // case 1 : delete first node
            pop_front();
        }
        else if (pos == length - 1)
        {
            // case 2 : delete last node
            pop_back();
        }
        else
        {
            // case 3 : delete middle node
            Node *temp = head;
            for (int i = 0; i < pos; i++)
            {
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->prev = temp->next = nullptr;
            delete temp;

            length--;
        }
    }

    // 4. to remove node by value
    void deleteValue(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
            {
                Node *toDelete = temp;
                temp = temp->next;

                if (toDelete == head)
                {
                    // case 1 - delete first node
                    pop_front();
                }
                else if (toDelete == tail)
                {
                    // case 2 - delete last node
                    pop_back();
                }
                else
                {
                    // case 3 - delete middle node
                    toDelete->prev->next = toDelete->next;
                    toDelete->next->prev = toDelete->prev;
                    toDelete->prev = toDelete->next = nullptr;
                    delete toDelete;
                    length--;
                }
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    // __________ OTHER OPERATIONS __________

    // 1. to print doubly linked list
    void print() const
    {
        if (head == nullptr)
        {
            cout << "\nEmpty List!\n\n";
            return;
        }

        Node *temp = head; // local pointer variable
        cout << "\nNULL <= ";
        while (temp != nullptr)
        {
            cout << temp->data << ((temp->next == nullptr) ? " => " : " <=> ");
            temp = temp->next;
        }
        cout << "NULL\n\n";
    }

    // 2. to reverse doubly linked list
    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *temp = nullptr;
        Node *curr = head;

        while (curr != nullptr)
        {
            // swapping prev and next pointers
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;

            // update curr
            curr = curr->prev;
        }

        // update head & tail
        temp = head;
        head = tail;
        tail = temp;
    }

    // 3. to get front element
    int front() const
    {
        if (head == nullptr)
            return -1;
        return this->head->data;
    }

    // 4. to get last element
    int back() const
    {
        if (tail == nullptr)
            return -1;
        return this->tail->data;
    }

    // 5. to get size of doubly linked list
    int size() const
    {
        return this->length;
    }

    // 6. to find element
    bool find(int val) const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }
};

int main()
{
    DoublyList dll;

    dll.push_front(30); // NULL <= 30 => NULL
    dll.push_front(20); // NULL <= 20 <=> 30 => NULL
    dll.push_front(10); // NULL <= 10 <=> 20 <=> 30 => NULL

    dll.push_back(40); // NULL <= 10 <=> 20 <=> 30 <=> 40 => NULL
    dll.push_back(50); // NULL <= 10 <=> 20 <=> 30 <=> 40 <=> 50 => NULL
    dll.push_back(60); // NULL <= 10 <=> 20 <=> 30 <=> 40 <=> 50 <=> 60 => NULL

    dll.insert(100, 0); // NULL <= 100 <=> 10 <=> 20 <=> 30 <=> 40 <=> 50 <=> 60 => NULL
    dll.insert(200, 5); // NULL <= 100 <=> 10 <=> 20 <=> 30 <=> 40 <=> 200 <=> 50 <=> 60 => NULL
    dll.insert(500, 8); // NULL <= 100 <=> 10 <=> 20 <=> 30 <=> 40 <=> 200 <=> 50 <=> 60 <=> 500 => NULL

    dll.print(); // NULL <= 100 <=> 10 <=> 20 <=> 30 <=> 40 <=> 200 <=> 50 <=> 60 <=> 500 => NULL

    dll.pop_front(); // delete 100
    dll.pop_front(); // delete 10
    dll.pop_back();  // delete 500
    dll.pop_back();  // delete 60

    dll.print(); // NULL <= 20 <=> 30 <=> 40 <=> 200 <=> 50 => NULL

    dll.remove(0); // delete 20
    dll.remove(1); // delete 40
    dll.remove(2); // delete 50

    dll.print(); // NULL <= 30 <=> 200 => NULL

    cout << "Size = " << dll.size() << endl; // 2

    cout << "Front: " << dll.front() << endl; // 30
    cout << "Back: " << dll.back() << endl;   // 200

    dll.reverse();
    dll.print(); // NULL <= 200 <=> 30 => NULL

    cout << "Found 30: " << (dll.find(30) ? "Yes" : "No") << endl;   // Yes
    cout << "Found 10: " << (dll.find(10) ? "Yes" : "No") << "\n\n"; // No

    dll.deleteValue(200); // delete 200
    dll.deleteValue(30);  // delete 300

    dll.print(); // Empty List!

    return 0;
}