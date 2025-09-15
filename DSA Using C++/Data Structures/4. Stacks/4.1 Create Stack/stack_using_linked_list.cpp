#include <iostream>

using namespace std;

// Node
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Popped: " << this->data << endl;
    }
};

// Stack
class Stack
{
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(int val) // O(1)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void pop() // O(1)
    {
        if (head == nullptr)
        {
            cout << "Stack underflow!\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    int top() // O(1)
    {
        if (head == nullptr)
            return -1;
        return head->data;
    }

    bool empty() // O(1)
    {
        return head == nullptr;
    }

    void print()
    {
        if (head == nullptr)
        {
            cout << "\nStack is empty!\n\n";
        }

        Node *temp = head;
        cout << "\nStack: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    Stack s;
    cout << "Is stack empty: " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Top element: " << s.top() << endl;

    // push operation
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);

    s.print();

    // pop operation
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.print();

    cout << "Is stack empty: " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Top element: " << s.top() << endl;

    return 0;
}