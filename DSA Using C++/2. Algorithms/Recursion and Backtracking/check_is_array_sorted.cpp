#include <iostream>
#include <vector>

using namespace std;

bool isSorted(vector<int> arr, int n)
{
    // base case
    if (n <= 1)
        return true;

    if (arr[n - 1] < arr[n - 2])
        return false;

    return isSorted(arr, n - 1);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 10};
    cout << "Is array sorted: " << (isSorted(arr, arr.size()) ? "Yes" : "No") << endl;

    return 0;
}