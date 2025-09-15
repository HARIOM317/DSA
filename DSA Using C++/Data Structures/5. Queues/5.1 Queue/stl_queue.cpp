#include <iostream>
#include <queue>

using namespace std;

// to print the queue
void print(queue<int> q)
{
    if (q.empty())
    {
        cout << "\nQueue is Empty!\n\n";
    }
    else
    {
        cout << "\nQueue: ";
        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n\n";
    }
}

int main()
{
    queue<int> q;

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
    cout << "size: " << q.size() << "\n";

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