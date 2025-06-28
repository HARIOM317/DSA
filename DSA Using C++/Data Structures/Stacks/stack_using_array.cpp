#include <iostream>

using namespace std;

class Stack
{
public:
    // properties
    int *arr;
    int top;
    int size;

    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top != size - 1) // size-top > 1
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop()
    {
        if (top != -1)
        { // top >= 0
            top--;
        }
        else
        {
            cout << "Stack underflow!" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

void print(Stack st)
{
    for (int i = 0; i <= st.top; i++)
    {
        cout << st.arr[i] << " ";
    }
    cout << endl;
}

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
    print(st);

    st.pop();
    st.pop();
    st.pop();

    cout << "Stack elements after pop: ";
    print(st);

    cout << "Is empty: " << (st.empty() ? "Yes" : "No") << endl;
    cout << "Peek: " << st.peek() << endl;

    return 0;
}