#include <bits/stdc++.h>
using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];//store first character of the string
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){//this program only removes the immediate duplicates only
        return ans;
    }
    return (ch+ans);
}
int main(){
    string s;
    cin>>s;
    cout<<removeDup(s)<<endl;
return 0;
}

////Output 1
// abcdcba
// abcdcba
////Output 2
// aabbcc
// abc