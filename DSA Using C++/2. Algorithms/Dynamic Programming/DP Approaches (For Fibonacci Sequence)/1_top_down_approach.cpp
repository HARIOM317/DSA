#include <iostream>
#include <vector>

using namespace std;

int fib(int n, vector<int> dp)
{
    // Base case
    if (n <= 1)
        return n;

    // Return stored result if available
    if (dp[n] != -1)
        return dp[n];

    // Memorization
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    vector<int> dp(n + 1, -1); // dp array for memorization

    cout << "Top-Down (Memorization) Fibonacci(" << n << ") = " << fib(n, dp) << endl;

    return 0;
}