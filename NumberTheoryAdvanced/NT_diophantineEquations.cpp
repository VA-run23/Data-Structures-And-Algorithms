//37.1
//Important
//Extended Euclid Algorithm.
/*
Diophantine equations are polynomial equations for which we look for integer solutions.

Examples: 
3x + 7y = 1 
x^2 - y^2 = z^3

General Form: 
A linear Diophantine equation is represented as ax + by = c, where a, b, c ∈ I (integers).

Solution Condition: 
Solutions exist only if the greatest common divisor (gcd) of a and b divides c.
*/
 
//ax +by = gcd(a, b)
//gcd(x, 0) = d;
//ax + 0 = a -> x =1
//y = 0;

#include <bits/stdc++.h>
using namespace std;


struct triplet{
    int x, y, gcd;
};


triplet extendedEuclid(int a, int b){
    if(b == 0){
        triplet ans; 
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet smallAns = extendedEuclid(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}


const int N = 1e5+2, MOD = 1e9+7;
int main(){ 
    int a, b; cin>>a>>b;
    triplet ans = extendedEuclid(a, b);
    cout<<ans.gcd<<" "<<ans.x<<" "<< ans.y<<endl;
    return 0;
}