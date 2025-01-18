/*
given array:
data    1   3   2   3   4   1   6   4   3
index   0   1   2   3   4   5   6   7   8

count array:
data    0   2   1   3   2   0   1
index   0   1   2   3   4   5   6

sorted array:
1   1   2   3   3   3   4   4   6
*/

#include <iostream>
using namespace std;

void CountSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int *output = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    delete[] output;
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