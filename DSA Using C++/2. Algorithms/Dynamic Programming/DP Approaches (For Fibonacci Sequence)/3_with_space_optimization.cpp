#include <iostream>

using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;

    int a = 0; // F(n-2)
    int b = 1; // F(n-1)

    // Compute fibonacci numbers iteratively
    for (int i = 2; i <= n; i++)
    {
        int curr = a + b;
        a = b;
        b = curr;
    }

    return b;
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << "Space Optimized Fibonacci(" << n << ") = " << fib(n) << endl;

    return 0;
}