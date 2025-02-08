//Not able to run
//41.2.2
//Range updates
// 

#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int  N = 1e5+2, MOD = 1e9+7;


int query(int i,int bit[], int n){
    int ans = 0;
    while(i>0){
        ans += bit[i];
        i -= i &(-i);
    }
    return ans;
}

void update(int i , int inc, int bit[], int n){
    while(i<=n){
        bit[i] += inc;
        i += i & (-i);
    }
     
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int bit[n+10] = {0};
        int u ; cin>>u;
        while(u--){
            int l, r, inc;
            cin>>l>>r>>inc;
            l++; r++;
            update(l, inc, bit,n);
            update(r+1, -inc, bit, n);

        }
        int q; cin>> q;
        while(q--){
            int w; cin>>w;
            w++;
            cout<<query(w, bit,n)<<endl;
            // cout<<
        }
    }
    return 0;
}
// //Input
// 1
// 5 3 
// 0 1 7
// 2 4 6
// 1 3 2 
// 3 
// 0
// 3
// 4
// //Output
// 7
// 8
// 6
