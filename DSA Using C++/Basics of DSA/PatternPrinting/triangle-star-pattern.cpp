#include <iostream>

using namespace std;

// Triangle pattern of stars
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}