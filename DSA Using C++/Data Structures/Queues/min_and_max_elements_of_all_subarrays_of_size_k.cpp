#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<pair<int, int>> solve(vector<int> &arr, int n, int k)
{
    vector<pair<int, int>> ans;
    deque<int> maximum(k);
    deque<int> minimum(k);

    // process first window
    for (int i = 0; i < k; i++)
    {
        while (!maximum.empty() && arr[maximum.back()] <= arr[i])
            maximum.pop_back();

        while (!minimum.empty() && arr[minimum.back()] >= arr[i])
            minimum.pop_back();

        maximum.push_back(i);
        minimum.push_back(i);
    }
    ans.push_back({arr[maximum.front()], arr[minimum.front()]});

    // process remaining windows
    for (int i = k; i < n; i++)
    {
        // removal
        while (!maximum.empty() && i - maximum.front() >= k)
        {
            maximum.pop_front();
        }

        while (!minimum.empty() && i - minimum.front() >= k)
        {
            minimum.pop_front();
        }

        // addition
        while (!maximum.empty() && arr[maximum.back()] <= arr[i])
            maximum.pop_back();

        while (!minimum.empty() && arr[minimum.back()] >= arr[i])
            minimum.pop_back();

        maximum.push_back(i);
        minimum.push_back(i);

        ans.push_back({arr[maximum.front()], arr[minimum.front()]});
    }

    return ans;
}

int main()
{
    int k = 3;
    vector<int> arr = {2, 5, -1, 7, -3, -1, 2, 5, 7, 1};

    vector<pair<int, int>> ans = solve(arr, arr.size(), k);

    int i = 1;
    for (auto p : ans)
    {
        cout << "Window " << i++ << " : " << "{" << p.first << "," << p.second << "}" << endl;
    }

    return 0;
}