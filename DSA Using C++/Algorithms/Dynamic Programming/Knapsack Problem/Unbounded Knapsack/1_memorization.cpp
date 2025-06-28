#include <iostream>
#include <vector>

using namespace std;

// Helper function
int solveKnapsack(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == value.size())
        return 0;

    // check memory
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // include current item
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveKnapsack(weight, value, index, capacity - weight[index], dp);
    }

    // exclude current item
    int exclude = solveKnapsack(weight, value, index + 1, capacity, dp);

    // memorize the ans
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

// Memorization (Top-Down) Approach
int unboundedKnapsack(vector<int> &weight, vector<int> &value, int capacity)
{
    int n = value.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1)); // initializing dp array

    return solveKnapsack(weight, value, 0, capacity, dp);
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