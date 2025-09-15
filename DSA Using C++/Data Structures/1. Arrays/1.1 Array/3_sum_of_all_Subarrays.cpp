#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\nSum of all subarrays are as follow: \n\n";
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            cout << curr << endl;
        }
    }

    return 0;
}