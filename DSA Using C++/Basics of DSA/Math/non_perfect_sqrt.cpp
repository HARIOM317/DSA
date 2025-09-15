#include <iostream>

using namespace std;

double EPSILON = 1e-9; // accurate upto 8 decimal places

// Time complexity: O(log(n * 10^9)) because of EPSILON
double sqrt(double n)
{
    double st = 1, end = n;
    while (end - st > EPSILON)
    {
        double mid = st + (end - st) / 2;
        if (mid < n / mid)
            st = mid;
        else
            end = mid;
    }
    return st; // or end
}

int main()
{
    double n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Square root = " << sqrt(n) << endl;

    return 0;
}