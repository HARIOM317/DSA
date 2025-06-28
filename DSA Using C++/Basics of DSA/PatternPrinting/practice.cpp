#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = i; j >= 0; j--)
        {
            cout << j + 1 << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}