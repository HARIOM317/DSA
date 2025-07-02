#include <iostream>

using namespace std;

int firstOccurence(int *arr, int n, int i, int num)
{
    // base case
    if (i == n)
        return -1;

    if (arr[i] == num)
        return i;

    return firstOccurence(arr, n, i + 1, num);
}

int main()
{
    int arr[] = {1, 2, 4, 3, 3, 5, 4, 6, 7, 7, 5, 8, 9, 10};
    int n = sizeof(arr) / sizeof(n);
    int num = 5;

    cout << "First occurence of " << num << " at index " << firstOccurence(arr, n, 0, num) << endl;

    return 0;
}