//35.7 
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
int val[N], wt[N];

int Knapsack(int n, int w){
    if(w<= 0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(wt[n-1]>w){
        return Knapsack(n-1, w);
    }
    return max(Knapsack(n-1, w), val[n-1]+Knapsack(n-1, w-wt[n-1]));
}

int main(){
    int n ; cin>>n;
    int w; cin>>w;

    rep(i,0,n){
        cin>>wt[i];
    }
    rep(i,0,n){
        cin>>val[i];
    }

    cout<<Knapsack(n, w)<<endl;
    return 0;
}
// //Input
// 3
// 50
// 15 30 45
// 60 100 150
// //Output
// 160
