#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = value.size();

    // initialize table
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // fill the table
    for (int i = n - 1; i >= 0; i--)
    {
        for (int w = 0; w <= capacity; w++)
        {
            // include current item
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + dp[i][w - weight[i]];
            }

            // exclude current item
            int exclude = dp[i + 1][w];

            // store ans
            dp[i][w] = max(include, exclude);
        }
    }

    return dp[0][capacity];
}

int main()
{
    // Ans = 16 (4 items of weight 2 : value = 4 * 4 = 16)
    vector<int> weights = {2, 3, 4}; // sample weights
    vector<int> values = {4, 5, 6};  // sample values
    int capacity = 8;

    int maxValue = unboundedKnapsack(weights, values, capacity);

    cout << "Maximum value = " << maxValue << endl;

    return 0;
}