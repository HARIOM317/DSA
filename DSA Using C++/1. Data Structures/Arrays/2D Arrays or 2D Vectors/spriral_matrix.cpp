#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> spiralMatrix;
    int rows = matrix.size();
    if (rows == 0)
        return spiralMatrix; // Handle empty matrix
    int columns = matrix[0].size();

    int count = 0;
    int totalElements = rows * columns;

    // index pointers
    int startingRow = 0;
    int endingRow = rows - 1;
    int startingColumn = 0;
    int endingColumn = columns - 1;

    while (count < totalElements)
    {
        // starting row
        for (int index = startingColumn; index <= endingColumn && count < totalElements; index++)
        {
            spiralMatrix.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        // ending column
        for (int index = startingRow; index <= endingRow && count < totalElements; index++)
        {
            spiralMatrix.push_back(matrix[index][endingColumn]);
            count++;
        }
        endingColumn--;

        // ending row
        for (int index = endingColumn; index >= startingColumn && count < totalElements; index--)
        {
            spiralMatrix.push_back(matrix[endingRow][index]);
            count++;
        }
        endingRow--;

        // starting column
        for (int index = endingRow; index >= startingRow && count < totalElements; index--)
        {
            spiralMatrix.push_back(matrix[index][startingColumn]);
            count++;
        }
        startingColumn++;
    }

    return spiralMatrix;
}

int main()
{
    int rows, columns;
    cout << "Enter rows and columns: ";
    cin >> rows >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    cout << "Enter vector element: ";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = spiralOrder(matrix);
    cout << "\nSpiral matrix is: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}