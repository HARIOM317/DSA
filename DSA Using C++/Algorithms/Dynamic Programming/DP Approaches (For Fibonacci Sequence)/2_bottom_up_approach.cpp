#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    // base case
    if (n <= 1)
        return n;

    // Tabulation Method - table to store fibonacci numbers
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    // build table iteratively
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    cout << "Bottom-Up (Tabulation) Fibonacci(" << n << ") = " << fib(n) << endl;

    return 0;
}