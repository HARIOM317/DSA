#include <iostream>

using namespace std;

/*
    Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

    A binary string is that string which contains only 0 and 1.

    Example:
    Input: N = 3
    Output: 000 , 001 , 010 , 100 , 101

    Explanation:
    None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively.
*/

void binaryStrings(int n, int lastDigit, string ans)
{
    // base case
    if (n == 0)
    {
        cout << ans << " ";
        return;
    }

    if (lastDigit != 1)
    {
        // 2-choices
        binaryStrings(n - 1, 0, ans + '0');
        binaryStrings(n - 1, 1, ans + '1');
    }
    else
    {
        // 1-choice
        binaryStrings(n - 1, 0, ans + '0');
    }
}

int main()
{
    int n = 3;
    string ans = "";

    binaryStrings(n, 0, ans);

    return 0;
}