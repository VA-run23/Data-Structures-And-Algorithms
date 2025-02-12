//18.1
//Done
////rat in maze
/* 
Initial Setup: Allocate memory for the maze (arr) and solution (solArr) matrices.

Safety Check: Use isSafe() to check if the current position (x, y) is within bounds and not blocked.

Base Case: If the rat reaches the bottom-right corner (n-1, n-1), mark the cell as part of the solution and return true.

Move Down: If moving down (x+1, y) is safe, recursively call ratInMaze() for the new position.

Move Right: If moving right (x, y+1) is safe, recursively call ratInMaze() for the new position.

Backtracking: If neither move results in a solution, unmark the current cell and backtrack.

Output: If a solution is found, print the solution matrix solArr.
*/

//TC: O(2^(n^2))
#include <bits/stdc++.h>
using namespace std;

// Function to check if the current position is safe to move to
// bool isSafe(int ** arr, int x, int y, int n){
//     // Check if x and y are within the bounds of the maze and the cell is not blocked
//     if(x < n && y < n && arr[x][y] == 1){
//         return true; // The cell is safe to move to
//     }
//     return false; // The cell is not safe to move to
// }
bool isSafe(int** arr, int x, int y, int n) {
    return (x < n && y < n && arr[x][y] == 1); // Check if x and y are within bounds and the cell is not blocked
}


// Function to solve the maze problem using backtracking
bool ratInMaze(int** arr, int x, int y, int n, int** solArr){
    // Base case: If the rat reaches the bottom-right corner of the maze
    if(x == n-1 && y == n-1){
        solArr[x][y] = 1; // Mark the cell as part of the solution path
        return true; // Solution found
    }
// Check if the current position is safe to move to
if (isSafe(arr, x, y, n)) {
    solArr[x][y] = 1; // Mark the cell as part of the solution path

    // Try moving DOWN (increasing x)
    if (ratInMaze(arr, x + 1, y, n, solArr)) {
        return true; // Solution found by moving DOWN
    }

    // If moving DOWN doesn't give a solution, try moving RIGHT (increasing y)
    if (ratInMaze(arr, x, y + 1, n, solArr)) {
        return true; // Solution found by moving RIGHT
    }

    solArr[x][y] = 0; // Backtracking: Unmark the cell if it's not part of the solution
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

    int** solArr = new int*[n]; // Step 1: Allocate memory for an array of 'n' pointers to int, each representing a row of the matrix
    // Loop through each row
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n]; // Step 2: Allocate memory for 'n' integers for each row, resulting in a 2D array
        for (int j = 0; j < n; j++) {
            solArr[i][j] = 0; // Step 3: Initialize each element in the matrix to 0, indicating no path
        }
    }


// // Visual Representation:
// // Suppose n = 3 for simplicity:

// // Array of Pointers:
// int** solArr = new int*[n]; // Creates an array of 'n' pointers to int
// // After this line, solArr looks like this (addresses are hypothetical):
// // solArr:  [ptr1] [ptr2] [ptr3]
// //           |      |      |

// // Allocating Rows:
// for (int i = 0; i < n; i++) {
//     solArr[i] = new int[n]; // Allocates memory for 'n' integers for each row
//     // After this loop, each solArr[i] points to the beginning of a dynamically allocated array of n integers, forming rows in the 2D array:
//     // solArr:  [ptr1]  [ptr2]  [ptr3]
//     //           |       |       |
//     //           V       V       V
//     //         [0][1][2] [0][1][2] [0][1][2]
// }

// // Explanation:
// // With int** solArr = new int*[n];, you allocate an array of n pointers to integers.
// // Each of these pointers will represent a row in the 2D array.

// // Then, for each row, solArr[i] = new int[n]; allocates an array of n integers.
// // Each solArr[i] is a pointer to the beginning of a dynamically allocated array of n integers,
// // forming a row in the 2D array.


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
//5
// 1 0 1 0 1 
// 1 1 1 1 1 
// 0 1 0 1 0 
// 1 0 0 1 1 
// 1 1 1 0 1 


//5
// 1 1 1 1 1 
// 0 0 0 0 1 
// 0 0 0 0 1 
// 0 0 0 0 1 
// 0 0 0 0 1 

////No answer is returned if there is no path
// 5
// 0 0 0 0 1 
// 1 0 1 0 1 
// 1 1 1 1 1 
// 0 1 0 0 0 
// 0 0 1 0 1 


//This code does not handle this case of input even though it has answer
// 5 
// 1 0 1 1 1
// 1 0 1 0 1
// 1 0 1 0 1
// 1 0 1 0 1
// 1 1 1 0 1


