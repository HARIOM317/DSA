#include <iostream>

using namespace std;

/*
Inversion Count - (Using merge sort):
In an array, an inversion occurs when:

A pair of indices (i,j) exists such that i<j and arr[i]>arr[j].

For example:
In the array [2, 4, 1, 3, 5], the inversions are:
(2, 1), (4, 1), (4, 3), resulting in a total count of 3 inversions.

The inversion count measures how far the array is from being sorted:

If the array is already sorted, the count is 0.
If the array is sorted in reverse order, the count is at its maximum.
*/

void merge(int *arr, int start, int end, int &inversionCount)
{
    int mid = start + (end - start) / 2;

    int n1 = mid - start + 1;
    int n2 = end - mid;

    int *first = new int[n1];
    int *second = new int[n2];

    int index = start;
    // copy items
    for (int i = 0; i < n1; i++)
    {
        first[i] = arr[index++];
    }

    index = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        second[i] = arr[index++];
    }

    int i = 0, j = 0;
    index = start;

    while (i < n1 && j < n2)
    {
        if (first[i] <= second[j])
        {
            arr[index++] = first[i++];
        }
        else
        {
            arr[index++] = second[j++];
            inversionCount += (n1 - i);
        }
    }

    while (i < n1)
    {
        arr[index++] = first[i++];
    }

    while (j < n2)
    {
        arr[index++] = second[j++];
    }
}

void mergeSort(int *arr, int start, int end, int &inversionCount)
{
    int mid = start + (end - start) / 2;

    if (start >= end)
        return;

    mergeSort(arr, start, mid, inversionCount);
    mergeSort(arr, mid + 1, end, inversionCount);
    merge(arr, start, end, inversionCount);
}

int main()
{
    int arr[10] = {1, 2, 7, 6, 3, 5, 4, 8, 9, 10};
    int inversionCount = 0;

    cout << "Sorted array is: ";
    int n = 10;
    mergeSort(arr, 0, n - 1, inversionCount);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nInversion count: " << inversionCount << endl;

    /*
    Inversion count is 8, because-
    7 > 6
    7 > 3
    7 > 5
    7 > 4
    6 > 3
    6 > 5
    6 > 4
    5 > 4
    */

    return 0;
}