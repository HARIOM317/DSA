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
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
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
    int arr[] = {10,19,18,7,16,50,4,13,2,11};
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