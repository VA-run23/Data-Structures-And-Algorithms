//35.9
//Time complexity: O(n*m)
//Tabulation method
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


const int N = 1e3+2, MOD = 1e9+7;
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.size(), m = s2.size();
    vvi dp(n+1, vi(m+1, 0));//n is number of rows and m is number of columns

    rep(i, 0, n+1){
        rep(j, 0, m+1){
            if( i == 0 || j==0){
                dp[i][j] = 0;
                continue;
            }
            else if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}

// //Input
// rishabh
// shubhi
// //Output
// 4