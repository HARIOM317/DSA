#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    ~Node()
    {
        cout << "Deleted : " << this->data << endl;
    }
};

class Queue
{
    Node *f;
    Node *r;
    int length;

public:
    // constructor
    Queue()
    {
        this->f = this->r = NULL;
        length = 0;
    }

    // 1. enqueue() - to insert an element at the end of the queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        this->length++;

        // if queue is empty
        if (f == NULL)
        {
            f = r = newNode;
            return;
        }
        r->next = newNode;
        r = newNode;
    }

    // 2. dequeue() - to delete an element from the start of the queue
    int dequeue()
    {
        if (f == NULL)
            return -1;

        Node *temp = f;
        int dequeuedElement = temp->data;

        f = f->next;
        if (f == NULL)
        {
            r = NULL;
        }
        
        temp->next = NULL;
        delete temp;
        length--;

        return dequeuedElement;
    }

    // 3. front() - to get the front element of the queue
    int front()
    {
        if (f == NULL)
            return -1;
        return f->data;
    }

    // 4. real() - to get the real element of the queue
    int rear()
    {
        if (r == NULL)
            return -1;
        return r->data;
    }

    // 5. size() - to get the size of the queue
    int size()
    {
        return this->length;
    }

    // 6. empty() - to check wether a queue is empty or not
    bool empty()
    {
        return this->length == 0;
    }

    // 7. print() - to print the queue elements
    void print()
    {
        if (!empty())
        {
            Node *temp = f;
            cout << "\nQueue: ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl
                 << endl;
        }
    }

    // Destructor
    ~Queue()
    {
        while (f != NULL)
        {
            Node *temp = f;
            f = f->next;
            delete temp;
        }
        cout << "Queue destroyed." << endl;
    }
};

int main()
{

    Queue q;
    cout << "Is Queue Empty : " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Size of Queue : " << q.size() << endl;

    // enqueue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.print();

    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl
         << endl;

    // dequeue
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.print();

    cout << "Is Queue Empty : " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Size of Queue : " << q.size() << endl;
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl
         << endl;

    return 0;
}