//36.8 
//Tabulation
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


int main(){
    int n; cin>>n;
    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    vi dp(n, 1);
    int ans = 0;
    rep(i, 1, n){
        rep(j, 0, i){
            if(a[i]> a[j]){
                dp[i] =  max(dp[i], dp[j]+ 1);
            }
        }
        ans = max(ans , dp[i]);

    }
    cout<<ans<<endl;

    return 0;
}

// Input:
// 9 
// 10 22 9 33 21 50 52 60 80
// Output:
// 7