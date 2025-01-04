//35.2
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

// Global variables
const int N = 1e5 + 2, MOD = 1e9 + 7;

int dp[N];

// Type 1: Iterative with Constant Space
// TC: O(n), SC: O(1)
int fib1(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
        // cout<<c<<endl;
    }
    return c;
}

// Type 2: Dynamic Programming with Array (Bottom-Up / Tabulation)
// TC: O(n), SC: O(n)
int fib2(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    return dp[n];
}

// Type 3: Simple Recursive
// TC: O(2^n), SC: O(n)
int fib3(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fib3(n - 1) + fib3(n - 2);
}

// Type 4: Recursive with Memoization (Top-Down / Memoization)
// TC: O(n), SC: O(n)
int fib4(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = (fib4(n - 1) + fib4(n - 2)) % MOD;
    return dp[n];
}

// Type 5: Bottom-Up Dynamic Programming (Tabulation)
// TC: O(n), SC: O(n)
int fib5(int n) {
    vi dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    rep(i, 3, n + 1) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n; 
    cin >> n;

    // Initialize dp array for Type 4 function
    rep(i, 0, N) {
        dp[i] = -1;
    }

    // You can call any of the fib functions here:
    cout << "Type 1: " << fib1(n) << endl;
    cout << "Type 2: " << fib2(n) << endl;  // Bottom-Up / Tabulation
    cout << "Type 3: " << fib3(n) << endl;
    cout << "Type 4: " << fib4(n) << endl;  // Top-Down / Memoization
    cout << "Type 5: " << fib5(n) << endl;  // Bottom-Up / Tabulation

    return 0;
}
