#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int> &arr, int n, int c, int minimumAllowedDistance)
{
    int cows = 1, lastStaffPos = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastStaffPos >= minimumAllowedDistance)
        {
            cows++;
            lastStaffPos = arr[i];
        }

        if (cows == c)
            return true;
    }
    return false;
}

int largeMinDistance(vector<int> &arr, int c)
{
    // sorting the array
    sort(arr.begin(), arr.end());

    // finding maximum an minimum
    int n = arr.size();
    int min = arr[0], max = arr[n - 1];

    // performing binary search to find minimum possible largest distance between two cows
    int start = 1, end = max - min, ans = -1; // minimum possible dist = 1 and maximum possible dist = max(arr) - min(arr)
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(arr, n, c, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, c;
    cin >> n >> c;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << largeMinDistance(arr, c) << endl;

    return 0;
}