#include <iostream>
#include <vector>

using namespace std;

// Utility functions
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
    vector<int> dp(n + 1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i - 1], k - 1), mul(dp[i - 2], k - 1));
    }

    return dp[n];
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