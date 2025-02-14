//Done
//TC : O(n)
//Done
//TC : O(n)
#include <bits/stdc++.h>
using namespace std;

void replacePi(string s){
    if(s.length() == 0){
        return;
    }
    if(s[0] == 'p' && s[1] == 'i'){
        cout << "3.14";
        replacePi(s.substr(2));
    } else {
        cout << s[0];
        replacePi(s.substr(1));
    }
}

int main(){
    string s;
    cin >> s;
    replacePi(s); // Original string remains as it is
    cout << endl << s << endl;
    return 0;
}
// //INPUT
// weoiwiopiasdfasdfpiwer


// //OUTPUT
// weoiwio3.14asdfasdf3.14wer
// weoiwiopiasdfasdfpiwer



/*
Example Execution:
Input: "weoiwiopiasdfasdfpiwer"
Initial String: "weoiwiopiasdfasdfpiwer"

First Call: replacePi("weoiwiopiasdfasdfpiwer")
s[0] = 'w', print w
Recursive call: replacePi("eoiwiopiasdfasdfpiwer")

Second Call: replacePi("eoiwiopiasdfasdfpiwer")
s[0] = 'e', print e
Recursive call: replacePi("oiwiopiasdfasdfpiwer")

Third Call: replacePi("oiwiopiasdfasdfpiwer")
s[0] = 'o', print o
Recursive call: replacePi("iwiopiasdfasdfpiwer")

...

Ninth Call: replacePi("piopiasdfasdfpiwer")
s[0] = 'p' and s[1] = 'i', print 3.14
Recursive call: replacePi("opiasdfasdfpiwer")

...

Final Call: replacePi("")
String is empty, return
*/

/*
Example Execution (Short):
Input: "weoiwiopiasdfasdfpiwer"
Initial String: "weoiwiopiasdfasdfpiwer"

First Call: replacePi("weoiwiopiasdfasdfpiwer")
s[0] = 'w', print w
Recursive call: replacePi("eoiwiopiasdfasdfpiwer")

Second Call: replacePi("eoiwiopiasdfasdfpiwer")
s[0] = 'e', print e
Recursive call: replacePi("oiwiopiasdfasdfpiwer")

Third Call: replacePi("oiwiopiasdfasdfpiwer")
s[0] = 'o', print o
Recursive call: replacePi("iwiopiasdfasdfpiwer")

...

Ninth Call: replacePi("piopiasdfasdfpiwer")
s[0] = 'p' and s[1] = 'i', print 3.14
Recursive call: replacePi("opiasdfasdfpiwer")

...

Final Call: replacePi("")
String is empty, return
*/
