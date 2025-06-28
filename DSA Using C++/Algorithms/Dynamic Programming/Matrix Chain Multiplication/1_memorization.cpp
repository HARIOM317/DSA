#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solveMCM(vector<int> &p, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == j)
        return 0;

    // check memory
    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int cost = solveMCM(p, i, k, dp) + solveMCM(p, k + 1, j, dp) + (p[i - 1] * p[j] * p[k]);

        if (cost < minCost)
            minCost = cost;
    }

    // memorize ans
    dp[i][j] = minCost;
    return dp[i][j];
}

int mcm(vector<int> &p)
{
    int n = p.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveMCM(p, 1, n - 1, dp);
}

int main()
{
    // Dimension becomes : (A = [2x3], B = [3x4], C = [4x1], D = [1x3])
    vector<int> p = {2, 3, 4, 1, 3};

    cout << "Minimum number of multiplications = " << mcm(p) << endl;

    return 0;
}