//Done
//TC : O(n)
//Prints only two unique numbers

#include<iostream>
using namespace std;

int setBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);//returns 0 if it is 0 , else 1
}

void unique(int arr[], int n) {
    int xorsum = 0;
    for (int i = 0; i < n; i++) {
        xorsum = xorsum ^ arr[i];// xorsum is the XOR of the two unique numbers because XOR of two same numbers is 0.
    }// After this loop, xorsum is the XOR of the two unique numbers in binary representation form (because duplicates cancel out)  

    int tempxor = xorsum, setbit = 0, pos = 0;
    while (setbit != 1) {
        setbit = xorsum & 1;  // Check the least significant bit.
        pos++;                // Move to the next bit position.////this position is regarding the position of the first set bit (obviously from right)
        xorsum = xorsum >> 1; // Right shift to check the next bit.
    }
    // This loop identifies the position of the first set bit in xorsum.


    int newxor = 0;
    for (int i = 0; i < n; i++) {////This part calculates the XOR of all numbers in the array that have the set bit at the found position. The result (newxor) will be one of the unique numbers.
        if (setBit(arr[i], pos - 1)) {
            newxor = newxor ^ arr[i];
        }
    }

    cout << newxor << endl;//For this input this is printing 7
    cout << (tempxor ^ newxor) << endl;//For this input this is printing 4
}

int main() {
    int arr[] = {1, 2, 3, 4,7, 3, 2, 1};// This function works only if any number appears exactly twice, and exactly two numbers appear once.
    unique(arr, 8);
    return 0;
}



////Explaination
// xorsum(initially 0) have xor of each element with next element, such that diplicates will get eleminated and we will be having binary representation of xor or two unique elements,
// tempxor = xorsum,setbit=0, pos=0;
// finding position of least(first from right) setBit, while finding pos++
// find out element having setbit at pos-1 position, xor those element with newxor(initialised with 0)
// then newxor gives one of the unique element, and xor it with tempxor(a copy of xorsum) which gives another unique element
