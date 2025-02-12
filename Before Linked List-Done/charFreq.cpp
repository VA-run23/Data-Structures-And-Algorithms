//done
//TC : O(n)
////Namaste
//My version

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s="heqoiadfafahiokmlhqhfnf";
    int freq[26];
    int mx=0, preMx = 0;;
    char ans;
    for(int i=0;i<26; i++){
        freq[i]=0;
    }
    for(int i=0; i<s.size(); i++){
        freq[s[i] - 'a']++; // If s[i] is 'a', the value at the zeroth index will be incremented by one. If s[i] is 'b', the value at the first index will be incremented.
        preMx = mx;
        mx = max(mx, freq[s[i] - 'a']);
        if(preMx  != mx){
             ans = s[i];
        }
    }

    cout<<ans<<":"<<mx<<endl;


return 0;
}
// //output
// h:4