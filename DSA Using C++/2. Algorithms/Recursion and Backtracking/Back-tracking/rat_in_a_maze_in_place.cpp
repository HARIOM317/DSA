#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool issafe(int x, int y, vector<vector<int>> &mat, int n)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && mat[x][y] == 1)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> mat, int n, vector<string> &ans, int x, int y, string path)
{
    // base case: if reached at destination point
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    mat[x][y] = -1;

    // 4 choices: D, L, R, T

    // 1. Down
    int newX = x + 1, newY = y;
    if (issafe(newX, newY, mat, n))
    {
        path.push_back('D');
        solve(mat, n, ans, newX, newY, path);
        path.pop_back(); // backtracking
    }

    // 2. Left
    newX = x, newY = y - 1;
    if (issafe(newX, newY, mat, n))
    {
        path.push_back('L');
        solve(mat, n, ans, newX, newY, path);
        path.pop_back(); // backtracking
    }

    // 3. Right
    newX = x, newY = y + 1;
    if (issafe(newX, newY, mat, n))
    {
        path.push_back('R');
        solve(mat, n, ans, newX, newY, path);
        path.pop_back(); // backtracking
    }

    // 4. Up
    newX = x - 1, newY = y;
    if (issafe(newX, newY, mat, n))
    {
        path.push_back('U');
        solve(mat, n, ans, newX, newY, path);
        path.pop_back(); // backtracking
    }

    mat[x][y] = 1;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    int n = mat.size();

    vector<string> ans;
    if (mat[0][0] == 0 || mat[n - 1][n - 1] == 0)
        return ans;

    string path = "";
    solve(mat, n, ans, 0, 0, path);

    return ans;
}

int main()
{
    // driver code
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};

    vector<string> path = findPath(mat);

    cout << "The Possible Paths are: " << endl;

    for (auto possiblePath : path)
    {
        cout << possiblePath << endl;
    }

    return 0;
}