//DONE
//Successfully implemented DP to this program and optimised the program

 /* Time Complexity for DP Version:
       countPathMaze: The time complexity is O(n^2) since you are filling an n x n DP table. Each cell in the table is computed once.
       
       countPathMazeDia: Similar to the above function, the time complexity is O(n^2) because you are filling an n x n DP table with each cell being computed once.
*/

#include <bits/stdc++.h>
using namespace std; 
const int MOD = 1e5 + 7;
int countPathMaze(int n , int i, int j, vector<vector<int>> &dp) { // Pass dp by reference
    if(i == n-1 && j == n-1) {
        return 1;
    }
    if(i >= n || j >= n) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    dp[i][j] = (countPathMaze(n, i+1, j, dp) + countPathMaze(n, i, j+1, dp)) % MOD; // Move right (i, j+1) and down (i+1, j), and sum the number of valid paths
    return dp[i][j]; // Add return statement
}

int countPathMazeDia(int n , int i, int j ,vector<vector<int>> &dpDIA){
    if(i==n-1 &&j==n-1){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }
    if(dpDIA[i][j] != -1){
        return dpDIA[i][j];
    }

    //To Move right (i, j+1), down (i+1, j), and diagonally (i+1, j+1)
    dpDIA[i][j]  = countPathMazeDia(n, i + 1, j, dpDIA) + countPathMazeDia(n, i, j + 1, dpDIA) + countPathMazeDia(n, i + 1, j + 1, dpDIA);
    return dpDIA[i][j];
}

int main() {
    int n, i, j;
    // NOTE: Enter one dimension of square maze and starting points
    cin >> n >> i >> j;
    vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize dp with the correct size
    vector< vector<int> > dpDIA(n, vector<int>(n, -1));
    cout << "Number of paths without traveling diagonally: " << countPathMaze(n, i, j, dp) << endl;
    cout<<"Number of paths including diagonal paths: "<<countPathMazeDia(n,i,j, dpDIA)<<endl;
    return 0;
}


// //INPUT
// 7 0 0
// //OUTPUT
// Number of paths without traveling diagonally: 924
// Number of paths including diagonal paths: 8989
