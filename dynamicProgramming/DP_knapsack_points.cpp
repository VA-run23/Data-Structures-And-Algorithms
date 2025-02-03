#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 5, W = 11;
    vector<int> wt = {3, 2, 4, 5, 1};  // Weights of the items
    vector<int> val = {4, 3, 5, 6, 1}; // Values of the items
    vector<int> dp(W + 1, 0);          // DP array to store the maximum value for each weight capacity

    // The magic of Dynamic Programming (DP) in this context lies in its efficiency and elegance
    // when solving the Unbounded Knapsack Problem. Here's a brief breakdown of why using DP here is so special:

    // Optimal Substructure:
    // DP leverages the fact that the problem can be broken down into simpler subproblems,
    // each of which can be solved independently. By solving these subproblems once and storing their results,
    // the algorithm avoids redundant computations.

    // Efficient Computation:
    // Instead of trying every possible combination of items (which can be extremely time-consuming),
    // DP allows you to build up the solution by iteratively improving the maximum value for each weight capacity
    // from 0 to W.

    // Memory Utilization:
    // The use of a DP array dp of size W+1 ensures that you are storing only the necessary information
    // required to determine the maximum value for each weight capacity, thereby optimizing space usage.

    // Iterative Update:
    // By iterating over each weight capacity and item, the algorithm dynamically updates the maximum value
    // for the current weight capacity (dp[j]). This iterative update is efficient and ensures that the solution
    // builds upon previously computed values.

    // Scalability:
    // This approach scales well with larger inputs. It efficiently computes the maximum value without
    // exponential time complexity, making it suitable for larger datasets.

    // Iterate over all possible weight capacities
    for(int j = 0; j <= W; j++){
        // Iterate over all items
        for(int i = 0; i < n; i++){
            // Check if the current item can be added to the knapsack
            if(j - wt[i] >= 0)
                // Update the maximum value for the current weight capacity
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
        }
    }

    // Output the maximum value for the full knapsack capacity
    cout << dp[W] << endl;
    return 0;
}
