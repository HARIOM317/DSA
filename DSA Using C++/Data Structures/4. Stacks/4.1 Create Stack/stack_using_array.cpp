#include <iostream>

using namespace std;

class Stack
{
    // properties
    int *arr;
    int size;
    int top;

public:
    // constructor
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int[size];
    }

    // to push element - O(1)
    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack overflow!\n";
            return;
        }

        top++;
        arr[top] = val;
    }

    // to pop element - O(1)
    void pop()
    {
        if (top == -1)
        {
            cout << "stack underflow!\n";
            return;
        }
        arr[top] = 0;
        top--;
    }

    // to get top element - O(1)
    int peek()
    {
        if (top == -1)
        {
            cout << "stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    // to check stack is empty or not - O(1)
    bool empty()
    {
        return top == -1;
    }

    // to print the stack elements - O(n)
    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(10);

    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Peek: " << st.peek() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.push(80);
    st.push(90);
    st.push(100);
    st.push(110); // stack overflow

    cout << "Stack elements: ";
    st.print();

    st.pop();
    st.pop();
    st.pop();

    cout << "Stack elements after pop: ";
    st.print();

    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Peek: " << st.peek() << endl;

    return 0;
}