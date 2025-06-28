#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

bool find(vector<vector<int>> arr, int target)
{
    int rows = arr.size(), columns = arr[0].size();
    for (size_t i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (arr[i][j] == target)
                return true;
        }
    }
    return false;
}

vector<int> getRowSum(vector<vector<int>> arr)
{
    vector<int> rowSum;
    int rows = arr.size(), columns = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
        rowSum.push_back(sum);
    }
    return rowSum;
}

vector<int> getColumnSum(vector<vector<int>> arr)
{
    vector<int> rowSum;
    int rows = arr.size(), columns = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += arr[j][i];
        }
        rowSum.push_back(sum);
    }
    return rowSum;
}

int largestRow(vector<vector<int>> arr)
{
    vector<int> rowSum;
    int rows = arr.size(), columns = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += arr[i][j];
        }
        rowSum.push_back(sum);
    }

    int ans = 0, max = INT_MIN;
    for (int i = 0; i < rowSum.size(); i++)
    {
        if (max < rowSum[i])
        {
            ans = i;
            max = rowSum[i];
        }
    }

    return ans;
}

int largestColumn(vector<vector<int>> arr)
{
    vector<int> colSum;
    int rows = arr.size(), columns = arr[0].size();
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < columns; j++)
        {
            sum += arr[j][i];
        }
        colSum.push_back(sum);
    }

    int ans = 0, max = INT_MIN;
    for (int i = 0; i < colSum.size(); i++)
    {
        if (max < colSum[i])
        {
            ans = i;
            max = colSum[i];
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cout << "Enter rows an columns for 2D array: ";
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m)); // equivalent to arr[n][m]
    cout << "Enter Array Elements -" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Your 2D Array is -" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int target;
    cout << "Enter what you want to search: ";
    cin >> target;

    if (find(arr, target))
        cout << "Element is present" << endl;
    else
        cout << "Element is not present" << endl;

    vector<int> rowSum = getRowSum(arr);
    cout << "\nRow Sum: ";
    for (int i = 0; i < rowSum.size(); i++)
    {
        cout << rowSum[i] << " ";
    }

    vector<int> columnSum = getColumnSum(arr);
    cout << "\nColumn Sum: ";

    for (int i = 0; i < rowSum.size(); i++)
    {
        cout << columnSum[i] << " ";
    }

    cout << "\n\nLargest row: " << largestRow(arr) << endl;
    cout << "Largest column: " << largestColumn(arr) << endl;

    return 0;
}