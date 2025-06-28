#include <iostream>
#include <vector>

using namespace std;

/* Problem - Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word :
    1. Insert a character
    2. Delete a character
    3. Replace a character
*/

int getMinDistance(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    // base cases (1. s1 < s2 and 2. s2 < s1)
    if (i == s1.length())
        return s2.length() - j;
    if (j == s2.length())
        return s1.length() - i;

    // check memory
    if (dp[i][j] != -1)
        return dp[i][j];

    int minOperations = 0;

    if (s1[i] == s2[j])
    {
        // check for next index values
        minOperations = getMinDistance(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        // case-1 : insert operation
        int insertOperation = 1 + getMinDistance(s1, s2, i, j + 1, dp);

        // case-2 : delete operation
        int deleteOperation = 1 + getMinDistance(s1, s2, i + 1, j, dp);

        // case-3 : replace operation
        int replaceOperation = 1 + getMinDistance(s1, s2, i + 1, j + 1, dp);

        minOperations = min(insertOperation, min(deleteOperation, replaceOperation));
    }

    return dp[i][j] = minOperations; // memorize and return ans
}

int minDistance(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return getMinDistance(s1, s2, 0, 0, dp);
}

int main()
{
    /*
    _____ Test Case - 1 _____
    Ans = 3
    horse -> rorse (replace 'h' with 'r')
    rorse -> rose (remove 'r')
    rose -> ros (remove 'e')
    */

    string s1 = "horse", s2 = "ros";
    cout << "1. Minimum operations to convert word1 to word2 = " << minDistance(s1, s2) << endl;

    /*
    _____ Test Case - 2 _____
    Ans = 5
    intention -> inention (remove 't')
    inention -> enention (replace 'i' with 'e')
    enention -> exention (replace 'n' with 'x')
    exention -> exection (replace 'n' with 'c')
    exection -> execution (insert 'u')
    */

    s1 = "intention", s2 = "execution";
    cout << "2. Minimum operations to convert word1 to word2 = " << minDistance(s1, s2) << endl;

    return 0;
}