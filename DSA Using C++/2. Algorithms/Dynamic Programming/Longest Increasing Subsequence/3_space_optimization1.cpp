#include <iostream>
#include <vector>

using namespace std;

int lis(vector<int> &arr)
{
    int n = arr.size();

    vector<int> currRow(n + 1, 0);
    vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            // include
            int include = 0;
            if (prev == -1 || arr[curr] > arr[prev])
            {
                include = 1 + nextRow[curr + 1];
            }

            // exclude
            int exclude = nextRow[prev + 1];

            currRow[prev + 1] = max(include, exclude);
        }

        nextRow = currRow;
    }

    return nextRow[0];
}

int main()
{
    // Ans = 4 (2, 5, 7, 101)
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Maximum Length of LIS : " << lis(nums);

    return 0;
}