#include <iostream>

using namespace std;

class Queue
{
    int *arr;
    int f;
    int r;
    int queueSize;

public:
    // constructor
    Queue(int size)
    {
        queueSize = size;
        arr = new int[queueSize];
        f = r = 0;
    }

    // _____ Queue Operations _____

    // 1. enqueue() - to push element at the last
    void enqueue(int data)
    {
        if (r == queueSize) // if queue is full
        {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[r++] = data;
    }

    // 2. dequeue() - to remove element from the start
    int dequeue()
    {
        // if queue is empty
        if (f == r)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int element = arr[f];
        arr[f++] = -1;
        if (f == r)
            f = r = 0;
        return element;
    }

    // 3. size() - to get queue size
    int size()
    {
        return r - f;
    }

    // 4. front() - to get first element of queue
    int front()
    {
        if (f == r)
            return -1;
        return arr[f];
    }

    // 5. back() - to get last element of queue
    int back()
    {
        if (f == r)
            return -1;
        return arr[r - 1];
    }

    // 6. empty() - to check wether a queue is empty or not
    bool empty()
    {
        return f == r;
    }

    // 7. print() - to print the queue
    void print()
    {
        if (f == r)
        {
            cout << "\nQueue is empty!\n\n";
            return;
        }
        cout << "\nQueue : ";
        for (int i = f; i < r; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
    }

    // destructor
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(5);

    cout << "Is queue empty : " << (q.empty() ? "Yes" : "No") << endl;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.print();

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    cout << "\nDequeued : " << q.dequeue() << endl;
    cout << "Dequeued : " << q.dequeue() << endl;

    q.print();

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Is queue empty : " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}