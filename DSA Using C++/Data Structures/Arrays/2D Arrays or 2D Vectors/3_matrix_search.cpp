#include <bits/stdc++.h>

using namespace std;

/*
Question -
Given a nxm matrix.
Write an algorithm to find that given value exist in the matrix or not.
Integers in each row are sorted in ascending from left to right.
Integer in column are sorted in ascending from top to bottom.
Example : 1 4 7 11
          2 5 8 12
          3 6 9 16
          10 13 14 17
*/

int main()
{
    int n, m;
    cout << "Enter order of matrix : ";
    cin >> n >> m;

    int matrix[n][m];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target element : ";
    cin >> target;

    int r = 0, c = m - 1;
    bool found = false;

    while (r < n and c >= 0)
    {
        if (matrix[r][c] == target)
        {
            found = true;
        }
        if (matrix[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (found)
    {
        cout << "Element " << target << " is present in given matrix." << endl;
    }
    else
    {
        cout << "Element " << target << " is not present in given matrix." << endl;
    }

    return 0;
}