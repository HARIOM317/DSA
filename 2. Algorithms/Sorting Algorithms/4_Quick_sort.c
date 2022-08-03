#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void Quick_sort(int arr[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        printArray(arr, 10);
        Quick_sort(arr, low, partitionIndex - 1);  // Sort left sub-Array
        Quick_sort(arr, partitionIndex + 1, high); // Sort right sub-Array
    }
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    int n = 10;
    printf("Before sorting Array is: \n");
    printArray(arr, n);
    printf("\n");
    Quick_sort(arr, 0, n-1);
    printf("\nAfter sorting Array is: \n");
    printArray(arr, n);
    printf("\n");

    return 0;
}