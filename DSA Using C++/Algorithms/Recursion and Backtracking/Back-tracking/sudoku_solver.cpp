#include <iostream>

using namespace std;

void printSuduko(int arr[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        if (i % 3 == 0)
        {
            cout << "\n";
        }

        for (int j = 0; j < 9; j++)
        {
            if (j % 3 == 0)
            {
                cout << "\t";
            }

            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int suduko[9][9], int row, int col, int digit)
{
    // check horizontally
    for (int j = 0; j < 9; j++)
    {
        if (suduko[row][j] == digit)
        {
            return false;
        }
    }

    // check vertically
    for (int i = 0; i < 9; i++)
    {
        if (suduko[i][col] == digit)
        {
            return false;
        }
    }

    // check 3x3 grid
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i <= startRow + 2; i++)
    {
        for (int j = startCol; j <= startCol + 2; j++)
        {
            if (suduko[i][j] == digit)
            {
                return false;
            }
        }
    }

    return true; // valid place for digit
}

bool solveSuduko(int suduko[9][9], int row, int col)
{
    // base case
    if (row == 9)
    {
        printSuduko(suduko);
        return true;
    }

    int nextRow = row, nextCol = col + 1;
    if (col + 1 == 9)
    {
        nextRow = row + 1;
        nextCol = 0;
    }

    // if already digit placed
    if (suduko[row][col] != 0)
    {
        return solveSuduko(suduko, nextRow, nextCol);
    }

    // place digit
    for (int digit = 1; digit <= 9; digit++)
    {
        if (isValid(suduko, row, col, digit))
        {
            suduko[row][col] = digit;
            if (solveSuduko(suduko, nextRow, nextCol))
            {
                return true;
            }
            suduko[row][col] = 0; // backtrack
        }
    }

    return false; // no solution found
}

int main()
{
    int matrix[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 1, 0, 0, 8, 0},
                        {9, 0, 0, 8, 6, 3, 0, 0, 5},
                        {0, 5, 0, 0, 9, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    solveSuduko(matrix, 0, 0);

    return 0;
}