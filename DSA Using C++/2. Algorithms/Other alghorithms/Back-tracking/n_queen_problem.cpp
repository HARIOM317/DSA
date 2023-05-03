#include <iostream>

using namespace std;

/*
problem: for NxN chess board place N queens i.e. no queen can kill each other.

ex - 
input : N = 4

Output:
0   1   0   0
0   0   0   1
1   0   0   0
0   0   1   0

Note : 1 denotes position of queen in 4x4 chess board.
*/

bool isSafe(int** arr, int x, int y, int n){
    // for row/column
    for (int row = 0; row < x; row++)
    {
        if(arr[row][y]==1){
            return false;
        }
    }

    // for left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }

    // for right diagonal
    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1){
            return false;
        }
        row--;
        col++;
    }
    
    return true;
}

bool nQueen(int** arr, int x, int n){
    // base case if all queens are safe
    if (x >= n){
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        // check if queen is safe
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;

            // check for next row by recursion
            if (nQueen(arr, x + 1, n))
            {
                return true;
            }

            // backtracking
            arr[x][col] = 0;
        }
    }
    
    return false;
}

int main(){
    int n;
    cout<<"For NxN size chess board enter size of N Queen : ";
    cin>>n;

    // creating 2d array of size n dynamically
    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            // set all elements 0 of 2d array
            arr[i][j] = 0;
        }
    }
    
    cout<<"\nAll queens can be placed on following position i.e. all queens will be safe: \n\n";
    // calling function
    if (nQueen(arr, 0, n))
    {
        // printing array
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<"  ";
            }
            cout << endl;
        }
    }
    
    return 0;
}