#include <iostream>
#include <vector>

using namespace std;

int getPivotIndex(vector<int> &arr)
{
    int start = 0, end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
            start = mid + 1;
        else
            end = mid;
    }
    return start; // also can return end, because both start and end will point the same point too terminate the loop (start < end)
}

int main()
{
    vector<int> arr = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};

    cout << "Pivot Index = " << getPivotIndex(arr) << endl;

    return 0;
}