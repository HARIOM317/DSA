#include <bits/stdc++.h>

using namespace std;

class Queue
{
    deque<int> dq;

public:
    void push(int val)
    {
        dq.push_back(val);
    }

    void pop()
    {
        if (dq.empty())
        {
            cout << "Queue is empty!\n";
            return;
        }

        dq.pop_front();
    }

    int front()
    {
        if (dq.empty())
            return -1;
        return dq.front();
    }

    int back()
    {
        if (dq.empty())
            return -1;
        return dq.back();
    }

    int size()
    {
        return dq.size();
    }

    bool empty()
    {
        return dq.empty();
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;

    cout << "\nQueue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n\n";

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;
    cout << "Size: " << q.size() << endl;
    q.pop();

    return 0;
}