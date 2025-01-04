//The time complexity of the numberOfOnes function is O(k), where k is the number of 1s in the binary representation of the number n. This is because each iteration of the while loop reduces the number of 1s by 1. Therefore, the function runs in linear time relative to the number of 1s in the input number's binary representation.
#include <iostream>
#include <string>

using namespace std;

int numberOfOnes(int n) {
    int count = 0; 
    while (n) {
        n = n & (n - 1);//using bitwise and operator and, we are trying to remove the last 1 from the binary representation , until  the complete binary representation of the given number becomes 0s
        count++;
    }
    return count;
}

int main() {
    int n;
    cout<<"Enter a number : ";
    cin>>n;
    cout <<"Number of ones in the binary representation of "<<n<<" is "<< numberOfOnes(n) << endl;
    return 0;
}
////Output
// Enter a number : 15
// Number of ones in the binary representation of 15is 4