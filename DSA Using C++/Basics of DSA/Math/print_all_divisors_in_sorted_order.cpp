#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int n)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }

    for (int i = sqrt(n); i >= 1; i--)
    {
        if (n % i == 0)
        {
            if (i != n / i)
                cout << (n / i) << " ";
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    printDivisors(n);

    return 0;
}