//Done
//TC : O(6^(e-s))
////starting to end in a dice
#include <bits/stdc++.h>
using namespace std;

int countPath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1; i<=6; i++){
    count+=countPath(s+i, e);//count from base case is added to count total upto the required value
    }
    return count;
}
int main(){
    int m,n;
    cout<<"Enter the two numbers on the dice: "<<endl;
    cin>>m>>n;
    cout<<"There are "<<countPath(m,n)<<" ways";
    return 0;
}
// //Output
// Enter the two numbers on the dice: 
// 1
// 6
// There are 16 ways