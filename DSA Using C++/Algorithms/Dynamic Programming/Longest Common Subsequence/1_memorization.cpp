#include <iostream>
#include <vector>

using namespace std;

int getLCSLength(string &str1, string &str2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i == str1.size() || j == str2.size())
        return 0;

    // check memory
    if (dp[i][j] != -1)
        return dp[i][j];

    int length = 0;
    if (str1[i] == str2[j])
    {
        length = 1 + getLCSLength(str1, str2, i + 1, j + 1, dp);
    }
    else
    {
        length = max(getLCSLength(str1, str2, i + 1, j, dp), getLCSLength(str1, str2, i, j + 1, dp));
    }

    return dp[i][j] = length; // memorize and return ans
}

int lcs(string &str1, string str2)
{
    int n1 = str1.size(), n2 = str2.size();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return getLCSLength(str1, str2, 0, 0, dp);
}

int main()
{
    // Ans = 3 ("ace")
    string s1 = "abcde", s2 = "ace";
    cout << "Maximum Common Subsequence Length = " << lcs(s1, s2) << endl;

    return 0;
}