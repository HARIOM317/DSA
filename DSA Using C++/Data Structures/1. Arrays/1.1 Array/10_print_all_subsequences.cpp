#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void generateSubsequences(const vector<int> &arr)
{
    int n = arr.size();
    int totalSubsequences = pow(2, n); // 2^n total subsequences

    // Iterate over all possible combinations
    for (int i = 0; i < totalSubsequences; i++)
    {
        vector<int> subsequence;
        for (int j = 0; j < n; ++j)
        {
            // Check if the j-th bit in i is set
            if (i & (1 << j))
            {
                subsequence.push_back(arr[j]);
            }
        }

        // Print the current subsequence
        cout << "{ ";
        for (int num : subsequence)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    generateSubsequences(arr);
    return 0;
}
