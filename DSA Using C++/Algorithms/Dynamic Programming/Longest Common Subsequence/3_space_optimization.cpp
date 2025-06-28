#include <iostream>
#include <vector>

using namespace std;

int lcs(string &str1, string &str2)
{
    int n1 = str1.size(), n2 = str2.size();
    vector<int> curr(n2 + 1, 0);
    vector<int> next(n2 + 1, 0);

    for (int i = n1 - 1; i >= 0; i--)
    {
        for (int j = n2 - 1; j >= 0; j--)
        {
            int length = 0;

            if (str1[i] == str2[j])
            {
                length = 1 + next[j + 1];
            }
            else
            {
                length = max(next[j], curr[j + 1]);
            }

            curr[j] = length;
        }
        next = curr;
    }

    return curr[0];
}

int main()
{
    // Ans = 3 ("ace")
    string s1 = "abcde", s2 = "ace";
    cout << "Maximum Common Subsequence Length = " << lcs(s1, s2) << endl;

    return 0;
}