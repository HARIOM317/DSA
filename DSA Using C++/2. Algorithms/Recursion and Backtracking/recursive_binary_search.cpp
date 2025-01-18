#include <iostream>
#include <vector>

using namespace std;

bool recursiveBinarySearch(vector<int> arr, int start, int end, int target)
{
    // base case
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == target)
        return true;
    else if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, end, target);
    else
        return recursiveBinarySearch(arr, start, mid - 1, target);
}

int main()
{
    vector<int> arr = {1, 3, 5, 8, 10, 11, 15, 19, 25, 30, 35, 40, 44, 50};
    int target = 19;

    cout << "Target element present: " << (recursiveBinarySearch(arr, 0, arr.size() - 1, target) ? "Yes" : "No") << endl;

    return 0;
}