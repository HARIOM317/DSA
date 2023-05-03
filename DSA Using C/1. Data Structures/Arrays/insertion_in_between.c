# include <stdio.h>

void insert(int arr[], int value, int index, int size){
    int temp[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = index; i < size-1; i++)
    {
        arr[i+1] = temp[i];
    }
    arr[index] = value;
}

int main(){
    int arr[10] = {2, 5, 8, 19, 89, 10};
    insert(arr, 20, 0, 10);
    insert(arr, 30, 2, 10);
    insert(arr, 50, 7, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}