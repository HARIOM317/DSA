#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> &weight, vector<int> value, int n, int capacity)
{
    vector<int> prev(capacity + 1, 0);
    vector<int> curr(capacity + 1, 0);

    // base case
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
        {
            prev[w] = value[0];
        }
        else
        {
            prev[w] = 0;
        }
    }

    // process items
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[i] <= w)
            {
                include = value[i] + prev[w - weight[i]];
            }

            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }

    return prev[capacity];
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