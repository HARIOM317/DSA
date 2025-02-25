#include <iostream>
#include <vector>

using namespace std;

// utility functions
int add(int a, int b)
{
    return a + b;
}
int mul(int a, int b)
{
    return a * b;
}

int solve(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, mul(k, k - 1));

    // check memory
    if (dp[n] != -1)
        return dp[n];

    // memorize ans
    dp[n] = add(mul(solve(n - 1, k, dp), k - 1), mul(solve(n - 2, k, dp), k - 1));
    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

int main()
{
    int n = 4;
    int k = 3;

    int ans = numberOfWays(n, k);
    cout << "Total number of ways to paint the fence : " << ans << endl;

    return 0;
}