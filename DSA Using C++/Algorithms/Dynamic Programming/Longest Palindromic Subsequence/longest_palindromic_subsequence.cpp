#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Optimized approach
int lps(string str)
{
    // Note : Ans is LCS of string str and its reverse
    string str2 = str;
    reverse(str2.begin(), str2.end()); // reverse str2

    int n = str.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)        {
            int length = 0;

            if (str[i] == str2[j])
            {
                length = 1 + next[j + 1];
            }
            else
            {
                length = max(next[j], curr[j + 1]);
            }

            // store length
            curr[j] = length;
        }
        next = curr;
    }

    return curr[0];
}

int main()
{
    // Ans = 7 ("bbababb")
    string str = "bbbabaabb";

    cout << "Longest Palindromic Subsequence Length = " << lps(str) << endl;

    return 0;
}