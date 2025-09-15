#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *prev;
    Node *next;

    Node(T val)
    {
        data = val;
        prev = next = nullptr;
    }

    ~Node()
    {
        cout << "Deleted: " << this->data << endl;
    }
};

template <typename T>
class Deque
{
    Node<T> *head, *tail;
    int currSize;

public:
    // constructor
    Deque()
    {
        head = tail = nullptr;
        currSize = 0;
    }

    // destructor
    ~Deque()
    {
        cout << "\nClearing deque from memory..." << endl;
        while (!empty())
        {
            pop_front();
        }
    }

    // to push element at the start --> O(1)
    void push_front(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        currSize++;
    }

    // to push element at the end --> O(1)
    void push_back(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        currSize++;
    }

    // to pop element from start --> O(1)
    void pop_front()
    {
        if (head == nullptr)
            return;
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node<T> *toDelete = head;
            head = head->next;
            head->prev = nullptr;

            toDelete->prev = toDelete->next = nullptr;
            delete toDelete;
        }
        currSize--;
    }

    // to pop element from end --> O(1)
    void pop_back()
    {
        if (tail == nullptr)
            return;
        else if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node<T> *toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;

            toDelete->prev = toDelete->next = nullptr;
            delete toDelete;
        }
        currSize--;
    }

    // to check wether the deque is empty or not --> O(1)
    bool empty() const
    {
        return head == nullptr;
    }

    // to get the current size of deque --> O(1)
    int size() const
    {
        return currSize;
    }

    // to get the first element of deque --> O(1)
    T front() const
    {
        if (head == nullptr)
            throw runtime_error("Deque is empty!");

        return head->data;
    }

    // to get the last element of deque --> O(1)
    T back() const
    {
        if (tail == nullptr)
            throw runtime_error("Deque is empty!");

        return tail->data;
    }

    // to prin the deque elements --> O(n)
    void print() const
    {
        if (head == nullptr)
        {
            cout << "\nDeque is empty!\n\n";
        }
        else
        {
            Node<T> *temp = head;
            cout << "\nDeque: ";
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "\n\n";
        }
    }
};

int main()
{
    Deque<int> dq;

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

    dq.print(); // 10 20 30 40 50 60 70 80 90 100
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << "\n\n";

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
    cout << "Size : " << dq.size() << "\n\n";

    dq.pop_back();  // delete 200
    dq.pop_back();  // delete 80
    dq.pop_back();  // delete 70
    dq.pop_back();  // delete 60
    dq.pop_front(); // delete 20
    dq.pop_front(); // delete 30
    dq.pop_front(); // delete 40
    dq.pop_front(); // delete 50

    dq.print(); // empty
    // cout << "Front : " << dq.front() << endl; // throw runtime error
    // cout << "Rear : " << dq.back() << endl;   // throw runtime error
    cout << "Size : " << dq.size() << endl; // 0

    dq.push_back(100);
    dq.push_front(10);

    dq.print(); // 10 100
    cout << "Front : " << dq.front() << endl;
    cout << "Rear : " << dq.back() << endl;
    cout << "Size : " << dq.size() << endl;
    cout << "Is Deque Empty : " << (dq.empty() ? "Yes" : "No") << endl;

    return 0;
}