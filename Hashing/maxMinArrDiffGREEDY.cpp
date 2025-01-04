//33.7 
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
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) cin>>i;
    sort(a.begin(), a.end());
    long long mn = 0, mx = 0;
    for(int i = 0; i < n/2; i++){
        mx += (a[i + n/2] - a[i]);//sum of: first - last , first+1 - last - 1 and so on
        mn += (a[2*i + 1] - a[2*i]);//sum of: difference of odd indexed - even indexed values
    }

    cout<<mn<<" " <<  mx<<endl;
    return 0;
}