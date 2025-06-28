#include <iostream>

using namespace std;

// Square Pattern
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}