#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;

    vector<int> dp(n, 1); // Each element is an LIS of length 1 by itself
    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    // Ans = 4 (2, 5, 7, 101)
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Maximum Length of LIS : " << lengthOfLIS(nums);

    return 0;
}