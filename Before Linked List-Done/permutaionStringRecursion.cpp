//Done
//TC : O(n)
#include <bits/stdc++.h>
using namespace std;
void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);////substr(startPoint, length_upto_not_including);
        ////ch ke pheele wale tak ka string + ch ke baad wale string
        permutation(ros, ans+ch);
    }
}
int main(){
    string s;
    cin>>s;
    permutation(s, "");
    return 0;
}