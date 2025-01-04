//Done
////TC:O(2^n)
#include <bits/stdc++.h>
using namespace std;

int fibo(int n) {
    // First Fibonacci number is 0 and second is 1
    if (n == 0 || n == 1) {
        return n;
    }
    int fibonacci = fibo(n - 1) + fibo(n - 2); // returned value is stored in fibonacci variable
    return fibonacci;
}
int main() {
    int n;
    cout<<"Enter the number: "<<endl;
    cin >> n;
    cout <<"The "<<n<<"th fibanacci number is: "<< fibo(n) << endl;
    return 0;
}
////Fibonacci series
// 0
// 1
// 1
// 2
// 3
// 5
// 8
// 13
// 21
// 34
// 55
// 89
// 144
// 233
// 377
// 610
// 987
// 1597
// 2584
// 4181


////Output
// Enter the number: 
// 1
// The 1th fibanacci number is: 1