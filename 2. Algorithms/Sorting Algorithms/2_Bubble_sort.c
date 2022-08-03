#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubble_sort_Normal(int *A, int n)
{
    for (int i = 0; i < n - 1; i++) // For number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        { // For comparision in each pass
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_Adaptive(int *A, int n)
{
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++) // For number of passes
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        { // For comparision in each pass
            if (A[j] > A[j + 1])
            {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    // int A[] = {12, 34, 87, 13, 4, 5, 34, 90, 76, 43, 1, 8, 36, 4, 9};
    int A[] = {1, 2, 3, 5, 7, 9, 11, 12, 14, 16, 22, 23, 34, 45, 55};
    int n = 15;
    printf("Given array is :  \n");
    printArray(A, n);
    // bubble_sort_Normal(A, n);    
    bubble_sort_Adaptive(A, n);
    printf("\nSorted array is :  \n");
    printArray(A, n);

    return 0;
}