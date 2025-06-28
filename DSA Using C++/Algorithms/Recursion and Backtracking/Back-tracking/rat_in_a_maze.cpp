/*
Backtracking :
               Backtracking is an algorithm-technique for solving recursive problems by trying to build every possible solution incrementally and removing those solutions that fail to satisfy the constraints of the problem at any point of time.
*/

/* Problem on backtracking -
rat in a maze (Note: rat can move only right direction or downward direction to leave the maze).
If solution were not found by rat to leave the maze then the rat can backtrack on that's privies point to choose the correct path (In backtracking rat can move in top and left direction).

input = {1,0,1,0,1}
        {1,1,1,1,1}
        {0,1,0,1,0}
        {1,0,0,1,1}
        {1,1,1,0,1}
1 - block where rat can reach
0 - block where rat can't reach

output = {1,0,0,0,0}
         {1,1,1,1,0}
         {0,0,0,1,0}
         {0,0,0,1,1}
         {0,0,0,0,1}
1 denotes the path which will follow the rat to relies from maze.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool issafe(int x, int y, vector<vector<int>> mat, int n, vector<vector<int>> visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && mat[x][y] == 1 && visited[x][y] == 0)
    {
        return true;
    }
    return false;
}

void solve(vector<vector<int>> mat, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path)
{
    // base case: if reached at destination point
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // 4 choices: D, L, R, T

    // 1. Down
    int newX = x + 1, newY = y;
    if (issafe(newX, newY, mat, n, visited))
    {
        path.push_back('D');
        solve(mat, n, ans, newX, newY, visited, path);
        path.pop_back(); // backtracking
    }

    // 2. Left
    newX = x, newY = y - 1;
    if (issafe(newX, newY, mat, n, visited))
    {
        path.push_back('L');
        solve(mat, n, ans, newX, newY, visited, path);
        path.pop_back(); // backtracking
    }

    // 3. Right
    newX = x, newY = y + 1;
    if (issafe(newX, newY, mat, n, visited))
    {
        path.push_back('R');
        solve(mat, n, ans, newX, newY, visited, path);
        path.pop_back(); // backtracking
    }

    // 4. Up
    newX = x - 1, newY = y;
    if (issafe(newX, newY, mat, n, visited))
    {
        path.push_back('U');
        solve(mat, n, ans, newX, newY, visited, path);
        path.pop_back(); // backtracking
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    if (mat[0][0] == 0)
        return ans;

    int n = mat.size();
    int srcX = 0, srcY = 0;

    // creating a NxN size visited matrix and initializing with 0
    vector<vector<int>> visited(n, vector<int>(n, 0));

    string path = "";
    solve(mat, n, ans, srcX, srcY, visited, path);

    // sorting ans in lexicographical order
    sort(ans.begin(), ans.end());

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