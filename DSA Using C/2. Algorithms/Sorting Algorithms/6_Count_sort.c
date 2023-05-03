#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int maximum(int arr[], int n)
{
    // For finding the maximum element in array
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void Count_sort(int *arr, int n)
{
    int i, j;
    // Finding the maximum element in array
    int max = maximum(arr, n);

    // Create the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Initialize all array elements to 0
    for (i = 0; i < max+1; i++)
    {
        count[i] = 0;
    }

    // Increment the corresponding index in the count array
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; // Counter for count array
    j = 0; // Counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[] = {18, 34, 98, 9, 34, 17, 93, 2, 7, 29};
    int n = 10;
    printf("Before sorting Array is: \n");
    printArray(arr, n);
    printf("\n");
    Count_sort(arr, n);
    printf("\nAfter sorting Array is: \n");
    printArray(arr, n);
    printf("\n");
    return 0;
}