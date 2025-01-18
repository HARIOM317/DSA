#include <iostream>
#include <vector>

using namespace std;

void getAllSubsets(vector<int> arr, int n, vector<vector<int>> &ans, vector<int> subset, int index)
{
    // base case
    if (index >= n)
    {
        ans.push_back(subset);
        return;
    }

    // include
    subset.push_back(arr[index]);
    getAllSubsets(arr, n, ans, subset, index + 1);

    // exclude
    subset.pop_back(); // backtracking - to remove last element
    getAllSubsets(arr, n, ans, subset, index + 1);
}

vector<vector<int>> subsets(vector<int> arr, int n)
{
    vector<vector<int>> ans;
    vector<int> subset;
    int index = 0;
    getAllSubsets(arr, n, ans, subset, index);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();
    vector<vector<int>> ans = subsets(arr, n);

    // printing all subsets
    cout << "All subsets are: \n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            cout << (j == ans[i].size() - 1 ? "" : ",");
        }
        cout << "}" << endl;
    }

    return 0;
}