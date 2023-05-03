// DNF stands for Dutch National Flag algorithm. DNF sort is also called 0,1,2 sort because there are only three elements (0, 1 and 2) present in our array
 
 /*
 zeros    ones      unknown     twos
 _____   _______    _______     _____
 0   0   1  1  1    ?  ?  ?     2   2
         ^          ^           ^
         |          |           |
        low        mid         high

Procedure :
Check value of arr[mid]-
if 0, swap arr[low] and arr[mid], low++, mid++
if 1, mid++
if 2, swap arr[mid] and arr[high], high--

Time complexity = O(n)
 */

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void dnfSort(int arr[], int n){
    int low = 0;
    int mid = 0;
    int high = n-1;

    while (mid<=high)
    {
        if(arr[mid] == 0){
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr, mid, high);
            high--;
        }
    }
}

int main(){
    int arr[] = {1,0,2,1,0,1,2,1,2};

    dnfSort(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}