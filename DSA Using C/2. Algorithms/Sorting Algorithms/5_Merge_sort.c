#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[high + 1];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void Merge_sort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        Merge_sort(A, low, mid);
        Merge_sort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int arr[] = {18, 34, 98, 9, 34, 17, 93, 2, 7, 29};
    int n = 10;
    printf("Before sorting Array is: \n");
    printArray(arr, n);
    printf("\n");
    Merge_sort(arr, 0, 9);
    printf("\nAfter sorting Array is: \n");
    printArray(arr, n);
    printf("\n");
    return 0;
}