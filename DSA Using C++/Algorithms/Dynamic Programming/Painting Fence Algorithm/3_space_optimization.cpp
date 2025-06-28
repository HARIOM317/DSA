#include <iostream>
#include <vector>

using namespace std;

// Utility function
int add(int a, int b)
{
    return a + b;
}
int mul(int a, int b)
{
    return a * b;
}

int numberOfWays(int n, int k)
{
    int a = k;
    int b = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int ans = add(mul(a, k - 1), mul(b, k - 1));
        a = b;
        b = ans;
    }

    return b;
}

int main()
{
    int n = 4;
    int k = 3;

    int ans = numberOfWays(n, k);
    cout << "Total number of ways to paint the fence : " << ans << endl;

    return 0;

    return 0;
}