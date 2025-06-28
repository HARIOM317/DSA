#include <iostream>

using namespace std;

long long fastExpo(int x, int n)
{
    long long ans = 1;

    while (n > 0)
    {
        int lastBit = n & 1;

        if (lastBit == 1)
        {
            ans = ans * x;
        }
        x = x * x;

        n = n >> 1;
    }

    return ans;
}

int main()
{
    cout << "Pow(3, 5) = " << fastExpo(3, 5) << endl;
    cout << "Pow(2, 10) = " << fastExpo(2, 10) << endl;

    return 0;
}