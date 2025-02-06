//37.4

// Modular Arithmetic Properties
// 
// (a + b) % m = (a % m) + (b % m)
// 
// Explanation:
// The sum of two numbers a and b, taken modulo m, is equal to the sum of a and b 
// taken separately modulo m.
//
// (a * b) % m = (a % m) * (b % m)
// 
// Explanation:
// The product of two numbers a and b, taken modulo m, is equal to the product of 
// a and b taken separately modulo m.
//
// (a - b) % m = (a % m) - (b % m)
// 
// Explanation:
// The difference of two numbers a and b, taken modulo m, is equal to the difference 
// of a and b taken separately modulo m.
//
// (a / b) % m = (a % m) * (b^(-1) % m)
// 
// Explanation:
// The division of two numbers a and b, taken modulo m, involves the multiplicative 
// inverse of b modulo m, represented as b^(-1).


////Without recursion
#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;

int power(int a, int n){
    a %= MOD;//If not taken MOD, chances that the answer will be in negative
    int ans = 1;
    while(n>0){
        if(n&1){
            ans = (ans * a) %MOD;
        }
        a = (a*a) % MOD;
        n = n>>1;
    }
    return ans;
}

int main(){
    int a, n;
    cin>>a>>n;
    cout<<power(a, n)<<endl;
    return 0;
}