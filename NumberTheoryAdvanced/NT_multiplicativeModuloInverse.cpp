//37.2
//(A * B) % m = 1; Find B where A and m will be given 
//Multiplicative modulo Inverse exists only if A and m are co prime: That is gcc(A,m) = 1

// Multiplicative Modulo Inverse
// 
// A * B ≡ 1 (mod m)
//
// Explanation:
// We are looking for a number B such that when it is multiplied by A, 
// the result is congruent to 1 modulo m.
//
// To simplify the statement: (A * B - 1) ≡ 0 (mod m)
//
// Which can be rearranged to: A * B - 1 = mq
//
// Where q is an integer.
//
// This can be rewritten as: A * B + mQ = 1
//
// Essentially, we need to find integers B and Q that satisfy this equation.
// Finding such B is critical in number theory and cryptography.

// a % m = (a + m) % m
#include <bits/stdc++.h>
using namespace std;
//ac +by = gcd(a, b) by Extended Euclids Algo 

struct triplet{
    int x, y, gcd;

};

triplet extendedEuclid(int a, int b){
    if(b == 0){
        triplet ans;
        ans.x  =1;
        ans.y =0;
        ans.gcd = a;
        return ans;
    }

    triplet smallAns =  extendedEuclid(b, a%b);
    triplet ans;
    ans.x = smallAns.y;
    ans.gcd = smallAns.gcd;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}




int multiplicativeModuloinverse(int a, int m){
// a % m = (a + m) % m

    triplet temp = extendedEuclid(a, m);
    return temp.x;

}


// int multiplicativeModuloinverse(int a, int m) {
//     triplet result = extendedEuclid(a, m);
//     if (result.gcd != 1) {
//         // Multiplicative inverse doesn't exist if gcd(a, m) != 1
//         return -1;
//     } else {
//         // Ensure the result is positive
//         return (result.x % m + m) % m;
//     }
// }




int main(){
    int a, m;
    cin>> a >>m;
    cout<<multiplicativeModuloinverse( a, m)<<endl;

    return 0;
}