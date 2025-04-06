//Done
//TC: O(n * W)
#include <bits/stdc++.h>
using namespace std;

int knapsack(int value[], int wt[], int n, int W, vector<vector<int>> &dp) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (dp[n][W] != INT_MIN) {
        return dp[n][W];
    }
    if (wt[n - 1] > W) {
        //W is always the new current capacity 
        dp[n][W] = knapsack(value, wt, n - 1, W, dp);//if the weight of the current item > capacity, exclude to add to the knapsack
    } else {
        dp[n][W] = max( // The function then returns the maximum value of these two scenarios, ensuring the optimal solution.
                    knapsack(value, wt, n - 1, W - wt[n - 1], dp) + value[n - 1], // Including the current item, adding its value, and reducing the capacity accordingly.
                    knapsack(value, wt, n - 1, W, dp)// Excluding the current item.
                );
    }
    return dp[n][W];
 
   
}

int main() {
    int wt[] = {10, 20, 30}; // wt and value are corresponding to each other
    int value[] = {100, 50, 150};
    int W = 50;
    int n = sizeof(wt) / sizeof(wt[0]);
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, INT_MIN));

    cout << knapsack(value, wt, n, W, dp) << endl;
    return 0;
}
// This program puts a restriction of W on wt to get the maximum value

 // Computed DP Table:
    // Items (n) → / Weights (W) ↓   0   10   20   30   40   50
    // 0                              0    0    0    0    0    0
    // 1                              0  100  100  100  100  100
    // 2                              0  100  100  150  150  150
    // 3                              0  100  100  150  150  250
