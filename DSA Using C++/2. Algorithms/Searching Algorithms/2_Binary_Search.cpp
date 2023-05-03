#include <iostream>

using namespace std;

int binarySearch(int arr[], int n, int key)
{
    int starting_point = 0;
    int ending_point = n;
    while (starting_point <= ending_point)
    {
        int mid = (starting_point + ending_point) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            ending_point = mid - 1;
        }
        else
        {
            starting_point = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter size of array:  ";
    cin >> n;
    int arr[n];
    cout << "Enter arrays element in sorting order: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "Enter key for searching :   ";
    cin >> key;

    cout << "Element " << key << " presents on index " << binarySearch(arr, n, key);
    return 0;
}