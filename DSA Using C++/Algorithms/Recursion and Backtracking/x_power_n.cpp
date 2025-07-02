#include <iostream>

using namespace std;

// Bruteforce - (Recursive) --> O(n)
int pow(int x, int n)
{
    // base case
    if (n == 1)
        return x;
    return x * pow(x, n - 1);
}

// Optimized (Recursive) --> O(log n)
int fastPow(int x, int n)
{
    // base case
    if (n == 0)
        return 1;

    // calculate half power --> pow(x, n/2);
    int halfPow = pow(x, n / 2);
    int halfPowSquare = halfPow * halfPow;

    // if n is odd
    if (n & 1)
        return x * halfPowSquare;

    // if n is even
    return halfPowSquare;
}

int main()
{
    // using pow();
    cout << pow(3, 3) << endl;
    cout << pow(2, 8) << endl;
    cout << pow(5, 4) << endl;

    // using fastPow()
    cout << endl
         << pow(3, 3) << endl;
    cout << pow(2, 8) << endl;
    cout << pow(5, 4) << endl;

    return 0;
}