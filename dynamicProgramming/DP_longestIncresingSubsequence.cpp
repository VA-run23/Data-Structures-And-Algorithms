//36.8 
//Memoisation
// Time Complexity: O(n^2)

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
#define setBits(x) __builtin_popcount(x)//counts the number of set bits (1s) in the binary representation of x


const int N = 1e5+2, MOD = 1e9+7;

int dp[N];

int lis(vi &a, int n){
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = 1;// because single element is also an lis
    for(int i = 0; i<n; i++){
        if(a[n] > a[i]){
            dp[n] = max(dp[n], 1+lis(a, i));
        }
    }
    return dp[n];  
}

int main(){

    rep(i, 0, N){
        dp[i] = -1;
    }   
    int n;
    cin>> n;
    vi a(n);
    rep(i, 0, n){
        cin>> a[i];
    }
    cout<<lis(a, n-1)<<endl;

    return 0;
}

// Input:
// 9 
// 10 22 9 33 21 50 52 60 80
// Output:
// 7