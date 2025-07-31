#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    vector<int> v;

public:
    void push(int val) // O(1)
    {
        v.push_back(val);
    }

    void pop() // O(1)
    {
        if (v.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }

        v.pop_back();
    }

    int top() // O(1)
    {
        return v[v.size() - 1];
    }

    bool empty() // O(1)
    {
        return v.size() == 0;
    }

    void print() // O(n)
    {
        if (v.empty())
        {
            cout << "\nStack is empty!\n\n";
            return;
        }

        cout << "\nStack: ";
        for (int num : v)
        {
            cout << num << " ";
        }
        cout << "\n\n";
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.print();
    cout << "Top: " << st.top() << endl;

    st.pop();
    st.pop();
    st.pop();

    st.print();
    cout << "Top: " << st.top() << endl;
    cout << "Is stack empty: " << (st.empty() ? "Yes" : "No") << endl;

    st.pop();
    st.pop();

    st.print();
    cout << "Is stack empty: " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}