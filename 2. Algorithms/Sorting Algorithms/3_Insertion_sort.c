#include<stdio.h>

void printArray(int * arr, int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSortAssending(int * arr, int n){
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (arr[j] > key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

void insertionSortDecending(int * arr, int n){
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i-1;
        while (arr[j] < key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}

int main(){
    int arr[] = {12,45,2,4,7,8,9,76,54,32};
    int n = 10;
    printf("Before sort Array is: \n");
    printArray(arr, n);
    printf("\n");
    insertionSortAssending(arr, n);
    printf("After sorting in Assending order Array is: \n");
    printArray(arr, n);
    
    insertionSortDecending(arr, n);
    printf("After sorting in Decending order Array is: \n");
    printArray(arr, n);

    return 0;
}