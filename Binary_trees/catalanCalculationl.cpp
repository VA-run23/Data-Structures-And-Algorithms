//28.6.1
#include <bits/stdc++.h>
using namespace std;
// Combinatorics
// EG: C7= C0C6 + C1C5 + C2C4 + C3C3 + C4C2 + C5C1 + C6C0
//  Catalan Numbers: Count specific combinatorial structures.
//  Combinations: Count ways to select items without regard to order.
//  Permutations: Count ways to arrange items in a specific order.


//TC: (4^n / n^0.5)

int catalan(int n){
    if(n<=1){//as c(0) = 1  and c(1) = 1
        return 1;
    }
    int res = 0;
    for(int i=0; i<n; i++){
        res+=catalan(i) * catalan(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0; i<10; i++){
        cout<<catalan(i)<<" ";
    }
    cout<<endl;

    return 0;
}