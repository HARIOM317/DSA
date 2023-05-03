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

using namespace std;

// function for finding that where rat can reach
bool isSafe(int** arr, int x, int y, int n){
    if (x<n && y<n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArray){
    // base condition
    if (x==n-1 && y==n-1){
        solArray[x][y] = 1;
        return true;
    }

    if(isSafe(arr, x, y, n)){
        solArray[x][y] = 1;
        // moving rat in right direction if possible
        if(ratInMaze(arr, x+1, y, n, solArray)){
            return true;
        }
        // moving rat in downward direction if possible
        if(ratInMaze(arr, x, y+1, n, solArray)){
            return true;
        }

        // backtracking
        solArray[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter size : ";
    cin>>n;

    // allocating memory dynamically for 2d array
    int** arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
    }
    
    cout<<"Insert array element either 0 or 1 : \n\n";
    // taking array elements
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>arr[i][j];
        }
    }

    // allocating memory dynamically for solution array
    int **solArray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        solArray[i] = new int[n];
        // set all element 0
        for(int j = 0; j < n; j++){
            solArray[i][j] = 0;
        }
    }

    cout<<"\nCorrect path is: \n\n";
    // print correct path
    if(ratInMaze(arr, 0, 0, n, solArray)){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solArray[i][j] <<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}