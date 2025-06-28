#include <iostream>

using namespace std;

class Deque
{
    int *arr;
    int front;
    int rear;
    int size;
    int len;

public:
    // constructor
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
        len = 0;
    }

    // destructor
    ~Deque()
    {
        delete[] arr;
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void push_front(int data)
    {
        // if deque is full
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        // if deque is empty
        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + size) % size;

        arr[front] = data;
        len++;
    }

    void push_back(int data)
    {
        // if deque is full
        if (isFull())
        {
            cout << "Deque is full!" << endl;
            return;
        }

        // if deque is empty
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % size;

        arr[rear] = data;
        len++;
    }

    int pop_front()
    {
        // if deque is empty
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return -1;
        }

        int element = arr[front];
        arr[front] = -1;

        // if single element in deque
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        len--;
        return element;
    }

    int pop_back()
    {
        // if deque is empty
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return -1;
        }

        int element = arr[rear];
        arr[rear] = -1;

        // if single element in deque
        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + size) % size;

        len--;
        return element;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return arr[rear];
    }

    int length()
    {
        return len;
    }

    int capacity()
    {
        return size;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Deque is empty!" << endl;
            return;
        }
        int i = front;
        cout << "\nDeque: ";
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << "\n\n";
    }
};

int main()
{
    Deque dq(10);

    cout << "Is Deque Empty : " << (dq.isEmpty() ? "Yes" : "No") << endl;

    // enqueue
    dq.push_front(10);
    dq.push_front(20);
    dq.push_front(30);
    dq.push_front(40);
    dq.push_front(50);

    dq.push_back(60);
    dq.push_back(70);
    dq.push_back(80);
    dq.push_back(90);
    dq.push_back(100);

    dq.print();
    cout << "Is Deque Full : " << (dq.isFull() ? "Yes" : "No") << endl;
    cout << "Front : " << dq.getFront() << endl;
    cout << "Rear : " << dq.getRear() << endl;
    cout << "Size : " << dq.length() << endl;
    cout << "Capacity : " << dq.capacity() << endl
         << endl;

    // dequeue
    cout << "Deleted : " << dq.pop_front() << endl;
    cout << "Deleted : " << dq.pop_front() << endl;
    cout << "Deleted : " << dq.pop_back() << endl;
    cout << "Deleted : " << dq.pop_back() << endl;

    dq.print();
    cout << "Is Deque Full : " << (dq.isFull() ? "Yes" : "No") << endl;
    cout << "Front : " << dq.getFront() << endl;
    cout << "Rear : " << dq.getRear() << endl;
    cout << "Size : " << dq.length() << endl;
    cout << "Capacity : " << dq.capacity() << endl
         << endl;

    return 0;
}