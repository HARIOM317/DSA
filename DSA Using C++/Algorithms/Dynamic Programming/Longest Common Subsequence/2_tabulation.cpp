#include <iostream>
#include <vector>

using namespace std;

int lcs(string &str1, string &str2)
{
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)); // initialize table

    // fill the table
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int length = 0;

            if (str1[i] == str2[j])
            {
                length = 1 + dp[i + 1][j + 1];
            }
            else
            {
                length = max(dp[i + 1][j], dp[i][j + 1]);
            }

            // store ans
            dp[i][j] = length;
        }
    }

    return dp[0][0];
}

int main()
{
    // Ans = 3 ("ace")
    string s1 = "abcde", s2 = "ace";
    cout << "Maximum Common Subsequence Length = " << lcs(s1, s2) << endl;

    return 0;
}