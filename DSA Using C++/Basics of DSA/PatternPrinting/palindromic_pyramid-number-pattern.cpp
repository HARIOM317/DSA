#include <iostream>

using namespace std;

// Pyramid of numbers
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int num = 1;
        for (int j = 1; j <= 2 * n - 1; j++)
        {
            // left side spaces
            if (j <= n - i)
            {
                cout << "  ";
            }
            // right side spaces
            else if (j >= n + i)
            {
                cout << "  ";
            }
            // number
            else
            {
                if (j < n)
                {
                    cout << num << " ";
                    num++;
                }
                else
                {
                    cout << num << " ";
                    num--;
                }
            }
        }
        cout << endl;
    }

    return 0;
}