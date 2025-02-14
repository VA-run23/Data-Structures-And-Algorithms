//The time complexity of the numberOfOnes function is O(k), where k is the number of 1s in the binary representation of the number n. This is because each iteration of the while loop reduces the number of 1s by 1. Therefore, the function runs in linear time relative to the number of 1s in the input number's binary representation.
#include <iostream>
#include <string>

using namespace std;

int numberOfOnes(int n) {
    int count = 0; 
    while (n) {
        /*
        n = n & (n - 1);: This is the core operation of the function. Let's understand what this line does:

        Binary Representation: Consider the binary representation of n. For example, if n = 13, its binary representation is 1101.

        n - 1: Subtracting 1 from n flips the rightmost 1 bit and all the bits to its right. For n = 13 (1101), n - 1 would be 12 (1100).

        n & (n - 1): The bitwise AND operation between n and n - 1 effectively removes the rightmost 1 bit from n. For n = 13 (1101) and n - 1 = 12 (1100), the result of n & (n - 1) is 8 (1000).
        */
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of ones in the binary representation of " << n << " is " << numberOfOnes(n) << endl;
    cout<<"Alternative solution: "<< __builtin_popcount(n);
    return 0;
}

// Output
// Enter a number : 15
// Number of ones in the binary representation of 15 is 4
// Alternative solution: 4

    /*
    Step-by-Step Explanation with n = 15
    
    Initialization:

    int count = 0;: Initializes the counter count to zero.
    */

        /*
        First Iteration:
        
        Current n = 1111 (binary), which is 15 in decimal.
        
        Calculation: n - 1 results in 1110 (binary), which is 14 in decimal.
        
        Bitwise AND Operation: n = n & (n - 1) results in 1111 & 1110 which is 1110 (binary), which is 14 in decimal.
        
        Increment count: count becomes 1.
        */

        
        /*
        Second Iteration:
        
        Current n = 1110 (binary), which is 14 in decimal.
        
        Calculation: n - 1 results in 1101 (binary), which is 13 in decimal.
        
        Bitwise AND Operation: n = n & (n - 1) results in 1110 & 1101 which is 1100 (binary), which is 12 in decimal.
        
        Increment count: count becomes 2.
        */
        
        /*
        Third Iteration:
        
        Current n = 1100 (binary), which is 12 in decimal.
        
        Calculation: n - 1 results in 1011 (binary), which is 11 in decimal.
        
        Bitwise AND Operation: n = n & (n - 1) results in 1100 & 1011 which is 1000 (binary), which is 8 in decimal.
        
        Increment count: count becomes 3.
        */
        
        /*
        Fourth Iteration:
        
        Current n = 1000 (binary), which is 8 in decimal.
        
        Calculation: n - 1 results in 0111 (binary), which is 7 in decimal.
        
        Bitwise AND Operation: n = n & (n - 1) results in 1000 & 0111 which is 0000 (binary), which is 0 in decimal.
        
        Increment count: count becomes 4.
        */

    /*
    Termination:

    The while loop ends because n is now 0.

    The final value of count is 4, which is the number of 1 bits in the binary representation of 15 (1111).
    */