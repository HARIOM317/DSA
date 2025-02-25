#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<int> dp(capacity + 1, 0);

    // base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            dp[w] = value[0];
        }
        else
        {
            dp[w] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int w = capacity; w >= 0; w--)
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
    // Ans = 21
    int n = 10;       // 10 items
    int capacity = 8; // capacity 8 kg

    vector<int> weight = {2, 3, 1, 4, 2, 1, 3, 2, 1, 3};
    vector<int> value = {4, 5, 3, 7, 4, 2, 6, 3, 4, 8};

    int maxValue = knapsack(weight, value, n, capacity);
    cout << "Maximum value = " << maxValue << endl;

    return 0;
}