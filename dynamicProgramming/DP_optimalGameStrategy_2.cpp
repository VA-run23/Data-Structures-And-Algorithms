//35.12
//
//TC: O(n)
#include "bits/stdc++.h"
using namespace std;
vector<int> a;

///with memoization
int dp[100][100];
int solve(int i, int j){
    if(i == j){
        return a[i];
    }
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int l = a[i] + min(solve(i+2,j), solve(i+1,j-1));//if i-th coin is taken
    //A[i..j], remaining coins = A[i+1..j]
    int r = a[j] + min(solve(i,j-2), solve(i+1,j-1));//if j-th coin os taken
    //A[i..j], remaining coins = A[i..j-1]
    return dp[i][j]=  max(l, r);
}


// ////WIthout memoization
// int dp[100][100];
// int solve(int i, int j){
//     if(i == j){
//         return a[i];
//     }
//     if(i > j){
//         return 0;
//     }
  
//     int l = a[i] + min(solve(i+2,j), solve(i+1,j-1));//if i-th coin is taken
//     //A[i..j], remaining coins = A[i+1..j]
//     int r = a[j] + min(solve(i,j-2), solve(i+1,j-1));//if j-th coin os taken
//     //A[i..j], remaining coins = A[i..j-1]
//     max(l, r);
// }


int main() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve(0, n - 1) << endl;
    return 0;
}

// //Output
// 4 1 2 3 4 
// //Input
// 6
