#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using the greedy method, determine the minimum number of coins required to make a given amount.

vector<int> coinChange(vector<int> &coins, int amount)
{
    // sort coins array in decreasing order
    sort(coins.rbegin(), coins.rend());

    vector<int> result;

    for (int coin : coins)
    {
        while (amount >= coin)
        {
            result.push_back(coin);
            amount -= coin;
        }
    }

    return result;
}

int main()
{
    vector<int> coins = {25, 10, 5, 1};
    int amount = 30;

    vector<int> res = coinChange(coins, amount);

    cout << "Coins used: ";
    for (int c : res)
    {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}