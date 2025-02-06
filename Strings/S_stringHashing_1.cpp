//39.1.2
//


#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;
int p = 31;
vector<long long> powers(N); 

long long calculate_hash(string s){
    long long hash  = 0;
    for(int i = 0; i<s.size(); i++){
        hash =(hash + (s[i] - 'a' + 1) * powers[i])%MOD;
    }
}

int main(){
    
    powers[0] =1;
    for(int i =1; i<N; i++){
        powers[i] = (powers[i-1] * p) % MOD;
    }
    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "b"};
    vector<long long> hashes;
    for(auto w : strings){
        hashes.push_back(calculate_hash(w));
    }    
    //Time complexity : O(nm)
    sort(hashes.begin(), hashes.end());
    //Time complexity : o(n log n)

    //Final time complexity: O(nm + nlog(n))

    int distinct = 0;
    for(int i = 0; i< hashes.size(); i++){
        if(i == 0 or hashes[i]  != hashes[i-1])
        distinct++;
    }
    return 0;
}