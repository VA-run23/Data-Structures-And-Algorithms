////Namaste
#include<iostream>
#include<string>

using namespace std;

void primeFactor(int n){
    int spf[100] = {0}; // Array to store the smallest prime factor for every number up to n

    // Initialize the spf array
    for (int i = 2; i <= n; i++){
        spf[i] = i;
    }

    // Use the Sieve of Eratosthenes to fill spf array with smallest prime factors
    for(int i = 2; i <= n; i++){
        if(spf[i] == i){ // If i is a prime number
            for(int j = i * i; j <= n; j += i){ // Mark the multiples of i as i as it is its prime factor
                if(spf[j] == j){
                    spf[j] = i; // Set spf[j] to the smallest prime factor i
                }
            }
        }
    }

    // Print the prime factors of n
    while(n != 1){
        cout << spf[n] << " ";
        n = n / spf[n]; 
    }
}

int main(){
    int n;
    cin >> n;
    primeFactor(n);
    return 0;
}

/* 
Example:
n = 50

Execution for Input 50:
Initialize SPF Array:

spf[2] = 2, spf[3] = 3, spf[4] = 4, ..., spf[50] = 50

Sieve of Eratosthenes:

For i = 2, mark multiples of 2: spf[4] = 2, spf[6] = 2, spf[8] = 2, ..., spf[50] = 2
For i = 3, mark multiples of 3: spf[9] = 3, spf[12] = 3, ..., spf[48] = 3
For i = 5, mark multiples of 5: spf[25] = 5, spf[30] = 5, spf[35] = 5, ..., spf[50] = 5
Continue for other primes up to 50.

Printing Prime Factors of 50:

50: spf[50] = 5, print 5, n = 50 / 5 = 10
10: spf[10] = 2, print 2, n = 10 / 2 = 5
5: spf[5] = 5, print 5, n = 5 / 5 = 1
End loop as n = 1.

Output: 5 2 5
*/