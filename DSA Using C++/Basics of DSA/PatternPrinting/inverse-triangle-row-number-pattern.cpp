#include <iostream>

using namespace std;

// Inverse Triangle using Numbers
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j <= i)
            {
                cout << "  ";
            }
            else
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}