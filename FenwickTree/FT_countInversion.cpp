//i<j
// if(a[i] > a[j]) forms the count inversion
//41.3
// The relative ordering also gives the same answer.

#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int  N = 1e5+2, MOD = 1e9+7;
vector<int> bit;


int getSum(int idx){
    int sum = 0;
    while(idx){
        sum +=bit[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int n, int idx, int inc){
    while(idx <=n){
        bit[idx] += inc;
        idx += idx & (-idx);
    }

}





int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    vector<int> temp = a;
    sort(temp.begin(), temp.end());
    for(int i  = 0; i<n; i++){
        a[i] = lower_bound(temp.begin(), temp.end() , a[i])- temp.begin() +1 ;//lower_bound returns an iterator, since we have subtracted temp.egin() 

    }
    
    bit = vector<int> (n+1);
    int inv= 0;
    for(int i = n-1; i>=0; i--){
        inv += getSum(a[i] -1);
        update(n, a[i], 1);
    }
    cout<<inv;

    return 0;
}
// //Input
// 8
// 3 5 6 9 1 2 6 7 
//Output
// 10