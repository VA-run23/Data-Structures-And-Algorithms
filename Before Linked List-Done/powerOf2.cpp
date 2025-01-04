
//Done
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
