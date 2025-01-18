#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxAllowedTime)
{
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + arr[i] <= maxAllowedTime)
        {
            time += arr[i];
        }
        else
        {
            painters++;
            time = arr[i];
        }
    }
    return painters <= m ? true : false;
}

int minTimeToPaint(vector<int> &arr, int n, int m)
{
    int sum = 0, maxValue = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxValue = max(maxValue, arr[i]);
    }

    int start = maxValue, end = sum, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {40, 30, 10, 20};
    int n = arr.size(), m = 2;

    cout << minTimeToPaint(arr, n, m) << endl;

    return 0;
}