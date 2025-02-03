//35.20 
// f(n-1): Represents the number of ways the first n-1 people can either remain single or pair up.
//
// (n-1) * f(n-2):
// The (n-1) factor accounts for the n-th person pairing up with any of the remaining n-1 people.
//
// After the n-th person pairs up with one of the n-1 people, we are left with n-2 people, and the number of ways these n-2 people can either remain single or pair up is given by f(n-2).
//
// So, the formula
// f(n) = f(n-1) + (n-1) * f(n-2)

//
//TC: 
#include <bits/stdc++.h>
using namespace std;

int main(){
     int n; cin>>n;
     vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i<=n;i++){
        dp[i] = dp[i-1] + (i-1)* dp[i-2];
    }
    cout<<dp[n];
    
    return 0;
}