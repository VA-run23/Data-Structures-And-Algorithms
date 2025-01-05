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

int dp[105][10005];


// int coinChange(vi &a, int n, int x){
//     if(x==0)
//         return 1;
//     if(x<0)
//         return 0;
//     if(n<=0)
//         return 0;
//     return coinChange(a, n, x-a[n-1]) + coinChange(a, n-1, x);
//     //when we take coin                when we dont take coin
// }


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

    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];
    int x;
    cin >> x;
    // cout << coinChange(a, n, x) << endl;
    // cout << coinChangeDP(a, n, x) << endl;

    //iterative version
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

    return 0;
}
