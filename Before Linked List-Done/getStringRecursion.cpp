//Done
//TC : O(2^n)
#include <bits/stdc++.h>
using namespace std;
void subStr(string s, string ans) {
    if(s.length() == 0) { // Base case
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1); // Create a substring ros by removing the first character
    
    subStr(ros, ans); // Recursive call without including the current character
    subStr(ros, ans + ch); // Recursive call including the current character
}

int main(){
    string s="ABC";
    subStr(s, "");
    return 0;
}