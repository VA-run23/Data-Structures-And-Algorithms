
// The N-Queens problem  have solutions for every N ≥ 4.

/*
1. Start in the leftmost column.
2. Place a queen in the current column and move to the next column.
3. Check if placing the queen in the current row is safe. If it is:
   - Place the queen and move to the next column.
   - If placing the queen in the current row is not safe, move it to the next row within the same column and check again.
4. If all queens are placed safely, return true.
5. If placing a queen leads to a solution, recursively place queens in the remaining columns.
6. If placing a queen in a column does not lead to a solution, remove the queen (backtrack) and try the next row.
7. If all rows and columns have been tried and no solution is found, return false.
*/

/*
To compare the efficiency of O(n^n) and O(n^2 * 2^n):

O(n^n):
This represents exponential growth where the base is n and the exponent is also n. The complexity grows extremely fast, making it impractical for large n.

O(n^2 * 2^n):
This also represents exponential growth but with a smaller base of 2 and an additional polynomial factor of n^2. While it still grows quickly, the growth rate is less aggressive compared to O(n^n).

Comparison
- For small values of n: Both complexities are manageable, but O(n^2 * 2^n) will typically perform better.
- For large values of n: O(n^n) grows exponentially much faster and becomes infeasible much sooner compared to O(n^2 * 2^n).

 Conclusion
O(n^2 * 2^n) is more efficient than O(n^n) for both small and large values of n.
In practical terms, for large problems, even O(n^2 * 2^n) can be too slow, but it is significantly better than O(n^n).
*/
#include <bits/stdc++.h>
using namespace std;

// Function to check if placing a queen at (x, y) is safe
bool isSafe(vector<vector<int>> &arr, int x, int y, int n, vector<vector<vector<int>>> &dp) {
    // Check for queens in the same column
    for(int row = 0; row < x; row++) {
        if(arr[row][y])
            return false; // Returns false if a queen is already placed in the same column
    }
    // Check for queens in the principal diagonal
    int row = x;
    int col = y;
    while(row >= 0 && col >= 0) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col--;
    }
    // Check for queens in the reverse diagonal
    row = x;
    col = y;
    while(row >= 0 && col < n) {
        if(arr[row][col] == 1) {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

// Function to solve the N-Queens problem using DP and backtracking
bool nQueen(vector<vector<int>> &arr, int x, int n, vector<vector<vector<int>>> &dp) {
    // Base case: If all queens are placed
    if(x >= n) {
        return true; // Final solution found
    }
    /*
    dp[x] == arr:
    
    dp is a 3-dimensional vector used as the DP table to store results of subproblems.
    
    x is the current row index being processed.
    
    arr is the current state of the board (2D vector representing the positions of the queens).
    
    This condition checks if the current state arr matches the state stored in dp[x]. In other words, it verifies if we have already computed the result for this specific configuration of the board up to row x.
    */
    // Check if the result for this state is already computed
    if(dp[x] == arr) return dp[x][n][0];

    // For each column in the current row, try placing the queen
    for(int col = 0; col < n; col++) {
        if(isSafe(arr, x, col, n, dp)) { // Check if placing the queen is safe
            arr[x][col] = 1; // Place the queen
            if(nQueen(arr, x + 1, n, dp)) { // Recursively place queens in the next row
                dp[x] = arr; // Memoize the result
                /*
                return dp[x][n][0];:
                
                If the condition dp[x] == arr is true (i.e., the result for this state has already been computed), the function returns the precomputed result from the DP table.
                
                dp[x][n][0] holds the result for the state dp[x]. It indicates whether placing queens in the subsequent rows from the current configuration is feasible (true) or not (false).
                */
                return dp[x][n][0] = true;
            }
            arr[x][col] = 0; // Backtrack if placing the queen didn't lead to a solution
        }
    }
    dp[x] = arr; // Memoize the result
    return dp[x][n][0] = false; // Return false if no solution is found
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(1, -1))); // Initialize DP table

    if(nQueen(arr, 0, n, dp)) { // Passing starting array, starting row and size of the board (number of rows and columns) and dp table
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found" << endl;
    }
    return 0;
}

//INPUT
// 8

////output
// 1 0 0 0 0 0 0 0
// 0 0 0 0 1 0 0 0
// 0 0 0 0 0 0 0 1
// 0 0 0 0 0 1 0 0
// 0 0 1 0 0 0 0 0
// 0 0 0 0 0 0 1 0
// 0 1 0 0 0 0 0 0
// 0 0 0 1 0 0 0 0