#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> arr)
{
    int maxCount = 0, ans;
    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        if (maxCount == count)
        {
            ans = arr[i];
        }
    }
    return ans;
}

int majorityElementOptimized(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int freq = 1, maxFreq = 1, ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
        {
            freq++;
            maxFreq = max(maxFreq, freq);
        }
        else
        {
            freq = 1;
        }

        if (maxFreq == freq)
        {
            ans = arr[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2, 2, 3, 3, 2, 1, 3, 1, 3, 3};
    cout << "Majority Element = " << majorityElement(arr) << endl;          // O(n^2) time
    cout << "Majority Element = " << majorityElementOptimized(arr) << endl; // O(nlog(n)) time

    return 0;
}