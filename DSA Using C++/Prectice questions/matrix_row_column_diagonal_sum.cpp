#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

pair<int, int> linearSearch(vector<vector<int>> arr, int target)
{
    pair<int, int> ans = {-1, -1};
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == target)
            {
                ans.first = i;
                ans.second = j;
                return ans;
            }
        }
    }
    return ans;
}

pair<int, int> maxRowSum(vector<vector<int>> arr)
{
    pair<int, int> ans;
    int sum = INT_MIN, rowIndex = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        int rowSum = 0;
        for (int j = 0; j < arr[0].size(); j++)
        {
            rowSum += arr[i][j];
        }
        if (sum < rowSum)
        {
            sum = rowSum;
            rowIndex = i;
        }
    }

    ans.first = sum;
    ans.second = rowIndex;

    return ans;
}

pair<int, int> diagonalSum(vector<vector<int>> arr)
{
    pair<int, int> sum = {-1, -1};
    // check if matrix is square or not?
    if (arr.empty() || arr.size() != arr[0].size())
        return sum;

    int PrimaryDiagonalSum = 0, secondaryDiagonalSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (i == j)
            {
                PrimaryDiagonalSum += arr[i][j];
            }
            if ((i + j) == arr.size() - 1)
            {
                secondaryDiagonalSum += arr[i][j];
            }
        }
    }
    sum.first = PrimaryDiagonalSum;
    sum.second = secondaryDiagonalSum;

    return sum;
}

pair<int, int> maxColumnSum(vector<vector<int>> arr)
{
    pair<int, int> ans;
    int sum = INT_MIN, colIndex = -1;
    for (int i = 0; i < arr[0].size(); i++)
    {
        int colSum = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            colSum += arr[j][i];
        }
        if (sum < colSum)
        {
            sum = colSum;
            colIndex = i;
        }
    }

    ans.first = sum;
    ans.second = colIndex;

    return ans;
}

int optimizedCompleteDiagonalSum(vector<vector<int>> arr)
{
    // condition for valid square matrix
    if (arr.empty() || arr.size() != arr[0].size())
        return -1;

    int sum = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i][i];
        if (i != n - i - 1) // condition to avoid comman element
        {
            sum += arr[i][n - i - 1];
        }
    }
    return sum;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 1, 1},
        {2, 3, 4, 5},
        {3, 7, 5, 3},
        {4, 4, 4, 4}};

    int target = 11;
    pair<int, int> ans = linearSearch(arr, target);
    cout << "Target found at index: (" << ans.first << "," << ans.second << ")" << endl;

    cout << "Max row sum is " << maxRowSum(arr).first << " at row " << maxRowSum(arr).second << endl;
    cout << "Max column sum is " << maxColumnSum(arr).first << " at column " << maxColumnSum(arr).second << endl;
    cout << "Primary diagonal Sum = " << diagonalSum(arr).first << " and Secondary diagonal sum = " << diagonalSum(arr).second << endl;

    cout << "Complete matrix diagonal sum = " << optimizedCompleteDiagonalSum(arr) << endl;

    return 0;
}