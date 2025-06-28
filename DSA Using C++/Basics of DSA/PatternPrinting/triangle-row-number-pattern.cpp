#include <iostream>

using namespace std;

// pattern of triangle using row number
int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%3d ", i);
        }
        cout << endl;
    }

    return 0;
}