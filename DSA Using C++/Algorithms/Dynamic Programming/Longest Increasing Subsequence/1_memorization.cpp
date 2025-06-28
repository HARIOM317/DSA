#include <iostream>
#include <vector>

using namespace std;

int solveLIS(vector<int> &arr, int n, int curr, int prev, vector<vector<int>> &dp)
{
    // base case
    if (curr == n)
        return 0;

    // check memory
    if (dp[curr][prev + 1] != -1)
        return dp[curr][prev + 1];

    // include element
    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev])
    {
        include = 1 + solveLIS(arr, n, curr + 1, curr, dp);
    }

    // exclude element
    int exclude = solveLIS(arr, n, curr + 1, prev, dp);

    // memorize and return the ans
    return dp[curr][prev + 1] = max(include, exclude); // because prev starts from index -1
}

int lis(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveLIS(arr, n, 0, -1, dp);
}

int main()
{
    // Ans = 4 (2, 5, 7, 101)
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Maximum Length of LIS : " << lis(nums);

    return 0;
}