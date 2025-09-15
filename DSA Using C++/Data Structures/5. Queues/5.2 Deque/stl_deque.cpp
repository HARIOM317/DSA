#include <iostream>
#include <deque>

using namespace std;

// to print deque elements
void print(deque<int> dq)
{
    if (dq.empty())
    {
        cout << "\nDeque is empty!\n\n";
    }
    else
    {
        cout << "\nDeque: ";
        while (!dq.empty())
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << "\n\n";
    }
}

int main()
{
    deque<int> dq;

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

    print(dq); // 10 20 30 40 50 60 70 80 90 100
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

    print(dq); // 20 30 40 50 60 70 80 200
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

    print(dq);                                // empty
    cout << "Front : " << dq.front() << endl; // garbage
    cout << "Rear : " << dq.back() << endl;   // garbage
    cout << "Size : " << dq.size() << endl;   // 0

    dq.push_back(100);
    dq.push_front(10);

    print(dq); // 10 100
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;
    cout << "Is Deque Empty : " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}