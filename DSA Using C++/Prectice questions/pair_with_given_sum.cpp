#include <bits/stdc++.h>

using namespace std;

void findPair(int arr[], int arr_size, int sum){
    sort(arr, arr+arr_size);
    int low = 0;
    int high = arr_size-1;
    while (low<high)
    {
        if(arr[low]+arr[high] == sum){
            cout<<"Pair Found ("<<arr[low]<<", "<<arr[high]<<")\n";
            return;
        }
        else if(arr[low]+arr[high] < sum){
            low++;
        }
        else{
            high--;
        }
    }
    cout<<"Pair Not Found!";
}

int main(){
    int arr[] = {1, 25, 4, 5, 7, 9, 8, 3, 2, 10};
    int sum = 17;
    int arr_size = sizeof(arr)/sizeof(int);

    findPair(arr, arr_size, sum);

    return 0;
}