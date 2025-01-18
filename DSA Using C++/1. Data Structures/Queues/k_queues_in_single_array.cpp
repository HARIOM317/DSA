#include <iostream>

using namespace std;

class KQueues
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n;
    int k;
    int freeSpot;

public:
    KQueues(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];

        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    // enqueue
    void enqueue(int data, int qn)
    {
        // step-1 : check overflow
        if (freeSpot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }

        // step-2 : find first free index
        int index = freeSpot;

        // step-3 : update freeSpot
        freeSpot = next[index];

        // step-4: check wether first element otherwise link new element to previous element
        if (front[qn - 1] == -1)
        {
            // first element
            front[qn - 1] = index;
        }
        else
        {
            // link new element to previous element
            next[rear[qn - 1]] = index;
        }

        // step-5 : update next
        next[index] = -1;

        // step-6 : update rear
        rear[qn - 1] = index;

        // push element
        arr[index] = data;
    }

    // dequeue
    int dequeue(int qn)
    {
        // step-1 : check underflow
        if (front[qn - 1] == -1)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        // step-2 : find index to pop
        int index = front[qn - 1];

        // step-3 : update front
        front[qn - 1] = next[index];

        // step-4 : manage freeSpot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    bool isFull()
    {
        return freeSpot == -1;
    }

    bool isEmpty(int qn)
    {
        return front[qn] == -1;
    }
};

int main()
{
    int n = 10, k = 3;
    KQueues q(n, k);

    // enqueue
    q.enqueue(10, 1);
    q.enqueue(20, 1);
    q.enqueue(30, 2);
    q.enqueue(40, 2);
    q.enqueue(50, 3);
    q.enqueue(60, 1);
    q.enqueue(70, 2);
    q.enqueue(80, 3);
    q.enqueue(90, 2);
    q.enqueue(100, 1);
    q.enqueue(120, 3);

    // dequeue (Queue 1)
    cout << "\nDequeued (Queue 1) : " << q.dequeue(1) << endl;
    cout << "Dequeued (Queue 1) : " << q.dequeue(1) << endl;
    cout << "Dequeued (Queue 1) : " << q.dequeue(1) << endl;
    cout << "Dequeued (Queue 1) : " << q.dequeue(1) << endl;
    cout << "Dequeued (Queue 1) : " << q.dequeue(1) << endl;

    // dequeue (Queue 2)
    cout << "\nDequeued (Queue 2) : " << q.dequeue(2) << endl;
    cout << "Dequeued (Queue 2) : " << q.dequeue(2) << endl;
    cout << "Dequeued (Queue 2) : " << q.dequeue(2) << endl;
    cout << "Dequeued (Queue 2) : " << q.dequeue(2) << endl;
    cout << "Dequeued (Queue 2) : " << q.dequeue(2) << endl;

    // dequeue (Queue 3)
    cout << "\nDequeued (Queue 3) : " << q.dequeue(3) << endl;
    cout << "Dequeued (Queue 3) : " << q.dequeue(3) << endl;
    cout << "Dequeued (Queue 3) : " << q.dequeue(3) << endl;

    return 0;
}