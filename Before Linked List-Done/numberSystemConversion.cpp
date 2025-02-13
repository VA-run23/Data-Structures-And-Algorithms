//DONE
#include<bits/stdc++.h>
using namespace std;
//Detailed explanation at last

int binaryToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans =ans+ x*y;
        x*=2;
        n/=10;
    }
    return ans;
}

int octalToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans =ans+ x*y;
        x*=8;
        n/=10;
    }
    return ans;//returning decimal value 
}

int hexadecimaltoDecimal (string n){
    int ans=0;
    int x=1;
    int s=n.size();
    for(int i=s-1; i>=0; i--){
        if(n[i]>='0' &n[i]<='9'){
            ans+=x*(n[i]-'0');
        }else if(n[i]>='A' && n[i]<='F'){
            ans+=x*(n[i]-'A'+10);
        }
        x*=16;
    }
    return ans;//returning decimal value 
}

int decimalToBinary(int n){

    int x=1;
    int ans=0;
    while(x<=n){
        x*=2;
    }
    x/=2;

    while(x>0){
        int lastDigit=n/x;
        n-=lastDigit*x;
        x/=2;
        ans=ans*10+lastDigit;
    }
    return ans;
}

int decimalToOctal(int n){
    int x=1;
    int ans=0;
    while(x<=n)
        x*=8;
    x/=8;

    while(x>0){
        int lastDigit=n/x;
        n-=lastDigit*x;
        x/=8 ;
        ans=ans*10+lastDigit;
    }
    return ans;
}

string decimalToHexadecimal(int n){
    int x=1;
    string ans= "";
    while(x<=n)
        x*=16;
    x/=16;
    while(x>0){
        int lastDigit=n/x;
        n-=lastDigit*x;
        x/=16;
        if(lastDigit<=9)
            ans=ans+to_string(lastDigit);
        else{
            char c='A'+lastDigit-10;
            ans.push_back(c);
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;

    string n_hex;
    cin >> n_hex;

    cout << "Binary to Decimal: " << binaryToDecimal(n) << endl;
    cout << "Octal to Decimal: " << octalToDecimal(n) << endl;
    cout << "Hexadecimal to Decimal: " << hexadecimaltoDecimal(n_hex) << endl;

    cout << "Decimal to Binary: " << decimalToBinary(n) << endl;
    cout << "Decimal to Octal: " << decimalToOctal(n) << endl;
    cout << "Decimal to Hexadecimal: " << decimalToHexadecimal(n) << endl;

    return 0;
}
// //Input
// 1000
// AA6
// //Output
// Binary to Decimal: 8
// Octal to Decimal: 512
// Hexadecimal to Decimal: 2726
// Decimal to Binary: 1111101000
// Decimal to Octal: 1750
// Decimal to Hexadecimal: 3E8



/*
Step-by-Step Explanation
Initial Setup:
n = 20
x = 1
ans = 0

Finding the Highest Power of 2 Less Than or Equal to 20:
while (x <= n) {
    x *= 2;
}
x /= 2;

Iteration 1: x = 1 (Initially)
Iteration 2: x = 2 (1 * 2)
Iteration 3: x = 4 (2 * 2)
Iteration 4: x = 8 (4 * 2)
Iteration 5: x = 16 (8 * 2)
Iteration 6: x = 32 (16 * 2, now x > 20, so exit loop)
After exiting the loop, x /= 2 results in x = 16.

Converting to Binary:
while (x > 0) {
    int lastDigit = n / x;
    n -= lastDigit * x;
    x /= 2;
    ans = ans * 10 + lastDigit;
}

Iteration 1:
lastDigit = 20 / 16 = 1
n = 20 - 1 * 16 = 4
x = 16 / 2 = 8
ans = 0 * 10 + 1 = 1

Iteration 2:
lastDigit = 4 / 8 = 0
n = 4
x = 8 / 2 = 4
ans = 1 * 10 + 0 = 10

Iteration 3:
lastDigit = 4 / 4 = 1
n = 4 - 1 * 4 = 0
x = 4 / 2 = 2
ans = 10 * 10 + 1 = 101

Iteration 4:
lastDigit = 0 / 2 = 0
n = 0
x = 2 / 2 = 1
ans = 101 * 10 + 0 = 1010

Iteration 5:
lastDigit = 0 / 1 = 0
n = 0
x = 1 / 2 = 0
ans = 1010 * 10 + 0 = 10100

Final Result:
The binary representation of 20 is 10100.
*/
