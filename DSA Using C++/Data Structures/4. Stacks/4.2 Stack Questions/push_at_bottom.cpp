#include <bits/stdc++.h>

using namespace std;

void pushAtBottom(stack<int> &st, int val)
{
    // base case
    if (st.empty())
    {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();

    pushAtBottom(st, val);
    st.push(temp);
}

int main()
{
    stack<int> st;

    pushAtBottom(st, 10);
    pushAtBottom(st, 20);
    pushAtBottom(st, 30);
    pushAtBottom(st, 40);
    pushAtBottom(st, 50);

    cout << "Top: " << st.top() << endl;

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}