//Done
////Since each function performs a constant number of operations, the time complexity for each function is (O(1)).

// The main function calls each of these functions a fixed number of times, so the overall time complexity of the program is also (O(1)).
#include <iostream>
#include <string>

using namespace std;

// Function to get the bit at a specific position
int getBit(int n, int pos) { // 0-based index
    // Move the 1 bit to the specified position and perform AND operation with n
    // If the result is not 0, the bit at 'pos' is 1, otherwise it's 0
    return ((n & (1 << pos)) != 0);
}

// Function to set the bit at a specific position to 1
int setBit(int n, int pos) { // 0-based index
    // Move the 1 bit to the specified position and perform OR operation with n
    // This sets the bit at 'pos' to 1
    return (n | (1 << pos));// a bit of value 1 is moving to position pos
}

// Function to clear the bit at a specific position (set it to 0)
int clearBit(int n, int pos) {
    // Create a mask with all bits set to 1 except the bit at 'pos'
    int mask = ~(1 << pos);
    // Perform AND operation with n and the mask to clear the bit at 'pos'
    return (n & mask);
}

// Function to update the bit at a specific position to a given value (0 or 1)
int updateBit(int n, int pos, int value) {//The function updateBit effectively updates the bit at a specific position in an integer to a given value (0 or 1) by:
    // Create a mask with all bits set to 1 except the bit at 'pos'
    int mask = ~(1 << pos);
    // Clear the bit at 'pos' in n
    n = n & mask;
    // Set the bit at 'pos' to the given value
    return (n | (value << pos));
}

int main() {
    // Test the getBit function: Get the bit at position 2 of the number 5 (binary 101)
    cout << getBit(5, 2) << endl; // Output: 1 (since the bit at position 2 is 1)

    // Test the setBit function: Set the bit at position 2 of the number 5 (binary 101)
    cout << setBit(5, 2) << endl; // Output: 5 (binary 101 remains 101 since the bit at position 2 is already 1)

    // Test the clearBit function: Clear the bit at position 2 of the number 5 (binary 101)
    cout << clearBit(5, 2) << endl; // Output: 1 (binary 101 becomes 001)

    // Test the updateBit function: Update the bit at position 1 of the number 5 (binary 101) to 1
    cout << updateBit(5, 1, 1) << endl; // Output: 7 (binary 101 becomes 111)
    // n: The integer whose bit you want to update.
    // pos: The position of the bit you want to update (0-based index).
    // value: The new value for the bit (either 0 or 1).

    return 0;
}
////Output
// 1
// 5
// 1
// 7