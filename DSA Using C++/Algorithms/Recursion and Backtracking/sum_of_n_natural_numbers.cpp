#include <iostream>

using namespace std;

int sum(int n)
{
    // base condition
    if (n == 0)
        return 0;
    return n + sum(n - 1); // Recursive call
}

int main()
{
    int n = 10;
    cout << "Sum of first " << n << " natural numbers is " << sum(n) << endl;

    return 0;
}