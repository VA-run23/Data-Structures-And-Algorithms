//Done
//TC : O(n * 2^n).
#include<stdio.h>
#include<iostream>
#include<string>


using namespace std;

void subsets(int arr[], int n){//1 << 4 means that shift left the binary rep of 1 by 4 bits: 0001 changes to 10000
    for(int i=0; i<(1<<n);i++){//This loop runs from 0 to 2^n - 1. Each value of i represents a unique subset.
        for(int j=0; j<n; j++){//This loop iterates through each element of the array
            if(i&(i<<j)){
//                 This checks if the j-th bit in i is set (i.e., 1).
// 1 << j shifts 1 to the left by j positions, creating a mask to check the j-th bit.
// i & (1 << j) performs a bitwise AND operation. If the result is non-zero, it means the j-th bit in i is set.
                cout<<arr[j]<<" ";
            }
        }cout<<endl;
    }
}

int main(){
    int arr[]={1,4, 7, 130};
    subsets(arr,4);
return 0;
}

// This code generates the subsets of the given array using the binary representation of numbers from 0 to 2^n - 1.
//  Each binary number indicates which elements to include based on the positions of 1s in the binary digits.
// //Output

// 1 
// 1 
// 1 4 
// 1 
// 1 7 
// 1 4 
// 1 4 7 
// 1 
// 1 130 
// 1 7 
// 1 4 7 130 
// 1 4 
// 1 4 7 130 
// 1 4 7 
// 1 4 7 130 