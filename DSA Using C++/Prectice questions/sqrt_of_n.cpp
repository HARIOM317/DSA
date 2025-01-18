#include <iostream>

using namespace std;

double sqrt(int n)
{
    // Step: 1 - Calculating integer part of the sqrt
    int start = 0, end = n, intPart = -1;
    while (start <= end)
    {
        int mid = start + (mid - start) / 2;
        if (mid > n / mid)
        {
            end = mid - 1;
        }
        else if (mid < n / mid)
        {
            intPart = mid;
            start = mid + 1;
        }
        else
        {
            intPart = mid;
            break;
        }
    }

    // Step: 2 - Calculating floating part till precision no. of digits
    int precision = 5;
    double factor = 1, ans = intPart;

    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j < n / j; j += factor)
        {
            ans = j;
        }
    }

    return ans;
}

int main()
{
    int n = 19;
    cout << "Square root of " << n << " is " << sqrt(n) << endl;

    return 0;
}