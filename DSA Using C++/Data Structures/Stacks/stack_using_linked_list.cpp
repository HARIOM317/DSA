#include <iostream>

using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        Node *temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool empty()
    {
        return top == NULL;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "No any peek element!" << endl;
            return -1;
        }
        return top->data;
    }

    void print()
    {
        if (top == NULL)
            return;

        Node *temp = top;
        cout << "\nStack element: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl
             << endl;
    }
};

int main()
{
    Stack s;
    cout << "Is stack empty: " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Peek element: " << s.peek() << endl;

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
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;

    s.print();

    cout << "Is stack empty: " << (s.empty() ? "Yes" : "No") << endl;
    cout << "Peek element: " << s.peek() << endl;

    return 0;
}