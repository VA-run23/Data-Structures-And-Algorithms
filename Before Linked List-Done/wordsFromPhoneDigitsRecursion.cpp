#include <bits/stdc++.h>
using namespace std;

string keypadArr[]={"","./", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv","wxyz" };
void keypad(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=keypadArr[ch-'0'];//when ch = 2, it converts character '2' into integer 2, and keypadArr[2] is abc
    string ros=s.substr(1);
    for(int i=0; i<code.length(); i++){
        keypad(ros, ans+code[i]);//code[i] = a for first reccursion call and ans = ""
    }//keypad("3", "a"); first recursive call
}
int main(){
    keypad("235", "");
    return 0;
}
// ////Output if only 23 is input
// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf

// ////Output if  235 is input
// adj
// adk
// adl
// aej
// aek
// ael
// afj
// afk
// afl
// bdj
// bdk
// bdl
// bej
// bek
// bel
// bfj
// bfk
// bfl
// cdj
// cdk
// cdl
// cej
// cek
// cel
// cfj
// cfk
// cfl