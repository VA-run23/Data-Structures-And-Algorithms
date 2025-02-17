//DONE
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
/*
////Output if only 23 is input
Here's how the recursive calls and combinations look in the call stack:

keypad("23", "")
keypad("3", "a")
    keypad("", "ad") -> print ad
    keypad("", "ae") -> print ae
    keypad("", "af") -> print af
keypad("3", "b")
    keypad("", "bd") -> print bd
    keypad("", "be") -> print be
    keypad("", "bf") -> print bf
keypad("3", "c")
    keypad("", "cd") -> print cd
    keypad("", "ce") -> print ce
    keypad("", "cf") -> print cf
*/


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
