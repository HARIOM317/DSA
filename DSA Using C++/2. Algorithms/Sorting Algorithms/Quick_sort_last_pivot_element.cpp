// Quick sort also works on divide and conquer algorithm
/*
Time complexity:
best case - O(NlogN)
worst case - O(N^2)
*/
#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int pivotIndex = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            pivotIndex++;
            swap(arr[pivotIndex], arr[j]);
        }
    }
    swap(arr[pivotIndex + 1], arr[high]);
    return pivotIndex + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) // base case
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[10] = {12, 43, 11, 8, 5, 23, 9, 57, 100, 75};
    int n = 10;

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}