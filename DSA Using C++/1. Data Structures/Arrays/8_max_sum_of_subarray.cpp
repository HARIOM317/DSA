#include <iostream>

using namespace std;

int maxSumOfSubArray(int arr[], int n)
{
    int maxSum = 0;
    for (int i = 0; i < n; i++)
    {
        int currSum = 0;
        for (int j = i; j < n; j++)
        {
            currSum += arr[j];
            maxSum = max(maxSum, currSum);
        }
    }

    return maxSum;
}

int main()
{
    int arr[10] = {3, -4, 5, -3, 7, 3, 4, 6, -5, 8};

    cout << "Max Sum = " << maxSumOfSubArray(arr, 10) << endl;

    return 0;
}