//35.9
//Time complexity: O(n*m)
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


const int N = 1e3+2, MOD = 1e9+7;

int lcs(string &s1, string &s2, int n, int m){//passing by reference to avoid copying and the time complexity will be O(1) instead of O(n)
    if(n==0 || m==0) return 0;
    if(s1[n-1]==s2[m-1]) return 1+lcs(s1, s2, n-1, m-1);
    else return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));//taking last character of s1 and s2 and comparing them


}



int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length(), m = s2.length();
    cout<<lcs(s1, s2,n, m)<<endl;

    return 0;
}

// // Input:
// rishabh
// shubhi
// // Output:
// 4