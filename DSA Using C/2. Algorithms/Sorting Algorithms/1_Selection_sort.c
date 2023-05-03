#include<stdio.h>

void printArray(int * arr, int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int * arr, int n){
    int indexofMin;
    for (int i = 0; i < n-1; i++)
    {
        indexofMin = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[indexofMin]){
                indexofMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexofMin];
        arr[indexofMin] = temp;
    }
    
}

int main(){
    int arr[] = {12,45,2,4,7,8,9,76,54,32};
    int n = 10;
    printf("Before sort Array is: \n");
    printArray(arr, n);
    printf("\n");
    selectionSort(arr, n);
    printf("After sort Array is: \n");
    printArray(arr, n);
    printf("\n");

    return 0;
}