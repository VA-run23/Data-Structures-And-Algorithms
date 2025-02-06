//39.3
//Important for me
//KMP algorithm is used to find the occurances of string s in string t.
//also gives its index
//TC: O(S + T)

#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;

vector<int> prefixFunction(string s){
    int n = s.size();
    vector<int> pi(n,0);
    for(int i = 1; i<n; i++){
        int j = pi[i-1]; 

        // S[0..i-1] = ab.ab
        // pi[i-1] = 2
        // S[0..i] = abc.abc
        // pi[i] = j++;
        while (j> 0 and s[i] != s[j])
        {
            j=pi[j-1];
        }
        


        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;


    }
    return pi;
}

int main(){
    string s = "abcabcd";
    vector<int> res = prefixFunction(s);
    for (auto i: res){
        cout<<i<<" ";

    }
    cout<<endl;
    return 0;
}