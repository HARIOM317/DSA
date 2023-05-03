#include <iostream>

using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int min(int a, int b){
    return a<b?a:b;
}

int findMax_recursive(int arr[], int n){
    if(n==1){
        return arr[0];
    }
    return(max(arr[n-1], findMax_recursive(arr, n-1)));
}

int findMin_recursive(int arr[], int n){
    if(n==1){
        return arr[0];
    }
    return(min(arr[n-1], findMin_recursive(arr, n-1)));
}

int main(){
    int arr[] = {1, 8, 3, 2, 5, 90, 65, 13, 45, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Max = "<<findMax_recursive(arr, n)<<endl;
    cout<<"Min = "<<findMin_recursive(arr, n)<<endl;

    return 0;
}