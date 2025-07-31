#include <iostream>

using namespace std;

// Node (generic)
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        cout << "Popped: " << this->data << endl;
    }
};

// Stack (generic)
template <typename T>
class Stack
{
    Node<T> *head;

public:
    Stack()
    {
        head = nullptr;
    }

    void push(T val) // O(1)
    {
        Node<T> *newNode = new Node<T>(val);
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

        Node<T> *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }

    T top() // O(1)
    {
        if (head == nullptr)
        {
            cout << "Stack is empty!\n";
            return T(); // default value
        }
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

        Node<T> *temp = head;
        cout << "\nStack: ";
        while (temp != nullptr)
        {
            cout << temp->data << (temp->next ? ", " : "");
            temp = temp->next;
        }
        cout << "\n\n";
    }
};

int main()
{
    Stack<string> s;
    cout << "Is stack empty: " << (s.empty() ? "Yes" : "No") << endl;

    // push operation
    s.push("Red");
    s.push("Blue");
    s.push("Green");
    s.push("Pink");
    s.push("Yellow");
    s.push("Black");
    s.push("White");
    s.push("Orange");
    s.push("Purple");
    s.push("Brown");

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