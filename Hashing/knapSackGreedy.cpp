//33.4
//Done
//TC : O(nlogns)
//Fractional Knapsack using greedy algorithm
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)


bool compare(pii p1, pii p2){//Lambda function?
//Comparing each pair , by taking two at a time
    double  v1 = (double)p1.ff/p1.ss;
    double  v2 = (double)p2.ff/p2.ss;
    return v1> v2;
}

int main(){
    int n;
    cin>>n;
    // cout<<"Enter the value and weight of"<<n<<"items"<<endl;
    vii a(n);//vector of pair<int, int>, stores item's value with its weight
    rep(i, 0, n){
        cin>>a[i].ff>> a[i].ss;
    }
    int w;
    // cout<<"Enter capacity of the bag: "<<endl;
    cin>>w;
    sort(a.begin(), a.end(), compare);// Sort items based on value-to-weight ratio in descending order
    //The third parameter to the sort function is comparator, the third parameter which is function here is passed as argument not called 
    int ans =0;
    rep(i, 0, n){
        if(w>= a[i].ss){//if the knapsack carry the whole item
            ans += a[i].ff;
            w-=a[i].ss;
            continue;
        }
        //if knapsack cannot carry the while item
        double vw = (double) a[i].ff/a[i].ss;//value weight ratio
        ans+= vw*w;//multiplying the vw with remaining weight
        w = 0;//knap sack if full
        break;
    }
    cout<<ans<<endl;
    return 0;
}
// //Input
// 5 
// 21 7
// 24 4 
// 12 6
// 40 5
// 30 6
// 20

// //output
// 109

////NOTE
// sort(a.begin(), a.end(), compare);//why just compare why not compare()?
// compare: Passes the function itself as a comparator.
// compare(): Calls the function and passes its return value, which is not useful in this context.

