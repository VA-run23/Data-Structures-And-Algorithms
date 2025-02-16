//Done
//TC : O(n * 2^n).
///NOTE: LSB represents the first element of the array and MSB represents the last element of the array
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// Function to generate and print all subsets of the given array
void subsets(int arr[], int n) {
    // Iterate over all possible subsets (2^n subsets)
    for (int i = 0; i < (1 << n); i++) { // 1 << n means shifting 1 left by n positions, which is 2^n
        // Iterate over each element of the array
        for (int j = 0; j < n; j++) {
            // Check if the j-th bit in i is set (i.e., 1)
            // 1 << j shifts 1 to the left by j positions, creating a mask to check the j-th bit
            // i & (1 << j) performs a bitwise AND operation. If the result is non-zero, it means the j-th bit in i is set.
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << endl; // Move to the next line after printing each subset
    }
}

int main() {
    int arr[] = {1, 4, 7, 130}; // Define an array with elements
    subsets(arr, 4); // Call the function to generate and print subsets
    return 0;
}

/*
Explanation:
This code generates the subsets of the given array using the binary representation of numbers from 0 to 2^n - 1. Each binary number indicates which elements to include based on the positions of 1s in the binary digits.

Example Subsets:
For i = 0 (binary 0000): No elements included (empty subset). Output: (empty line)
For i = 1 (binary 0001): The subset includes arr[0] (i.e., 1). Output: 1
For i = 2 (binary 0010): The subset includes arr[1] (i.e., 4). Output: 4
For i = 3 (binary 0011): The subset includes arr[0] and arr[1] (i.e., 1 4). Output: 1 4
For i = 4 (binary 0100): The subset includes arr[2] (i.e., 7). Output: 7
For i = 5 (binary 0101): The subset includes arr[0] and arr[2] (i.e., 1 7). Output: 1 7
For i = 6 (binary 0110): The subset includes arr[1] and arr[2] (i.e., 4 7). Output: 4 7
For i = 7 (binary 0111): The subset includes arr[0], arr[1], and arr[2] (i.e., 1 4 7). Output: 1 4 7
For i = 8 (binary 1000): The subset includes arr[3] (i.e., 130). Output: 130
For i = 9 (binary 1001): The subset includes arr[0] and arr[3] (i.e., 1 130). Output: 1 130
For i = 10 (binary 1010): The subset includes arr[1] and arr[3] (i.e., 4 130). Output: 4 130
For i = 11 (binary 1011): The subset includes arr[0], arr[1], and arr[3] (i.e., 1 4 130). Output: 1 4 130
For i = 12 (binary 1100): The subset includes arr[2] and arr[3] (i.e., 7 130). Output: 7 130
For i = 13 (binary 1101): The subset includes arr[0], arr[2], and arr[3] (i.e., 1 7 130). Output: 1 7 130
For i = 14 (binary 1110): The subset includes arr[1], arr[2], and arr[3] (i.e., 4 7 130). Output: 4 7 130
For i = 15 (binary 1111): The subset includes all elements 1 4 7 130. Output: 1 4 7 130
Each iteration generates a subset by checking the bits of the current number i. If the bit corresponding to the position of the element in the array is set, the element is included in the subset.
*/


//OUTPUT:

// 1 
// 4 
// 1 4 
// 7 
// 1 7 
// 4 7 
// 1 4 7 
// 130 
// 1 130 
// 4 130 
// 1 4 130 
// 7 130 
// 1 7 130 
// 4 7 130 
// 1 4 7 130 
