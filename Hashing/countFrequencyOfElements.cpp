//
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)
// The __builtin_popcount(x) function is a built-in function provided by GCC (GNU Compiler Collection).
//  It counts the number of set bits (1s) in the binary representation of an integer x. This is also known as the “population count” or “Hamming weight” of the number.

int main(){
    int n;
    cin>>n;
    vi a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    // unordered_map<int,int> freq;
    // rep(i,0,n){
    //     freq[a[i]]++;
    // }
    // unordered_map<int, int> :: iterator it;
    // for(it = freq.begin(); it!= freq.end(); it++){
    //     cout<<it->ff<<" "<<it->ss<<endl;
    // }
    map<int,int> freq;
    rep(i,0,n){
        freq[a[i]]++;
    }
    map<int, int> :: iterator it;
    for(it = freq.begin(); it!= freq.end(); it++){
        cout<<it->ff<<" "<<it->ss<<endl;
    }
    return 0;
}

// //input
// 6
// 1 2 1 3 2 1
// ////Output

// 3 1
// 2 2
// 1 3
