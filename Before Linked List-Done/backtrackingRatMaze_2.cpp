//18.1
//MOdified by me to  handle other case
#include <bits/stdc++.h>
using namespace std;

// Function to check if the current position is safe to move to
bool isSafe(int** arr, int x, int y, int n, int** solArr) {
    // Check if x and y are within the bounds of the maze and the cell is not blocked and not already visited
    if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && solArr[x][y] == 0) {
        return true; // The cell is safe to move to
    }
    return false; // The cell is not safe to move to
}

// Function to solve the maze problem using backtracking
bool ratInMaze(int** arr, int x, int y, int n, int** solArr) {
    // Base case: If the rat reaches the bottom-right corner of the maze
    if (x == n - 1 && y == n - 1) {
        solArr[x][y] = 1; // Mark the cell as part of the solution path
        return true; // Solution found
    }

    // Check if the current position is safe to move to
    if (isSafe(arr, x, y, n, solArr)) {
        solArr[x][y] = 1; // Mark the cell as part of the solution path

        // Try moving DOWN (increasing x)
        if (ratInMaze(arr, x + 1, y, n, solArr)) {
            return true; // Solution found by moving DOWN
        }

        // Try moving RIGHT (increasing y)
        if (ratInMaze(arr, x, y + 1, n, solArr)) {
            return true; // Solution found by moving RIGHT
        }

        // Try moving UP (decreasing x)
        if (ratInMaze(arr, x - 1, y, n, solArr)) {
            return true; // Solution found by moving UP
        }

        // Try moving LEFT (decreasing y)
        if (ratInMaze(arr, x, y - 1, n, solArr)) {
            return true; // Solution found by moving LEFT
        }

        solArr[x][y] = 0; // Backtracking: Unmark the cell if it's not part of the solution
        return false; // No solution found from this cell
    }
    return false; // The cell is not safe to move to
}

int main() {
    int n;
    cin >> n;
    int** arr = new int*[n]; // Allocate memory for the maze matrix
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n]; // Allocate memory for each row
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j]; // Input the maze matrix
        }
    }

    int** solArr = new int*[n]; // Allocate memory for the solution matrix
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n]; // Allocate memory for each row
        for (int j = 0; j < n; j++) {
            solArr[i][j] = 0; // Initialize the solution matrix with 0
        }
    }

    if (ratInMaze(arr, 0, 0, n, solArr)) { // Call the function with the starting position and matrix size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solArr[i][j] << " "; // Output the solution matrix
            }
            cout << endl;
        }
    } else {
        cout << "No path found" << endl; // Output if no path is found
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i];
        delete[] solArr[i];
    }
    delete[] arr;
    delete[] solArr;

    return 0;
}

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

// //Input
// 5 
// 1 0 1 1 1
// 1 0 1 0 1
// 1 0 1 0 1
// 1 0 1 0 1
// 1 1 1 0 1

// //Output
// 1 0 1 1 1 
// 1 0 1 0 1 
// 1 0 1 0 1 
// 1 0 1 0 1 
// 1 1 1 0 1 


