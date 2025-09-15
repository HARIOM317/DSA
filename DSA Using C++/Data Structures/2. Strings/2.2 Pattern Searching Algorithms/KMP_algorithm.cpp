#include <iostream>
#include <vector>

using namespace std;

/*
    Longest Prefix Suffix:

        Given a string s, of lowercase english alphabets, find the length of the longest proper prefix which is also a suffix.

        Note: Prefix and suffix can be overlapping but they should not be equal to the entire string.
*/

// KMP Algorithm
int getLPSLength(string &s)
{
    int n = s.length();
    vector<int> lps(n, 0);
    int pre = 0, suff = 1;

    while (suff < n)
    {
        if (s[pre] == s[suff])
        {
            lps[suff] = pre + 1;
            pre++;
            suff++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suff] = 0;
                suff++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }

    string ans = s.substr(0, lps[n - 1]);
    cout << "LPS = " << ans << "\n";

    return lps[n - 1];
}

int main()
{
    string s1 = "ddbbbbcddd";
    string s2 = "aabaacaadaabaaba";
    string s3 = "abcabdabcabdabdab";

    cout << "Length: " << getLPSLength(s1) << "\n\n";
    cout << "Length: " << getLPSLength(s2) << "\n\n";
    cout << "Length: " << getLPSLength(s3) << "\n\n";

    return 0;
}