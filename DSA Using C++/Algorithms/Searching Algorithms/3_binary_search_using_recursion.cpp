#include <iostream>
#include <vector>

using namespace std;

int recursiveBinarySearch(vector<int> arr, int start, int end, int target)
{
    if (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
            return recursiveBinarySearch(arr, mid + 1, end, target);
        else if (arr[mid] > target)
            return recursiveBinarySearch(arr, start, mid - 1, target);
        else
            return mid;
    }
    return -1;
}

int main()
{
    vector<int> arr = {5, 7, 9, 11, 16, 18, 23, 33, 55, 59, 78, 89, 92, 100};
    int target = 89;
    int result = recursiveBinarySearch(arr, 0, arr.size() - 1, target);
    cout << "Element " << target << " is present at index " << result << endl;

    return 0;
}