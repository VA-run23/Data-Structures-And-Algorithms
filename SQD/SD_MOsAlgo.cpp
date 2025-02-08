//42.3
//
// 
//TC:O((n + q) * √n).

#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int  N = 1e5+2, MOD = 1e9+7;
int rootN;

struct Q{
    int idx, l, r;
};
Q q[N];

bool compare(Q q1, Q q2){
    if(q1.l / rootN == q2.l/rootN){
        return q1.r > q2.r;
    }
    return q1.l/rootN < q2.l/rootN;

}

int main(){
    int n; cin>>n ;
    vector<int> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    rootN = (int)sqrtl(n);
    int queries; 
    cin>>queries;
    for(int i =0; i<queries; i++){
        int l, r;
        cin>>l>>r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;

    }
    sort(q, q+queries, compare);

    //Offline processing
    vector<int> ans(queries);
    int currL = 0, currR = -1, l , r;
    int currAns= 0;
    for(int i = 0; i< queries; i++){
        l= q[i].l; 
        r = q[i].r;
        l--; r--;

        while(currR < r){
            currR++;
            currAns += a[currR];
        }
        while(currL > l){
            currL--; 
            currAns += a[currL];

        }

        while(currL < l){
            currAns -= a[currL];
            currL++;
        }

        while(currR > r){
             currAns -= a[currR];
            currR--;

        }

        ans[q[i].idx] = currAns;

    }

    for(int i = 0; i<queries; i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
// //Input
// 9
// 1 5 -2 6 8 -7 2 1 11
// 3
// 7 8
// 1 6
// 2 7
// //Output
// 3
// 11
// 12
