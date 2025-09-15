#include <iostream>

using namespace std;

class Deque
{
    int *arr;
    int f, r;
    int capacity;
    int currSize;

public:
    // constructor
    Deque(int size)
    {
        capacity = size;
        arr = new int[capacity];
        f = r = -1;
        currSize = 0;
    }

    // destructor
    ~Deque()
    {
        delete[] arr;
    }

    // __________ DEQUE OPERATIONS __________

    // to push element at first --> O(1)
    void push_front(int val)
    {
        if (currSize == capacity)
            return;
        else if (empty())
            f = r = 0;
        else
            f = (f + capacity - 1) % capacity;

        arr[f] = val;
        currSize++;
    }

    // to push element at last --> O(1)
    void push_back(int val)
    {
        if (currSize == capacity)
            return;
        else if (empty())
            f = r = 0;
        else
            r = (r + 1) % capacity;

        arr[r] = val;
        currSize++;
    }

    // to pop element from first --> O(1)
    void pop_front()
    {
        if (empty())
            return;
        else if (f == r)
            f = r = -1;
        else
            f = (f + 1) % capacity;

        currSize--;
    }

    // to pop element from last --> O(1)
    void pop_back()
    {
        if (empty())
            return;
        else if (f == r)
            f = r = -1;
        else
            r = (r + capacity - 1) % capacity;

        currSize--;
    }

    // to get first element --> O(1)
    int front() const
    {
        if (empty())
            return -1;
        return arr[f];
    }

    // to get last element --> O(1)
    int back() const
    {
        if (empty())
            return -1;
        return arr[r];
    }

    // to check wether the deque is empty or not --> O(1)
    bool empty() const
    {
        return currSize == 0;
    }

    // to get size of deque --> O(1)
    int size() const
    {
        return currSize;
    }

    // __________ OTHER OPERATIONS __________
    // to print the deque elements --> O(n)
    void print() const
    {
        if (empty())
        {
            cout << "\nQueue is empty!\n\n";
        }
        else
        {
            int i = f;
            cout << "\nQueue: ";
            while (i != r)
            {
                cout << arr[i] << " ";
                i = (i + 1) % capacity;
            }
            cout << arr[r] << "\n\n";
        }
    }
};

int main()
{
    Deque dq(10);

    cout << "Is Deque Empty : " << (dq.empty() ? "Yes" : "No") << endl;

    // enqueue
    dq.push_front(50);
    dq.push_front(40);
    dq.push_front(30);
    dq.push_front(20);
    dq.push_front(10);

    dq.push_back(60);
    dq.push_back(70);
    dq.push_back(80);
    dq.push_back(90);
    dq.push_back(100);
    dq.push_back(110); // no space available

    dq.print(); // 10 20 30 40 50 60 70 80 90 100
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;

    // dequeue
    dq.pop_front(); // delete 10
    dq.pop_front(); // delete 20
    dq.pop_back();  // delete 100
    dq.pop_back();  // delete 90

    dq.push_back(200);
    dq.push_front(20);

    dq.print(); // 20 30 40 50 60 70 80 200
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;

    dq.pop_back();  // delete 200
    dq.pop_back();  // delete 80
    dq.pop_back();  // delete 70
    dq.pop_back();  // delete 60
    dq.pop_front(); // delete 20
    dq.pop_front(); // delete 30
    dq.pop_front(); // delete 40
    dq.pop_front(); // delete 50

    dq.print(); // empty
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;

    dq.push_back(100);
    dq.push_front(10);

    dq.print(); // 10 100
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;
    cout << "Is Deque Empty : " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}