//Not able to run
//41.2(point updates)
//2 types of update
//range sum with point updates
//range sum with range updates 

#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int  N = 1e5+2, MOD = 1e9+7;

int n;
vector<int> bit;

void update(int idx, int val){
    while(idx <=n){
        bit[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx){
    int ans = 0; 
    while(idx> 0){
        ans += bit[idx];
        idx -= idx &(-idx);
    }
    return ans;
}


int main(){
    cin>>n;
    bit = vector<int> (n+1);
    vector<int> a(n+1);
    for( int i = 1; i<= n;i++ ){
        cin>>a[i];
        update(i, a[i]);
    }
    int q; cin>>q;

    while(q--){
        int c ; cin>>c;
            if(c==1){
                int l, r; cin>>l>>r;
                int  ans = query(r) - query(l-1);
                cout<<ans<<endl;
            }else if(c ==2){
                int index, val;
                cin>>index>>val;
                update(index, -a[index]);
                a[index] = val;
                update(index, val);
            }
    }
    return 0;
}

// //Sample input 1
// 5
// 1 2 3 4 5
// 4
// 1 1 3
// 1 2 5
// 2 3 10
// 1 2 5
