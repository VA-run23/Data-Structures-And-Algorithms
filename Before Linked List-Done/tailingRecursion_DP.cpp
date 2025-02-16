//DONE
//TC: O(n)
#include <bits/stdc++.h>
using namespace std;
 
// Function to calculate the number of ways to tile a 2 x n grid
int tilingWays(int n, vector<int> &dp) {
    if (n == 0 || n == 1) {
        return n; // Base cases
    }
    if (dp[n] != -1) {
        return dp[n]; // Use memoized result if available
    }
    // Recursively calculate the number of ways
    dp[n-1] = tilingWays(n-1, dp);
    dp[n-2] = tilingWays(n-2, dp);
    return dp[n] = dp[n-1] + dp[n-2]; // Number of ways follows Fibonacci sequence
}

int main() {
    int n;
    cin >> n; // Read the number of columns in the grid
    vector<int> dp(n + 1, -1); // Initialize memoization vector with -1
    cout << tilingWays(n, dp) << endl; // Output the result
    return 0;
}


/*
Explanation:
The problem is to tile a 2 x n grid using 2 x 1 tiles. The number of ways to do this follows the Fibonacci sequence.
For a 2 x 4 grid, there are only 3 possible ways:
1) Placing all tiles horizontally.
2) Placing all tiles vertically.
3) Placing 2 tiles vertically and 2 tiles horizontally.

The time complexity of this solution is O(n) due to the memoization technique used in the tilingWays function.
*/
