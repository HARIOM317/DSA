#include <iostream>

using namespace std;

//  GCD (HCF) = Greatest Common Divisor (Highest Common factor)

/*
Principle of Euclid algorithm:

Suppose numbers are 42 and 24

*first approach:
42 - 24 = 18
24 - 18 = 6
18 - 6  = 12
12 - 6  = 6 (answer)
6  - 6  = 0 (breaking point)

*second and better approach:
42 % 24 = 18
24 % 18 = 6 (answer)
18 % 6  = 0 (breaking point)
*/

int gcdRecursive(int a, int b)
{
    if (a == 0)
        return b;
    return gcdRecursive(b % a, a);
}

int main()
{
    int a, b;
    cout << "Enter two numbers for GCD/HCF : ";
    cin >> a >> b;

    cout << "GCD using Recursive approach = " << gcdRecursive(a, b) << endl;

    return 0;
}