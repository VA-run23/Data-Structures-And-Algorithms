//39.4
//Calculate the indices of the occurrences of string s in t.
//

#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;

int p  = 31;
vector<long long> powers(N);



int main(){
    string s = "na";
    string t = "apnacollegena na";
    int T= t.size(), S=s.size();

    powers[0] = 1;
    for(int i = 1; i<N; i++){
        powers[i] =(powers[i-1]*p)%MOD;
    }

    vector<long long> h(T+1, 0);
    for(int i = 0; i<T; i++){
        h[i+1] =(h[i] + (t[i] - 'a' +1)* powers[i])%MOD;
    }
    long long hString = 0; 
    for(int i = 0; i<S; i++){
        hString= (hString+(s[i] - 'a' +1) * powers[i])%MOD;
    }
    for(int i = 0; i+S-1<T; i++){
        long long currHash = (h[i+S]-h[i]+MOD) %MOD;
        if(currHash == ( hString* powers[i] )%MOD){
            cout<<"Found at index "<<i<<endl;
        }
    }

    return 0;
}
// //Output
// Found at index 2
// Found at index 11
// Found at index 14
