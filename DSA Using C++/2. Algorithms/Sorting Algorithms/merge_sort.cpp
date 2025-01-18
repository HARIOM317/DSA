#include <iostream>

using namespace std;
// Note: Merge sort algorithm follows divide and conquer algorithm
// Time complexity = NlogN

void merge(int arr[], int start, int end)
{
    int mid = start + (end - start) / 2;
    // creating two temporally arrays
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int *firstArr = new int[n1];
    int *secondArr = new int[n2];
    int index = start;

    // copying values
    for (int i = 0; i < n1; i++)
    {
        firstArr[i] = arr[index++];
    }
    index = mid + 1;
    for (int i = 0; i < n2; i++)
    {
        secondArr[i] = arr[index++];
    }

    int index1 = 0;
    int index2 = 0;
    index = start;

    // merging both arrays in sorted order
    while (index1 < n1 && index2 < n2)
    {
        if (firstArr[index1] < secondArr[index2])
        {
            arr[index++] = firstArr[index1++];
        }
        else
        {
            arr[index++] = secondArr[index2++];
        }
    }

    // merging remaining items of first array
    while (index1 < n1)
    {
        arr[index++] = firstArr[index1++];
    }
    // merging remaining items of second array
    while (index2 < n2)
    {
        arr[index++] = secondArr[index2++];
    }

    // deallocating array memory
    delete[] firstArr;
    delete[] secondArr;
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, end);
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

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}