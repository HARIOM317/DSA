#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // equivalent to (low+high)/2, but it is correct for integer range that is 2^31-1, because int can't store value more than this range.
        if (arr[mid] < key)
            low = mid + 1;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    int result = binarySearch(arr, 10, key);
    if (result != -1)
    {
        cout << "Element is present at index " << result << endl;
    }
    else
    {
        cout << "Element is not present in array" << endl;
    }

    return 0;
}