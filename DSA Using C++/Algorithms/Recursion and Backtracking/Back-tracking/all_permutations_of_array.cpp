#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>> &ans)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back({nums});
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, index + 1, ans); // recursive call for next index or position
        swap(nums[index], nums[i]);  // backtracking to pass the original array without changes
    }
}

vector<vector<int>> permutations(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, index, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permutations(nums);

    // printing all permutations
    cout << "All permutations are:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
            cout << (j >= ans[i].size() - 1 ? "" : ",");
        }
        cout << "}" << endl;
    }

    return 0;
}