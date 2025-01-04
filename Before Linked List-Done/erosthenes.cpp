//Done
//TC: n*log(log n)
//this code benefits much as bth 2 and 3 are  prime numbers
//The Sieve of Eratosthenes is designed to eliminate multiples of prime numbers
#include <iostream>
using namespace std;

void primeSeive(int n) {
    int prime[5000] = {0}; // Assuming n <= 5000
    for (int i = 2; i <= n/2; i++) {//this code benefits much as bth 2 and 3 are  prime numbers
        if (prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {//marking multiples of the prime as not prime
                prime[j] = 1;////the point is here: j += i 
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (prime[i] == 0)//If prime[i] is 0, it means i is a prime number.
            cout << i << " ";//i is the prime number not prime[i]
    }
    cout << endl;
}

int main() {
    cout<<"Enter till where you want prime numbers: "<<endl;
    int n;
    cin >> n;
    primeSeive(n);
    return 0;
}
