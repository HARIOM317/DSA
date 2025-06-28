#include <iostream>
#include <vector>

using namespace std;

int solveKnapsack(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        return (weight[0] <= capacity) ? value[0] : 0;
    }

    // Check memory
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    // include current item
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveKnapsack(weight, value, index - 1, capacity - weight[index], dp);
    }

    // exclude current item
    int exclude = solveKnapsack(weight, value, index - 1, capacity, dp);

    // Memorize the ans
    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}

int knapsack(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1)); // initialize 2D dp matrix with -1

    return solveKnapsack(weight, value, n - 1, capacity, dp);
}

int main()
{
    // Ans = 13
    int n = 10;       // 10 items
    int capacity = 5; // capacity 5 kg

    vector<int> weight = {1, 2, 3, 2, 1, 2, 1, 3, 2, 1};
    vector<int> value = {1, 2, 5, 3, 3, 4, 2, 7, 6, 1};

    int maxValue = knapsack(weight, value, n, capacity);
    cout << "Maximum value = " << maxValue << endl;

    return 0;
}