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
// //OUTPUT
//THE OUTPUT DOESNOT GIVE BINARY REP, IT is for reference that how output is generated
// (empty string) 00000000
// C              00000001
// B              00000010
// BC             00000011
// A              00000100
// AC             00000101
// AB             00000110
// ABC            00000111



// subStr("ABC", "")            → Calls subStr("BC", "")  & subStr("BC", "A")
//  ├─ subStr("BC", "")         → Calls subStr("C", "")   & subStr("C", "B")
//  │  ├─ subStr("C", "")       → Calls subStr("", "")    & subStr("", "C")
//  │  │  ├─ subStr("", "")     → Prints: (empty string)
//  │  │  ├─ subStr("", "C")    → Prints: C
//  │  ├─ subStr("C", "B")      → Calls subStr("", "B")   & subStr("", "BC")
//  │  │  ├─ subStr("", "B")    → Prints: B
//  │  │  ├─ subStr("", "BC")   → Prints: BC
//  ├─ subStr("BC", "A")        → Calls subStr("C", "A")  & subStr("C", "AB")
//  │  ├─ subStr("C", "A")      → Calls subStr("", "A")   & subStr("", "AC")
//  │  │  ├─ subStr("", "A")    → Prints: A
//  │  │  ├─ subStr("", "AC")   → Prints: AC
//  │  ├─ subStr("C", "AB")     → Calls subStr("", "AB")  & subStr("", "ABC")
//  │  │  ├─ subStr("", "AB")   → Prints: AB
//  │  │  ├─ subStr("", "ABC")  → Prints: ABC
