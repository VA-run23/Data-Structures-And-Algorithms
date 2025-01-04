//Done
////rat in maze
//TC : (O(2{n2}))
#include <bits/stdc++.h>
using namespace std;

// Function to check if the current position is safe to move to
bool isSafe(int ** arr, int x, int y, int n){
    // Check if x and y are within the bounds of the maze and the cell is not blocked
    if(x < n && y < n && arr[x][y] == 1){
        return true; // The cell is safe to move to
    }
    return false; // The cell is not safe to move to
}

// Function to solve the maze problem using backtracking
bool ratInMaze(int** arr, int x, int y, int n, int** solArr){
    // Base case: If the rat reaches the bottom-right corner of the maze
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1; // Mark the cell as part of the solution path
        return true; // Solution found
    }

    // Check if the current position is safe to move to
    if(isSafe(arr, x, y, n)){
        solArr[x][y] = 1; // Mark the cell as part of the solution path

        // Move forward in the x direction
        if(ratInMaze(arr, x+1, y, n, solArr)){
            return true; // Solution found by moving right
        }

        // If moving in the x direction doesn't give a solution, move down in the y direction
        if(ratInMaze(arr, x, y+1, n, solArr)){
            return true; // Solution found by moving down
        }

        solArr[x][y] = 0;//backtracking
        return false; // No solution found from this cell
    }
    return false; // The cell is not safe to move to
}

int main(){
    int n; 
    cin>>n;
    int** arr=new int*[n];//This line allocates memory for n pointers to int. Each pointer will eventually point to a row of the 2D array.
    ////Thus arr holds the address of another array , which forms the row
    for(int i=0; i<n;i++){
        arr[i]=new int[n];//arr[i] is a pointer to the beginning of the i-th row, which is an array of n integers.
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    int** solArr= new int*[n];//creating solution matrix with each element in the matrix initializing to 0
    for(int i=0; i<n;i++){
        solArr[i]=new int[n];
        for(int j=0; j<n; j++)
            solArr[i][j]=0;
    }

    if(ratInMaze(arr,0,0,n,solArr)){//passing the (matrix, starting point of 2-d matrix, size of the matrix, solution array)
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

////input
// 1 0 1 0 1 
// 1 1 1 1 1 
// 0 1 0 1 0 
// 1 0 0 1 1 
// 1 1 1 0 1 



// 1 1 1 1 1 
// 0 0 0 0 1 
// 0 0 0 0 1 
// 0 0 0 0 1 
// 0 0 0 0 1 

////No answer is returned if there is no path
// 0 0 0 0 1 
// 1 0 1 0 1 
// 1 1 1 1 1 
// 0 1 0 0 0 
// 0 0 1 0 1 
