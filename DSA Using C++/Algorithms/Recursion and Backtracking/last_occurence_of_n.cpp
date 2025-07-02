#include <iostream>

using namespace std;

int lastOccurence(int *arr, int n, int i, int num)
{
    // base case
    if (i < 0)
        return -1;

    if (arr[i] == num)
        return i;

    return lastOccurence(arr, n, i - 1, num);
}

int main()
{
    int arr[] = {1, 2, 4, 3, 3, 5, 4, 6, 7, 7, 5, 8, 9, 10};
    int n = sizeof(arr) / sizeof(n);
    int num = 5;

    cout << "Last occurence of " << num << " at index " << lastOccurence(arr, n, n - 1, num) << endl;

    return 0;
}