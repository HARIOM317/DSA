#include <iostream>

using namespace std;

int catalan(int n)
{
    if (n <= 1)
        return 1;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Catalan numbers from 0 to " << n << " are as follow-" << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << catalan(i) << " ";
    }

    return 0;
}