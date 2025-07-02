#include <iostream>

using namespace std;

// Note: Merge sort algorithm follows divide and conquer algorithm
// Time complexity = O(nlogn)
// Space complexity = O(n)

// Time: O(n)
void merge(int *arr, int st, int mid, int end)
{
    int i = st;
    int j = mid + 1;
    int n = end - st + 1; // size of array

    // auxilary array
    int *temp = new int[n];

    int index = 0;
    // arrange elements in temp array in sorted order
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[index++] = arr[i++];
        }
        else
        {
            temp[index++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[index++] = arr[i++];
    }

    while (j <= end)
    {
        temp[index++] = arr[j++];
    }

    // copy sorted elements in original array
    for (int i = 0; i < n; i++)
    {
        arr[st + i] = temp[i];
    }

    // delete temp array
    delete[] temp; // free memory
}

// divide
// Time: O(logn)
void mergeSort(int *arr, int st, int end)
{
    if (st < end)
    {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end); // conqure
    }
}

// To print array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3, 6, 7, 8, 9, 5, 4, 2, 1, 10};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}