//Done
//TC: O(n)
//
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int n = s.size();
    stack<char> st;
    bool ans = true;

    //Opening bracket is pushed to the stack,
    //Closing bracket is matched with the opening bracket and the opening bracket is popped out if matched
    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        } else if (s[i] == '}') {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        } else if (s[i] == ']') {
            if (!st.empty() && st.top() == '[') {
                st.pop();
            } else {
                ans = false;
                break;
            }
        }
    }
    if (!st.empty()) ans = false;//extra remaining braces Eg: [{}])) for such conditions
     if (ans) {
        cout << "Valid string" << endl;
    } else {
        cout << "Invalid string" << endl;
    }
    return ans;
}

int main() {
    string s = "({[]})";
    string s1 = "({()]})";
    string s3 = "(a-b/c)*(a/k-l)";
    isValid(s1);
    isValid(s);
    isValid(s3);
    return 0;
}


// //Output
// Invalid string
// Valid string
// Valid string