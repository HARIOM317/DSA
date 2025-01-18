#include <iostream>

using namespace std;

void multiplyMatrix(int F[2][2], int M[2][2])
{
    int p = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int q = F[0][0] * M[1][0] + F[0][1] * M[1][1];
    int r = F[0][1] * M[0][0] + F[1][1] * M[1][0];
    int s = F[0][1] * M[1][0] + F[1][1] * M[1][1];

    // overriding matrix F values
    F[0][0] = p;
    F[0][1] = q;
    F[1][0] = r;
    F[1][1] = s;
}

void powerMatrix(int F[2][2], int n)
{
    // base case
    if (n == 0 || n == 1)
        return;

    // creating 2x2 matrix, if n is odd number
    int M[2][2] = {{1, 1}, {1, 0}};

    powerMatrix(F, n / 2); // recursive call for n/2

    multiplyMatrix(F, F);

    if (n & 1) // if n is odd
        multiplyMatrix(F, M);
}

int fibonacciNumber(int n)
{
    if (n == 0)
        return 0;

    int F[2][2] = {{1, 1}, {1, 0}};

    powerMatrix(F, n - 1);

    return F[0][0]; // F[0][0] contains nth fibonacci number
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << n << "th fibonacci number = " << fibonacciNumber(n) << endl;

    return 0;
}