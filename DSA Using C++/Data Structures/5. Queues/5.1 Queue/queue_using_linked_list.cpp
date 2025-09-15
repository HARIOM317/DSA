#include <iostream>

using namespace std;

// Node <generic>
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

// Queue <generic>
template <typename T>
class Queue
{
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    // Constructor
    Queue()
    {
        length = 0;
        head = tail = nullptr;
    }

    // Destructor
    ~Queue()
    {
        cout << "\nClearing queue from memory...\n";
        while (!empty())
        {
            pop();
        }
    }

    // to return head of queue --> O(1)
    Node<T> *getHead()
    {
        return this->head;
    }

    // to enqueue element in queue --> O(1)
    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        length++;

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // to dequeue element from queue --> O(1)
    void pop()
    {
        if (head == nullptr)
            return;

        Node<T> *toDelete = head;
        head = head->next;
        toDelete->next = nullptr;
        delete toDelete;
        length--;
    }

    // to get first element of queue --> O(1)
    T front()
    {
        if (head == nullptr)
            return T(); // default value
        return head->data;
    }

    // to get last element of queue --> O(1)
    T back()
    {
        if (tail == nullptr)
            return T(); // default value
        return tail->data;
    }

    // to check wether the queue is empty or not --> O(1)
    bool empty()
    {
        return head == nullptr;
    }

    // to get size of queue --> O(1)
    int size()
    {
        return this->length;
    }
};

// To print the queue elements
void print(Queue<int> &q)
{
    Node<int> *curr = q.getHead();

    if (curr == nullptr)
    {
        cout << "\nQueue is Empty!\n\n";
    }
    else
    {
        cout << "\nQueue: ";
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n\n";
    }
}

int main()
{
    Queue<int> q;

    cout << "Size: " << q.size() << endl;
    cout << "Is queue empty: " << (q.empty() ? "Yes" : "No") << endl;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    print(q);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "size: " << q.size() << "\n\n";

    q.pop();
    q.pop();
    q.pop();

    print(q);
    cout << "front: " << q.front() << endl;
    cout << "back: " << q.back() << endl;
    cout << "size: " << q.size() << endl;
    cout << "Is queue empty: " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}