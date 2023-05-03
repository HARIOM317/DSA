#include <bits/stdc++.h>

using namespace std;

/*
    Sum of continues positive integer

    Array =    -1  4  -6  7  -4

    Current    -1  4  -2  7  3
    sum         ^      ^  ^
                |      |  |
                0      0  max sum

*/

int main()
{
    // FINDING MAXIMUM SUM OF SUB ARRAY USING KADANE'S ALGORITHMS

    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements :\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(currSum, maxSum);
    }

    cout << "Maximum sum of sub-array is : " << maxSum << endl;

    return 0;
}