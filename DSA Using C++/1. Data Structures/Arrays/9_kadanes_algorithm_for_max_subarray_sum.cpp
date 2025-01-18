#include <iostream>
#include <limits.h>

using namespace std;

int maxSubArraySum(int arr[], int n)
{
    int maxSum = INT_MIN, currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int arr[] = {3, -4, 5, 4, -1, 7, -8};

    cout << "Maximum Sub Array Sum = " << maxSubArraySum(arr, 7) << endl;

    return 0;
}