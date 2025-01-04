//32.6
//Done
//TC : O(n)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

int main(){
    int n, k;
    cin>>n>>k;
    vi a(n);

    rep(i,0,n) cin>>a[i];
    int s = 0, ans = INT_MAX;
    rep(i, 0,k)s+= a[i];
    ans = min(ans, s);
    

    //sliding window
rep(i, 1, n - k + 1) {
    s -= a[i - 1];
    s += a[i + k - 1];
    ans = min(ans, s);
}

    cout<<ans<<endl;
    return 0;
}

// //Input
// 8 3 
// -2 10 1 3 2 -1 4 5
// //Output
// 4