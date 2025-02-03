//35.10
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


const int N = 102, MOD = 1e9+7;
int a[N];
int dp[N][N];

//Memoization approach
int mcm(int i , int j){
    if( i ==  j){
        return 0 ;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = MOD;
    for(int  k  = i; k<j; k++){
        dp[i][j] =  min(dp[i][j], mcm(i, k)+ mcm(k+1, j) + a[i-1]*a[k]*a[j]);//this much operations takes place for matrix multiplication
    }
    return dp[i][j];
}



int main(){
    int n; cin>>n;
    rep(i, 0, n){
        cin>>a[i];
    }
    memset(dp, -1, sizeof dp);
    //memeset(); is required only for memoization

    cout<<mcm(1, n-1)<<endl;


    return 0;
}

// //Input:
// 5 
// 10 20 30 20 30 
// //Output
// 18000