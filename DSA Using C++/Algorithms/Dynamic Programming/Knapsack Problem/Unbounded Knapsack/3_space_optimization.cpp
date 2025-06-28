#include <iostream>
#include <vector>

using namespace std;

int unboundedKnapsack(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = value.size();
    vector<int> dp(capacity + 1, 0);

    for (int w = 0; w <= capacity; w++)
    {
        for (int i = 0; i < n; i++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + dp[w - weight[i]];
            }

            int exclude = dp[w];

            dp[w] = max(include, exclude);
        }
    }

    return dp[capacity];
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