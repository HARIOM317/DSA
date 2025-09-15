#include <iostream>

using namespace std;

class CircularQueue
{
    int *arr;
    int capacity;
    int currSize;
    int f, r;

public:
    // constructor
    CircularQueue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        f = 0;
        r = -1;
        currSize = 0;
    }

    // __________ QUEUE OPERATIONS __________

    // to push an element at end --> O(1)
    void push(int val)
    {
        if (currSize == capacity)
            return;
        r = (r + 1) % capacity;
        arr[r] = val;
        currSize++;
    }

    // to remove element from start --> O(1)
    void pop()
    {
        if (empty())
            return;
        arr[f] = 0;
        f = (f + 1) % capacity;
        currSize--;
    }

    // to get current size of queue --> O(1)
    int size()
    {
        return currSize;
    }

    // to check wether the queue is empty or not --> O(1)
    bool empty()
    {
        return currSize == 0;
    }

    // to get first element --> O(1)
    int front()
    {
        if (empty())
            return -1;
        return arr[f];
    }

    // to get last element --> O(1)
    int back()
    {
        if (empty())
            return -1;
        return arr[r];
    }

    // __________ OTHER OPERATIONS __________

    // to print the circular queue --> O(n)
    void print()
    {
        if (empty())
        {
            cout << "\nQueue is empty!\n\n";
        }
        else
        {
            cout << "\nQueue: ";
            int i = f;
            while (i != r)
            {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }

            cout << arr[r] << "\n\n";
        }
    }

    // destructor
    ~CircularQueue()
    {
        delete[] arr;
    }
};

int main()
{
    CircularQueue cq(5);

    cout << "Is queue empty: " << (cq.empty() ? "Yes" : "No") << endl;

    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);

    cq.print(); // 10 20 30 40 50
    cout << "Front: " << cq.front() << endl;
    cout << "Back: " << cq.back() << endl;
    cout << "Size: " << cq.size() << endl;

    cq.pop(); // delete 10
    cq.pop(); // delete 20
    cq.pop(); // delete 30

    cq.print(); // 40 50
    cout << "Front: " << cq.front() << endl;
    cout << "Back: " << cq.back() << endl;
    cout << "Size: " << cq.size() << endl;

    cq.pop(); // delete 40
    cq.pop(); // delete 50

    cq.print(); // empty
    cout << "Front: " << cq.front() << endl;
    cout << "Back: " << cq.back() << endl;
    cout << "Size: " << cq.size() << endl;

    cq.push(60);
    cq.push(70);
    cq.push(80);
    cq.push(90);

    cq.print(); // 60 70 80 90
    cout << "Front: " << cq.front() << endl;
    cout << "Back: " << cq.back() << endl;
    cout << "Size: " << cq.size() << endl;
    cout << "Is queue empty: " << (cq.empty() ? "Yes" : "No") << endl;

    return 0;
}