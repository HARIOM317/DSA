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

void printBoard(vector<vector<string>> &ans, int n)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i + 1 << ")";
        for (int j = 0; j < n; j++)
        {
            cout << "\t";
            for (int k = 0; k < n; k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << "\n\n";
    }
}

bool isSafe(vector<string> board, int n, int row, int col)
{
    // check horizontally
    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // check vertically
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true; // safe place
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
            board[row][j] = 'Q'; // place queen
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
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    printBoard(ans, n);

    return 0;
}