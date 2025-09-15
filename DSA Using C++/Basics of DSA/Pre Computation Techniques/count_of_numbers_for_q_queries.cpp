#include <iostream>
using namespace std;

/*
    Given array a of N intergers. Given Q queries and in each query given a number x, print count of that number in arry.

    Constraints:
    1 <= N <= 10^5
    1 <= Q <= 10^5
    1 <= a[i] <= 10^7
*/

// NOTE: use unordered_map for -ve and large values of arr[n] i.e. -10^12, 10^12 etc.
const int N = 1e7 + 1; // max possible value of arr[i]
int count[N];          // global array is by default initialized with 0

int main()
{
    // Taking input
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        // pre-computing count for each possible n
        count[arr[i]]++;
    }

    // Processing queries
    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        cout << count[x] << endl;
    }

    return 0;
}