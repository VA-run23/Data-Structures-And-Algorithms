//Done
//TC: 
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s; // Input the string from the user

    // Create a vector to store the last index of each character.
    // Initialize all values with -1 (indicating the character hasn't been seen yet).
    vector<int> dict(256, -1); // 256 is the number of ASCII characters

    int maxLen = 0; // Variable to store the length of the longest substring without repeating characters
    int start = -1; // Variable to store the starting index of the current substring

    // Loop through each character in the string
    for (int i = 0; i < s.size(); i++) {
        // If the character has been seen and its last index is greater than the start of the current substring
        if (dict[s[i]] > start) { //START STORES THE FIRST INDEX OF LONGEST SUBSTRING WITHOUT REPEATATION OF CHARACTERS
            // Update the start to the last index of the current character
            start = dict[s[i]];//
        }
        // Update the last index of the current character to the current position
        dict[s[i]] = i;
        // Calculate the length of the current substring and update maxLen if it's the longest so far
        maxLen = max(maxLen, i - start);
    }

    // Output the length of the longest substring without repeating characters
    cout << maxLen;

    return 0;
}

// //if a character is repeated , start updates , so, it starts the length of the new substring 
// //the index of the character is place in dict vector at the index value of their ascii value 
// The dict vector is used to store the last seen index of each character. The index of the character is placed in the dict vector at the index corresponding to the ASCII value of that character.
// For example, if the character a is at index 3 in the string, dict['a'] will be set to 3.