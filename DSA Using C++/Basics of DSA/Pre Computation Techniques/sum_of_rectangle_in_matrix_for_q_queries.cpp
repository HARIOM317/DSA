#include <iostream>
using namespace std;

/*
    Given a 2d array on N*N integers. Given Q queries and in each given query given a, b, c and d. Print sum of rectangle represented by (a,b) as top left point and (c,d) as bottom right point.

    Constraints:
    1 <= N <= 10^3
    1 <= A[i][j] <= 10^9
    1 <= Q <= 10^5
    1 <= a, b, c, d <= N
*/

/*
    Visualization of matrix:
    -----------------------
    Suppose matrix looks like this (rows i, cols j):

        0    1   2   3   4   5   j →
        ---------------------------
    0 | 0    0   0   0   0   0
    1 | 0   [1   2   3   4   5 ]
    2 | 0   [6   7   8   9   10]
    3 | 0   [11  12  13  14  15]
    4 | 0   [16  17  18  19  20]
    5 | 0   [21  22  23  24  25]
    i ↓
    ___________________________________________________

    Visualization of prefix:
    -----------------------
    Prefix arr will looks like this (rows i, cols j):

          0    1    2    3    4    5    j →
                    b         d
                    ↓         ↓
        ---------------------------
      0 | 0    0    0    0    0    0
      1 | 0   [1    3    6    10   15 ]
 a →  2 | 0   [7   |16   27   40 | 55 ]
      3 | 0   [18  |39   63   90 | 120]
      4 | 0   [34  |72   114  160| 210]
 c →  5 | 0   [55  |115  180  250| 325]
      i ↓

    Rectangle Sum Formula:
    ----------------------
    To get sum of submatrix (a,b) to (c,d):

    total = prefix[c][d]
            - prefix[a-1][d]   // remove area (above rectangle)
            - prefix[c][b-1]   // remove area (left of rectangle)
            + prefix[a-1][b-1] // add bacoverlap (subtracted twice)

    Here (a,b) is top-left and (c,d) ibottom-right of the rectangle.
    The formula ensures only this shaded region iincluded.
*/

const int N = 1e3 + 10;
int prefix[N][N]; // to store prefix sum of 2D matrix

int main()
{
    int n;
    cin >> n;

    int matrix[n + 1][n + 1] = {0}; // for 1-based indexing
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];

            // pre-conputing prefix sum
            prefix[i][j] = (matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1]);
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << (prefix[c][d] - prefix[a - 1][d] - prefix[c][b - 1] + prefix[a - 1][b - 1]) << endl;
    }

    return 0;
}