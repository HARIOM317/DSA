#include <iostream>
using namespace std;

/*
    Constraints:
    1 <= t <= 10^5
    1 <= n <= 10^5

    Time Limit: 1s
    Return modulo: 1e9+7
*/

const int M = 1e9 + 7;
const int N = 1e5 + 10; // larger than max size
long long fact[N];      // for pre-computation

// Overall: O(n+t) = O(n) (t <= n)
int main()
{
    int t;
    cin >> t;

    // precomputing ans for all possible inputs
    fact[0] = fact[1] = 1;
    // O(n)
    for (int i = 2; i <= N; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }

    // O(t)
    while (t--)
    {
        int n;
        cin >> n;
        cout << fact[n] << endl;
    }

    return 0;
}