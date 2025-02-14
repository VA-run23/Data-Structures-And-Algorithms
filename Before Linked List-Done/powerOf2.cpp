//Done
/*
The function isPowerOf2 checks if a given number is a power of 2.

Key points:
- A power of 2 has exactly one bit set to 1 in its binary representation.
- When subtracting 1 from a power of 2, all bits to the right of the most significant bit (MSB) turn to 1.
- Performing a bitwise AND operation between the number and the result of (number - 1) should yield 0 if the number is a power of 2.
*/
//TC : O(1)
#include<iostream>
#include<string>

using namespace std;
bool isPowerOf2(int n){
    return(n &&!(n&n-1));//if this value, !(n & (n - 1)) becomes !(0) which is true. Thus, isPowerOf2(16) returns true.

}

int main(){
    int n;
    cout<<"If 1 is displayed, it is a power of 2, else it's not"<<endl;
    cout<<"ENter the number: "<<endl;
    cin>>n;
    cout<<isPowerOf2(n)<<endl;
return 0;
}
// n = 16
//   10000 (16 in binary)
// - 00001 (subtract 1)
// = 01111 (15 in binary)
//  10000
// &01111
// =00000 (result is zero, so it's a power of 2)

// n = 22
//   10110 (22 in binary)
// - 00001 (subtract 1)
// = 10101 (21 in binary)
//  10110
// &10101
// =10100 (result is not zero, so it's not a power of 2)
