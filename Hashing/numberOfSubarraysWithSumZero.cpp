//Brute force: Summing of each subarray, Its TC:O(n^2)
//Prefix_sum = sum from beginning to i-th element

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x)__builtin_popcount(x)

int main(){
    int n; 
    cin>>n;
    vi a(n);
    rep(i,0,n)
        cin>>a[i];
    map<int, int> cnt;
    int prefSum = 0;
    rep(i, 0,n){
    prefSum += a[i];
    cnt[prefSum]++;
    }
    int ans = 0;
    map<int, int> :: iterator it;
    for(it = cnt.begin(); it!= cnt.end(); it++){
        int c = it->ss;//for input 1 -1 1 -1
        ans += (c*(c-1))/2;//here i am getting 2 ones in prefSum, so to get number of subarrays with zero sum between those two occurances of 1, combination is used, similarly two zeros appear so number of combinations in 1, and those two zeros also accounts for the final answer
        if(it->ff == 0){
            ans += it->ss;
        }
    }
    cout<<ans<<endl;
    return 0;
}   

//INPUT
// 1
// -1
// 1
// -1
