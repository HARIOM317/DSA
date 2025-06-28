#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int mcm(vector<int> &p)
{
    int n = p.size() - 1;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // create and initialize table

    // fill the table
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = (dp[i][k] + dp[k + 1][j]) + (p[i - 1] * p[j] * p[k]);
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    return dp[1][n];
}

int main()
{
    // Dimension becomes : (A = [10x30], B = [30x5], C = [5x60])
    vector<int> p = {10, 30, 5, 60};

    cout << "Minimum number of multiplications = " << mcm(p) << endl;

    return 0;
}