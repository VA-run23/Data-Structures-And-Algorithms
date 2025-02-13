// inclusion-exclusion principle
//Done
//TC : O(1)
#include<iostream>
#include<string>

using namespace std;
    int divisible(int n, int a, int b){
        int c1=n/a;
        int c2=n/b;
        int c3=n/(a*b);
        return (c1+c2-c3);
    } 

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    cout<<divisible(a,b,c);
return 0;
}
// //INPUT
// 7 2 3 
// //OUTPUT
// 4

// suppose if a is 7 and b is 2 and c is 3 and
// 7/2 = 3, this  means that there are 3 numbers upto 7 which are divisible by 2, similarly ,  
// 7/3 = 2, this means that there are 2 numbers upto 7 which are divisible by 3, similarly,
// 7(2*3) = 1, this means that there is only one number upto 7 which is divisible by 6,
// thus, there are 3+2-1 = 4, numbers upto 7 which are divisible by 2 and 3
