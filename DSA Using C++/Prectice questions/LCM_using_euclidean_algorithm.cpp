#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a = 28, b = 20;
    // NOTE: a*b = gcd(a, b) * lcm(a, b)
    // Hence, lcm(a, b) = (a*b)/gcd(a, b)

    int lcm = (a * b) / gcd(a, b);

    cout << "LCM of a and b is: " << lcm << endl;

    return 0;
}