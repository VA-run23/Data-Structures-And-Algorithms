//Done
//TC : O(p)
#include <bits/stdc++.h>
using namespace std;

int power(int n, int p){
    if(p==0){
        return 1;
    }
    int prevPower=power(n, p-1);
    return n*prevPower;
}
int main(){
    int n, p;
    cin>>n>>p;
cout<<power(n,p)<<endl;
return 0;
}
////INPUT: 
// 3 
////OUTPUT:
// 4
// 81


// //Explanation
// power(3, 4)
//    |
//    v
// power(3, 3)
//    |
//    v
// power(3, 2)
//    |
//    v
// power(3, 1)
//    |
//    v
// power(3, 0) --> returns 1
//    |
//    v
// returns 3  (from power(3, 1))
//    |
//    v
// returns 9  (from power(3, 2))
//    |
//    v
// returns 27 (from power(3, 3))
//    |
//    v
// returns 81 (from power(3, 4))
