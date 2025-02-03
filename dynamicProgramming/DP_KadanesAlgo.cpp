//35.5
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

    int curr =0, maxTillNow = 0;
    rep(i, 0, n){
        curr += a[i];
        maxTillNow = max(curr, maxTillNow);
        if(curr < 0){
            curr = 0;
        }
    }
    cout<<maxTillNow<<endl;
    return 0;
}
// //Input
// 8 
// -5 -1 5 -3 -1 2 3 -6
// // Output
// 6