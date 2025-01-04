#include <bits/stdc++.h>
using namespace std;

void reverse(string s) {
    // Base case: if the string is empty, return
    if(s.length() == 0) {
        return;
    }
    // Get the substring starting from the second character
    string ros = s.substr(1);
    // The string is broken down for each character till the last character by recursion,
    // and then prints the characters from the last function call, which reverses the string.
    reverse(ros);
    // After each recursive call, the variable s has one character less from the beginning.
    // We make use of this to get the reverse of the given string.
    cout << s[0];
}

int main() {
    reverse("Hello_Binod"); // Call the reverse function with the input string
    return 0;
}
