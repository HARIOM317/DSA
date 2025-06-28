#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static bool compareEnvelopes(pair<int, int> &a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int maxEnvelopes(vector<pair<int, int>> &envelopes)
{
    // step-1 : sort with custom comparator
    sort(envelopes.begin(), envelopes.end(), compareEnvelopes);

    // step-2 : find max length of LIS using binary search and dp
    int n = envelopes.size();
    vector<int> ans;
    ans.push_back(envelopes[0].second);

    for (int i = 1; i < n; i++)
    {
        int height = envelopes[i].second;

        if (height > ans.back())
        {
            ans.push_back(height);
        }
        else
        {
            // find index of just greater element
            int index = lower_bound(ans.begin(), ans.end(), height) - ans.begin();
            ans[index] = height;
        }
    }

    return ans.size();
}

int main()
{
    // Each envelope is represented as {width, height}
    vector<pair<int, int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << "Maximum number of envelopes: " << maxEnvelopes(envelopes) << endl;

    return 0;
}