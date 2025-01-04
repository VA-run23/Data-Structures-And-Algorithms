//Done 
//Refer easyBinAdd.cpp 
//the overall time complexity  ( O(n) ).
#include<bits/stdc++.h>
using namespace std;

// Function to reverse the digits of an integer
int reverse(int n){
    int ans = 0;
    while(n > 0){ 
        int lastDigit = n % 10; // Extract the last digit
        ans = ans * 10 + lastDigit; // Append the last digit to ans     
        n /= 10; // Remove the last digit from n
    }
    return ans; // Return the reversed number
}

// Function to add two binary numbers represented as integers
int addBinary(int a, int b){
    int ans = 0;
    int prevCarry = 0; // Initialize carry to 0

    // Loop while both a and b have digits left
    while(a > 0 && b > 0){
        if(a % 2 == 0 && b % 2 == 0){ // Both last digits are 0
            ans = ans * 10 + prevCarry; // Append carry to ans
            prevCarry = 0; // No carry
        } else if((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0)){ // One last digit is 1, the other is 0
            if(prevCarry == 1){
                ans = ans * 10 + 0; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else {
                ans = ans * 10 + 1; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else { // Both last digits are 1
            ans = ans * 10 + prevCarry; // Append carry to ans
            prevCarry = 1; // Set carry to 1
        }
        a /= 10; // Remove the last digit from a
        b /= 10; // Remove the last digit from b
    }

    // Process remaining digits of a
    while(a > 0){
        if(prevCarry == 1){
            if(a % 2 == 1){
                ans = ans * 10 + 0; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else {// when  a % 2  == 0
                ans = ans * 10 + 1; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else {
            ans = ans * 10 + (a % 2); // Append last digit of a to ans
        }
        a /= 10; // Remove the last digit from a
    }

    // Process remaining digits of b
    while(b > 0){
        if(prevCarry == 1){
            if(b % 2 == 1){
                ans = ans * 10 + 0; // Append 0 to ans
                prevCarry = 1; // Carry remains 1
            } else {
                ans = ans * 10 + 1; // Append 1 to ans
                prevCarry = 0; // No carry
            }
        } else {
            ans = ans * 10 + (b % 2); // Append last digit of b to ans
        }
        b /= 10; // Remove the last digit from b
    }

    // If there is a carry left, append it to ans
    if(prevCarry == 1){
        ans = ans * 10 + 1;
    }

    // Reverse the result to get the correct binary sum
    ans = reverse(ans);
    return ans; // Return the final result
}

int main(){
    int a, b;
    cin >> a >> b; // Read two binary numbers
    cout << addBinary(a, b) << endl; // Print their sum
    return 0;
}

// Input
// 1001
// 0110
// Output
// 1111

// Note: Evaluating from right to left but ans is created from right to left, so reverse function call is made

////Input
//1001
// 11011
////Output getting is: 1001
////Actual output should be: 100100
