//Done
//TC: 
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> st;
    bool ans = false; // Initially assuming no redundant parentheses

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            if (!st.empty() && st.top() == '(') {
                ans = true; // Found redundant parentheses
            }
            while (!st.empty() && (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')) {
                st.pop(); // In this loop, we are removing all the operators which are inside the parenthesis
            }
            if (!st.empty()) {
                st.pop(); // Pop the opening '(' after removing all the operators enclosed by it and its partner
            }
        }
    }

    cout << ans; // Prints 1 if there are redundant parentheses, otherwise 0

    return 0;
}

// Sample inputs and expected outputs:
// Input: (a + b) * c
// Output: 0 (No redundant parentheses)
//
// Input: ((a + b) * c) - (d / e)
// Output: 0 (No redundant parentheses)
