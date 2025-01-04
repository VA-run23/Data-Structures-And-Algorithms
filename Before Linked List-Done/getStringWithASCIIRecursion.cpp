#include <bits/stdc++.h>
using namespace std;
void subStr(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);//substr != subStr
    subStr(ros, ans);
    subStr(ros, ans+ch);
    subStr(ros, ans+to_string(code));
}
int main(){
    string s="AB";
    subStr(s, "");
    return 0;
}