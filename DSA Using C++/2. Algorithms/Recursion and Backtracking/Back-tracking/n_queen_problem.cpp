/*
problem: for NxN chess board place N queens i.e. no queen can kill each other.

ex -
input : N = 4

Output:
_   Q   _   _
_   _   _   Q
Q   _   _   _
_   _   Q   _

Note : Q denotes position of queen in 4x4 chess board.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSafe(vector<string> board, int n, int row, int col)
{
    // check horizontally
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // check vertically
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<string> &board, int n, vector<vector<string>> &ans, int row)
{
    // base case
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(board, n, row, j))
        {
            board[row][j] = 'Q';
            nQueens(board, n, ans, row + 1);
            board[row][j] = '_'; // backtracking
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> board(n, string(n, '_'));
    vector<vector<string>> ans;
    int row = 0;
    nQueens(board, n, ans, row);
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);

    for (int i = 0; i < n; i++)
    {
        if (i < ans.size())
        {
            cout << i + 1 << "th way:" << endl;
        }
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl
             << endl;
    }

    return 0;
}