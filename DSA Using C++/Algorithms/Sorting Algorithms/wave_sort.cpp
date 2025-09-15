/*
Note: In wave sort we have sort our array in a wave form, like-
arr[0]>=arr[1]<=arr[2]>=arr[3]<=arr[4]>=....

arr[0]--           -- arr[2] --           --arr[4]--
        |         |            |         |         |
        --arr[1]--             --arr[3]--          --arr[5]

Approach:
for i=1 to n-1
{
    if arr[i]>arr[i-1]
        swap(arr, i, i-1)

    if arr[i]>arr[i+1] && i<=n-2
        swap(arr, i, i+1)

    i+=2
}

Time complexity = O(n/2) = O(n)
*/

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void waveSort(int arr[], int n)
{
    for (int i = 1; i < n; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }
        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr, i, i + 1);
        }
    }
}

int main()
{
    int arr[] = {1, 3, 4, 7, 5, 6, 2, 11, 13, 14, 9, 22};

    waveSort(arr, 12);

    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}