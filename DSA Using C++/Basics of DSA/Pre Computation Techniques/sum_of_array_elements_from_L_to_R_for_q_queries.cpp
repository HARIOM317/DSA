#include <iostream>

using namespace std;

/*
    Given array A of N intergers (1 based indexing). Given Q queries and in each query given L and R. Print sum of array elements from index L to R(L, R included)

    Constraints:
    1 <= N <= 10^5
    a <= A[i] <= 10^9
    1 <= Q <= 10^5
    1 <= L, R <= N
*/

const int N = 1e5 + 1;
long long prefix[N];

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        // pre-computing prefix sum
        prefix[i + 1] = prefix[i] + arr[i];
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        cout << (prefix[r] - prefix[l - 1]) << endl;
    }

    return 0;
}