//35.3
//
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


// int MinSquare(int n){//recursive approach
//   if(n==1 || n==2 || n==3 || n==0) return n;
//   int ans = MOD;
//   for(int i = 1; i*i<=n; i++){
//     ans = min(ans, 1+MinSquare(n-i*i));
//   }
//     return ans;
// }

//DP approach
int MinSquareDP(int n){//recursive approach
  if(n==1 || n==2 || n==3 || n==0) return n;

  if(dp[n]!=MOD) return dp[n];
  
  for(int i = 1; i*i<=n; i++){
    dp[n] = min(dp[n], 1+MinSquareDP(n-i*i));
  }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    vi dp(n+1, MOD);
    dp[0]= 0;
    dp[1]= 1;
    dp[2]= 2;
    dp[3]= 3;
    for(int i = 1; i*i<=n; i++){//i*i< n == i< sqrt(n)
        for(int j= 0; i*i+j <=n; j++){
            dp[i*i +j] = min(dp[i*i +j], 1+dp[j]);
        }
    }

    cout<<dp[n]<<endl;
}