//Done
///NOTE: We are creating the number by comparing with their setbits
// TC: O(n)
#include <iostream>
#include <string>
using namespace std;

bool getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos) {
    return (n | (1 << pos));
}

int unique(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < 64; i++) {//this is looping for new array////i<64 , considering 64 bit number
        int sum = 0;
        for (int j = 0; j < n; j++) {//this is looping for input array
            if (getBit(arr[j], i)){// checks if the i-th bit of arr[j] is set (i.e., is 1) for all elements of the input array and the sum is re-calculated for each itereation of i
                sum++;
            }
        }
        if (sum % 3 != 0) {//this checks if the number of elements having setbit is a multiple of 3, then those numbers are not unique, this checking is done for each bit position
            result = setBit(result, i);//if at any bit position is having number of elements which is not a multiple of 3 we are setting it's bit position to 1
        }
    }
    return result;
}

int main() {
    int arr[] = {1, 1, 1, 2, 2, 2, 3, 4, 3, 3};//For this code to work properly other than unique element, all elements must appear thrice
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The unique element is: " << unique(arr, n) << endl;
    return 0;
}
