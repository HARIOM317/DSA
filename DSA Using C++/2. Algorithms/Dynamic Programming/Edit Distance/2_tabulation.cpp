#include <iostream>
#include <vector>

using namespace std;

/* Problem - Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word :
    1. Insert a character
    2. Delete a character
    3. Replace a character
*/

int minDistance(string s1, string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    // base case 1 : if string s1 is smaller than string s2
    for (int j = 0; j < n2; j++)
    {
        dp[n1][j] = n2 - j;
    }

    // base case 2 : if string s2 is smaller than string s1
    for (int i = 0; i < n1; i++)
    {
        dp[i][n2] = n1 - i;
    }

    // fill the table
    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int minOperations = 0;

            if (s1[i] == s2[j])
            {
                // check for next index values
                minOperations = dp[i + 1][j + 1];
            }
            else
            {
                // case-1 : insert operation
                int insertOperation = 1 + dp[i][j + 1];

                // case-2 : delete operation
                int deleteOperation = 1 + dp[i + 1][j];

                // case-3 : replace operation
                int replaceOperation = 1 + dp[i + 1][j + 1];

                minOperations = min(insertOperation, min(deleteOperation, replaceOperation));
            }

            // store ans
            dp[i][j] = minOperations;
        }
    }

    return dp[0][0];
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