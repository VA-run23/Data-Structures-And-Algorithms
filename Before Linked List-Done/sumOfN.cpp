
//Done
//TC : O(n)
#include<iostream>
#include<string>

using namespace std;
int  Sum(int n){
    if (n == 0) {
        return 0;
    }//// this returns from the last Sum()
    int prevSum=0;
    prevSum=prevSum+Sum(n-1);
    return n+prevSum;   
}
int main(){
    int n; 
    cin>>n;
    cout<<Sum(n)<<endl;
return 0;
}