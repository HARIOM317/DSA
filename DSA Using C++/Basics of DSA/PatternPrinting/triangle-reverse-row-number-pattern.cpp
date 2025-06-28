#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 0; j--)
        {
            printf("%3d ", j);
        }
        cout << endl;
    }

    return 0;
}