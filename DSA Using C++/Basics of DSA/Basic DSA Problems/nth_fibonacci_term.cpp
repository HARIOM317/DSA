#include <iostream>

using namespace std;

int nthFibonacciTerm(int n)
{
    if (n == 0 || n == 1)
        return n;

    int first = 0, second = 1;
    for (int i = 2; i <= n; i++)
    {
        int newTerm = first + second;
        first = second;
        second = newTerm;
    }

    return second;
}

int main()
{
    int n;
    cout << "Enter value of n : ";
    cin >> n;

    cout << n << "th Fibonacci term = " << nthFibonacciTerm(n) << endl;

    return 0;
}