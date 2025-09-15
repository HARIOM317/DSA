#include <iostream>
using namespace std;

/*
    Fot t testcases, Given a string S of lowercase english alphabet of length N and two intergers L and R. Check wether all the letter of the substring from index L to R (inclusive) can be rearranged to form a palindrome or not. Do this for q queries.

    Constraints:
    1 <= t <= 10
    1 <= N, Q <= 100000
    1 <= L <= R <= N
    'a' <= S[i] <= 'z' for 1 <= i <= N
*/

const int N = 1e5 + 10;
int hashing[N][26]; // construct arr of size N for each character to store char count on index i

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // reset hashing arr
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                hashing[i][j] = 0;
            }
        }

        string S;
        cin >> S;

        // pre-constructing the count of each char on a particular index
        for (int i = 0; i < S.length(); i++)
        {
            hashing[i + 1][S[i] - 'a']++;
        }

        // construct its prefix sum each char
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= S.length(); j++)
            {
                hashing[j][i] += hashing[j - 1][i];
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int oddCount = 0;
            for (int i = 0; i < 26; i++)
            {
                int charCount = hashing[r][i] - hashing[l - 1][i];
                if (charCount % 2 != 0)
                    oddCount++;
            }

            cout << (oddCount > 1 ? "NO" : "YES") << endl;
        }
    }

    return 0;
}