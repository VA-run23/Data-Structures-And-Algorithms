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
        dp[n][W] = knapsack(value, wt, n - 1, W, dp);
    } else {
        dp[n][W] = max(knapsack(value, wt, n - 1, W - wt[n - 1], dp) + value[n - 1], knapsack(value, wt, n - 1, W, dp));
    }
    return dp[n][W];
    // This line evaluates two scenarios:
    // Including the current item, adding its value, and reducing the capacity accordingly.
    // Excluding the current item.
    // The function then returns the maximum value of these two scenarios, ensuring the optimal solution.
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
