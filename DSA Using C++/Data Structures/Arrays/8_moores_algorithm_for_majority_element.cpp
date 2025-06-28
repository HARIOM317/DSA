#include <iostream>
#include <vector>

using namespace std;

// Works only if majority element is occurs more than nums.size()/2 times.
int majorityElement(vector<int> &nums)
{
    int freq = 0, ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq == 0)
            ans = nums[i];
        if (ans == nums[i])
            freq++;
        else
            freq--;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element = " << majorityElement(nums) << endl; // O(n) time

    return 0;
}