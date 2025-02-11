#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
string reverseString(string s){
    reverse(s.begin(), s.end());
    return s;
}

// Function to add two binary numbers represented as integers
string addBinary(int a, int b){
    string ans = "";
    int prevCarry = 0; // Initialize carry to 0

    // Loop while both a and b have digits left
    while(a > 0 && b > 0){
        if(a % 2 == 0 && b % 2 == 0){ // Both last digits are 0
            ans = to_string(prevCarry) + ans; // Append carry to ans
            prevCarry = 0; // No carry
        } else if((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)){ // One last digit is 1, the other is 0
            if(prevCarry == 1){
                ans = "0" + ans; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else {
                ans = "1" + ans; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else { // Both last digits are 1
            ans = to_string(prevCarry) + ans; // Append carry to ans
            prevCarry = 1; // Set carry to 1
        }
        a /= 10; // Remove the last digit from a
        b /= 10; // Remove the last digit from b
    }

    // Process remaining digits of a
    while(a > 0){
        if(prevCarry == 1){
            if(a % 2 == 1){
                ans = "0" + ans; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else { // when a % 2 == 0
                ans = "1" + ans; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else {
            ans = to_string(a % 2) + ans; // Append last digit of a to ans
        }
        a /= 10; // Remove the last digit from a
    }

    // Process remaining digits of b
    while(b > 0){
        if(prevCarry == 1){
            if(b % 2 == 1){
                ans = "0" + ans; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else {
                ans = "1" + ans; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else {
            ans = to_string(b % 2) + ans; // Append last digit of b to ans
        }
        b /= 10; // Remove the last digit from b
    }

    // If there is a carry left, append it to ans
    if(prevCarry == 1){
        ans = "1" + ans;
    }

    return ans; // Return the final result as a string
}

int main(){
    int a, b;
    cin >> a >> b; // Read two binary numbers
    cout << addBinary(a, b) << endl; // Print their sum as a string
    return 0;
}

// Input
// 1001
// 0110
// Output
// 1111


// //INput
// 1001
// 11011
// //Output
// 100100
//Fixed the problem by converting answer to string