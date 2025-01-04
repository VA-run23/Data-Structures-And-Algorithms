//Choosing the best option available at the current movement, this choice can change with the arrival of the new choice
////Done
//TC : O(nlogn)
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
    // cout<<"Enter the number of denominations: "<<endl;
    cin>>n;
    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    int x; 
    // cout<<"Enter the amount : "<<endl;
    cin>>x;

    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;
    for(int i =0; i<n; i++){
        ans += x/a[i];//Increases the number of coins
        x-=x/a[i] * a[i];//x - number_of_notes * denomination_of_that_note
    }
    cout<<ans<<endl;
    return 0;
}