//Done
//TC: O(log(min(a,b)))
//Difference of the number doesnot change the GCD 
//EUCLID'S ALGORITHM
#include<iostream>
using namespace std;

int gcd(int a , int b){
   while(b!=0){
    int rem=a%b;
    a=b;
    b=rem;
   }
   return a;

}
int main(){
    int a, b;
    cin>>a>>b;
    cout<<gcd(a,b);
return 0;
}