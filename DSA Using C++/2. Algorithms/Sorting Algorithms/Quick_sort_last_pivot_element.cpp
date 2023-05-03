// Quick sort also works on divide and conquer algorithm
/*
Time complexity:
best case - O(NlogN)
worst case - O(N^2)
*/
#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for (int j = low; j < high; j++)
    {
        if (arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i+1, high);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if (low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int n = 10;

    int arr[n] = {12, 43, 11, 8, 5, 23, 9, 57, 100, 75};

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array is\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}