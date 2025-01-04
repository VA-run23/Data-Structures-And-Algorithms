
//TC: 
//
#include <bits/stdc++.h>
using namespace std;

// Function to determine the precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3; // Highest precedence for exponentiation
    } else if (c == '*' || c == '/') {
        return 2; // Higher precedence for multiplication and division
    } else if (c == '+' || c == '-') {
        return 1; // Lowest precedence for addition and subtraction
    } else {
        return 0; // Non-operator characters
    }
}

// Function to convert infix expression to prefix expression
string infixToPrefix(string s) {
    // Reverse the infix expression
    reverse(s.begin(), s.end());
    cout << "The reversed string is: " << s << endl;

    stack<char> st; // Stack to hold operators and parentheses
    string res;     // Resultant prefix expression

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            // If s[i] is an operand (letter), add it to the result
            res += s[i];
        } else if (s[i] == ')') {
            // If s[i] is a closing parenthesis, push it onto the stack
            st.push(s[i]);
        } else if (s[i] == '(') {
            // If s[i] is an opening parenthesis
            while (!st.empty() && st.top() != ')') {
                // Pop from stack to result until a closing parenthesis is found
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                // Pop the closing parenthesis from the stack
                st.pop();
            }
        } else {
            // For operators
            while (!st.empty() && precedence(st.top()) > precedence(s[i])) {
                // Pop operators from stack to result based on precedence
                res += st.top();
                st.pop();
            }
            // Push the current operator onto the stack
            st.push(s[i]);
        }
    }
    // Pop all remaining operators from the stack to result
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    // Reverse the result to get the final prefix expression
    reverse(res.begin(), res.end());
    return res;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string s) {
    stack<char> st; // Stack to hold operators and parentheses
    string res;     // Resultant postfix expression

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            // If s[i] is an operand (letter), add it to the result
            res += s[i];
        } else if (s[i] == '(') {
            // If s[i] is an opening parenthesis, push it onto the stack
            st.push(s[i]);
        } else if (s[i] == ')') {
            // If s[i] is a closing parenthesis
            while (!st.empty() && st.top() != '(') {
                // Pop from stack to result until an opening parenthesis is found
                res += st.top();
                st.pop();
            }
            if (!st.empty()) {
                // Pop the opening parenthesis from the stack
                st.pop();
            }
        } else {
            ////"Push Operators Carefully, Pop When Precedence Drops."
            //// Pop When Precedence Drops: While the stack is not empty and the precedence of the operator on the stack is greater than or
            //// equal to the precedence of the current operator, pop the stack and add the operator to the postfix expression.
            // For operators
            while (!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                // Pop operators from stack to result based on precedence
                res += st.top();
                st.pop();
            }
            // Push the current operator onto the stack
            st.push(s[i]);
        }
    }
    // Pop all remaining operators from the stack to result
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

int main() {
    // Test the function with an example infix expression
    cout << "The prefix notation is: " << infixToPrefix("(a-b/c)*(d/k-l)") << endl;
    cout << "The postfix notation is: " << infixToPostfix("(a-b/c)*(d/k-l)") << endl;

    return 0;
}
// // // /Output
// The reversed string is: )l-k/d(*)c/b-a(
// The prefix notation is: *-a/bc-/dkl
// The postfix notation is: abc/-dk/l-*
