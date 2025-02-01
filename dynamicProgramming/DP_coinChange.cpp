//Given a set of coins and a value V. Fint the number of ways we can make the change of 'V'.
//We can use the coins any number of times.
//permutation of coins is not allowed.
//To make ways with every coin, we have 2 options


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define vpi vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x) // counts the number of set bits (1s) in the binary representation of x

const int N = 1e5+2, MOD = 1e9+7;

int dp[105][105];

//Without memoization (overlapping is occuring)
//Time Complexity: O(2^n)

// Overlapping occurs when memoization is not done.
// Without memoization, the same subproblems are solved multiple times,
// int coinChange(vi &a, int n, int x){
//     if(x==0)
//         return 1;
//     if(x<0)
//         return 0;
//     if(n<=0)
//         return 0;
//     return coinChange(a, n, x - a[n-1]) + coinChange(a, n-1, x);
// When we take the coin (a[n-1]), we reduce the remaining amount (x - a[n-1])
// and call coinChange with the same set of coins (n remains the same).
// When we don't take the coin, we exclude the coin (reduce n by 1) and
// call coinChange with the remaining amount (x).
// }


//With memoization
// Time Complexity: O(n * x) 
// n is the number of coins and x is the target amount.
// int coinChangeDP(vi &a, int n, int x){
//     if(x == 0)
//         return 1;
//     if(x < 0)
//         return 0;
//     if(n <= 0)
//         return 0;
//     // Memoizing 
//     if(dp[n][x] != -1)
//         return dp[n][x];
//     dp[n][x] =  coinChangeDP(a, n, x-a[n-1]) + coinChangeDP(a, n-1, x);
//     // when we take coin                when we don't take coin
//     return dp[n][x];
// }


int main(){
    memset(dp, -1, sizeof(dp));
    // Initialize all elements of the 2D array `dp` to -1.
    // `memset` sets each byte of the memory block to the specified value (-1).
    // `sizeof(dp)` calculates the total size of the `dp` array in bytes.

    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];
    int x;
    cin >> x;
    // cout << coinChange(a, n, x) << endl;
    // cout << coinChangeDP(a, n, x) << endl;

    //iterative with memoization
    vvi dp(n+1, vi(x+1, 0));
    dp[0][0] = 1;
    rep(i, 1, n+1){
        rep(j, 0, x+1){
            if(j-a[i-1] >= 0)
                (dp[i][j] += dp[i][j-a[i-1]]);
            dp[i][j] += dp[i-1][j];
        }
    }
    cout << dp[n][x] << endl;

/*
    Iterative Dynamic Programming:

    rep(i, 1, n+1){
        rep(j, 0, x+1){
            if(j-a[i-1] >= 0)
                (dp[i][j] += dp[i][j-a[i-1]]);
            dp[i][j] += dp[i-1][j];
        }
    }

    The outer loop rep(i, 1, n+1) iterates over the coins from 1 to n.
    The inner loop rep(j, 0, x+1) iterates over the amounts from 0 to x.

    If Condition:
    if(j-a[i-1] >= 0)
        (dp[i][j] += dp[i][j-a[i-1]]);
    For each coin i and amount j, if the current amount j is at least as large as the coin value a[i-1], 
    then we add the number of ways to make change for the amount j - a[i-1] using the first i coins to dp[i][j]. 
    This accounts for including the current coin a[i-1].

    Update DP Table:
    dp[i][j] += dp[i-1][j];
    Add the number of ways to make change for the amount j using the first i-1 coins to dp[i][j]. This accounts for excluding the current coin a[i-1].\
*/////////////////////////

    return 0;
}
