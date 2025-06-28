/*
given array:
data    1   3   2   3   4   1   6   4   3
index   0   1   2   3   4   5   6   7   8

count array:
freq    0   2   1   3   2   0   1
index   0   1   2   3   4   5   6

sorted array:
1   1   2   3   3   3   4   4   6
*/

#include <iostream>
#include <limits.h>

using namespace std;

void CountSort(int *arr, int n)
{
    int freq[100000] = {0};
    int minValue = INT_MAX, maxValue = INT_MIN;

    // first - O(n)
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;

        minValue = min(minValue, arr[i]);
        maxValue = max(maxValue, arr[i]);
    }

    // second - O(range) [maxValue - minValue]
    int idx = 0;
    for (int i = minValue; i <= maxValue; i++)
    {
        while (freq[i] > 0)
        {
            arr[idx++] = i;
            freq[i]--;
        }
    }
}

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    CountSort(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}