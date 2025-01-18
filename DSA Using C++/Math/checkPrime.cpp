#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n = 2;

    if (isPrime(n))
        cout << "Prime Number" << endl;
    else
        cout << "Not Prime Number" << endl;

    return 0;
}