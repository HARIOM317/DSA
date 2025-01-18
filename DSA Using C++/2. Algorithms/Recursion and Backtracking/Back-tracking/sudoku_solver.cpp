#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<char>> board, int row, int col, char dig)
{
    // check horizontally in row
    for (int j = 0; j < 9; j++)
    {
        if (board[row][j] == dig)
            return false;
    }

    // check vertically in column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == dig)
            return false;
    }

    // check grid
    // calculating starting row an col for the current grid
    int nrow = (row / 3) * 3;
    int ncol = (col / 3) * 3;

    for (int i = nrow; i <= nrow + 2; i++)
    {
        for (int j = ncol; j < ncol + 2; j++)
        {
            if (board[i][j] == dig)
                return false;
        }
    }

    return true;
}

bool sudokuSolver(vector<vector<char>> &board, int row, int col)
{
    // base case
    if (row == 9)
    {
        return true;
    }

    // calculating next row and next column
    int nextRow = row, nextCol = col + 1;
    if (nextCol == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // check for valid digit
    if (board[row][col] != '.')
    {
        return sudokuSolver(board, nextRow, nextCol);
    }

    // placing the right digit
    for (char dig = '1'; dig <= '9'; dig++)
    {
        if (isSafe(board, row, col, dig))
        {
            board[row][col] = dig; // placing the correct digit
            // if next digit placement is correct
            if (sudokuSolver(board, nextRow, nextCol))
            {
                return true;
            }
            board[row][col] = '.'; // backtracking for incorrect placement
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    sudokuSolver(board, 0, 0);
}

int main()
{
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    // printing solved sudoku
    cout << "Solved sudoku is\n";
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}