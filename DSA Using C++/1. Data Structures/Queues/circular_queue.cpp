#include <iostream>

using namespace std;

class Queue
{
    int *arr;
    int f;
    int r;
    int dequeSize;
    int length;

public:
    // constructor
    Queue(int size)
    {
        dequeSize = size;
        arr = new int[dequeSize];
        f = r = -1;
        length = 0;
    }

    void enqueue(int data)
    {
        // if queue is full
        if ((r + 1) % dequeSize == f)
        {
            cout << "Queue is full!" << endl;
            return;
        }

        if (f == -1)
            f = r = 0; // if queue is empty
        else
            r = (r + 1) % dequeSize; // if queue is not empty

        arr[r] = data;
        length++;
    }

    int dequeue()
    {
        // if queue is empty
        if (f == -1)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int dequeuedElement = arr[f];
        arr[f] = -1;

        // if only single element in queue
        if (f == r)
            f = r = -1;
        else
            f = (f + 1) % dequeSize;

        length--;
        return dequeuedElement;
    }

    int size()
    {
        return length;
    }

    int capacity()
    {
        return dequeSize;
    }

    int front()
    {
        if (f == -1)
            return -1;
        return arr[f];
    }

    int rear()
    {
        if (r == -1)
            return -1;
        return arr[r];
    }

    bool empty()
    {
        return f == -1;
    }

    void print()
    {
        if (!empty())
        {
            cout << "\nQueue : ";
            int i = f;
            while (true)
            {
                cout << arr[i] << " ";
                if (i == r)
                    break;
                i = (i + 1) % dequeSize;
            }
            cout << "\n\n";
        }
    }

    // destructor
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(10);
    cout << "Is Queue Empty : " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Size of Queue : " << q.size() << endl;
    cout << "Capacity of Queue : " << q.capacity() << endl;
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl;

    // enqueue operation
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.enqueue(80);
    q.enqueue(90);
    q.enqueue(100);
    q.enqueue(200);

    q.print();
    cout << "Is Queue Empty : " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Size of Queue : " << q.size() << endl;
    cout << "Capacity of Queue : " << q.capacity() << endl;
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl
         << endl;

    // dequeue operation
    cout << "Deleted : " << q.dequeue() << endl;
    cout << "Deleted : " << q.dequeue() << endl;
    cout << "Deleted : " << q.dequeue() << endl;
    cout << "Deleted : " << q.dequeue() << endl;
    cout << "Deleted : " << q.dequeue() << endl;

    q.enqueue(10);
    q.enqueue(20);

    q.print();
    cout << "Is Queue Empty : " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Size of Queue : " << q.size() << endl;
    cout << "Capacity of Queue : " << q.capacity() << endl;
    cout << "Front : " << q.front() << endl;
    cout << "Rear : " << q.rear() << endl;

    return 0;
}