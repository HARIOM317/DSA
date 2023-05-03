#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cout << "Enter rows : ";
    cin >> m;
    cout << "Enter columns : ";
    cin >> n;

    int arr[m][n];

    cout << "Enter matrix elements : \n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // For only square matrix
    cout << "\nTranspose is: \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}