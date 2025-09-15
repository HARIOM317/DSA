#include <iostream>

using namespace std;

int getMaxProfit(int *arr, int n)
{
    int maxProfit = 0, buy = arr[0];
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - buy;
        maxProfit = max(maxProfit, diff);
        buy = min(buy, arr[i]);
    }
    return maxProfit;
}

int main()
{
    int prices[] = {2, 3, 4, 7, 2, 9, 5, 11, 8};
    int n = sizeof(prices) / sizeof(int);

    cout << "Max profit : " << getMaxProfit(prices, n) << endl;

    return 0;
}