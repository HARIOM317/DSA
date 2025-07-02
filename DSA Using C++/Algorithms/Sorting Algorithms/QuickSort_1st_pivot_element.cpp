/*
    Quick sort also works on divide and conquer algorithm
        Time complexity:
            best case - O(NlogN)
            worst case - O(N^2)

        Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = high;

    for (int j = high; j > low; j--)
    {
        if (arr[j] > pivot)
        {
            swap(arr[i], arr[j]);
            i--;
        }
    }
    swap(arr[low], arr[i]);
    return i;
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
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter arrays elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorting array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}