//Done
//TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==0 || n == 1){//This is more efficient other if condition as : if(n==0 ) 
        return 1;
    }
    int fact=factorial(n-1); //the recursive factorial value is returned to fact variable
    return n*fact; 
}
int main(){
    int n;
    cin>>n;
    cout<<factorial(n)<<endl;
return 0;
}