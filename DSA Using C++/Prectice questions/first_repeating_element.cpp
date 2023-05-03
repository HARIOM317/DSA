#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];

    cout << "Enter array elements : \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e5 + 2;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    int minIndex = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minIndex = min(minIndex, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }

    if (minIndex == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minIndex + 1 << endl;
    }

    return 0;
}