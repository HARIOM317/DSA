/*
Problem:
Count the inversions of given array.
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i<j

3   5   6   9   1   2   7   8

Inversion = 10

Explanation:
(3,1), (3,2), (5,1), (5,2), (6,1), (6,2), (9,1), (9,2), (9,7), (9,8)
*/

#include <iostream>

using namespace std;

long long merge(int arr[], int l, int mid, int r){
    long long inv = 0;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l+i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid+i+1];
    }

    int i = 0, j = 0, k =l;
    while (i<n1 and j<n2)
    {
        if(a[i] <= b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            inv += n1 - i;
            j++;
            k++; 
        }
    }

    while (i<n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    
    while (j<n2)
    {
        arr[k] = a[j];
        j++;
        k++;
    }
    
    return inv;
}

long long mergeSort(int arr[], int l, int r){
    long long inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid+1, r);
        inv += merge(arr, l, mid, r);
    }

    return inv;
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array's element: \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"\nInversions = "<<mergeSort(arr, 0, n-1);

    return 0;
}