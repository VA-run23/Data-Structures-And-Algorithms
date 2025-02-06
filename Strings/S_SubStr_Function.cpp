//
//
//Time complexity: O(ST)
// string substr(position , length); returns the string of length 

#include <bits/stdc++.h>
using namespace std;

const int  N = 1e5+2, MOD = 1e9+7;


int main(){
    string s  = "na";
    string t = "apna collegena";
    int S = s.size(), T= t.size();
    for(int i = 0; i<T- S+1; i++){
        if(t.substr(i, S) == s){
            cout<<"Found at index : "<<i<<endl;
        }
    }
    return 0;
}
// //Output
// Found at index : 2
// Found at index : 12
