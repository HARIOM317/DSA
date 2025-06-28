#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generateSubsequences(vector<int> &nums, int n, vector<int> subset, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= n)
    {
        ans.push_back(subset);
        return;
    }

    // include
    subset.push_back(nums[index]);
    generateSubsequences(nums, n, subset, ans, index + 1);

    // exclude
    subset.pop_back();
    generateSubsequences(nums, n, subset, ans, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int n = arr.size();

    vector<vector<int>> ans;
    vector<int> subset;

    generateSubsequences(arr, n, subset, ans, 0);

    for (auto &sub : ans)
    {
        cout << "{ ";
        for (int num : sub)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
