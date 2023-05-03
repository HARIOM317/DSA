#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int starting_point = 0;
    int ending_point = n;
    while (starting_point <= ending_point)
    {
        int mid = (starting_point + ending_point) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            ending_point = mid - 1;
        }
        else
        {
            starting_point = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter size of array:  ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter arrays element in sorting order: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter key for searching :   ");
    scanf("%d", &key);
    printf("Element %d presents on index %d", key, binarySearch(arr, n, key));
    return 0;
}