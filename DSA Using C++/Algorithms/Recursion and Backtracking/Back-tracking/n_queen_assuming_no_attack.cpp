#include <bits/stdc++.h>

using namespace std;

// To print the board
void printBoard(vector<vector<char>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        cout << "\t";
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    // cout << "\t_";
    // for (int i = 1; i < n; i++)
    // {
    //     cout << "__";
    // }
    // cout << endl;

    cout << "\n\n";
}

// Placing n-queens assuming no queen can attack each other
void nQueens(vector<vector<char>> &board, int row)
{
    int n = board.size();
    static int count = 1;

    // base case
    if (row == n)
    {
        cout << count++ << ")";
        printBoard(board);
        return;
    }

    for (int j = 0; j < n; j++)
    {
        board[row][j] = 'Q'; // place queen
        nQueens(board, row + 1);
        board[row][j] = '.'; // backtrack
    }
}

int main()
{
    int n = 3;
    vector<vector<char>> board(n, vector<char>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    }

    nQueens(board, 0);

    return 0;
}