#include <iostream>

using namespace std;

long long pow(int a, int b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
            result *= a;

        a *= a;
        b = b >> 1;
    }
    return result;
}

// NOTE: An armstrong number is a number that is equal to the sum of cubes of its digits.
// For example, 153 is an Armstrong number since 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153

bool isArmStrongNumber(int n)
{
    int sum = 0, num = n;
    while (num != 0)
    {
        int digit = num % 10;
        int digitCube = pow(digit, 3);
        sum += digitCube;
        num /= 10;
    }

    return sum == n ? true : false;
}

int main()
{
    int n = 371;

    cout << "Is Armstrong number: " << (isArmStrongNumber(n) ? "Yes" : "No") << endl;

    return 0;
}