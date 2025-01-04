
//Done
//TC : O(2^n)
#include <bits/stdc++.h>
using namespace std;
////source to helper to destination 
void towerOfHanoi(int n, char src, char dest, char helper){
    if(n==0){
        return ;
    }////THE MAIN LOGIC IS :  BIGGER THING CANNOT BE ON THE SMALLER ONE.
    towerOfHanoi(n-1, src, helper, dest);
    cout<<"Move from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1, helper, dest, src);

    
}
int main(){
    int n;
    cout<<"ENter the number of of disks"<<endl;
    cin>>n;
    towerOfHanoi(n, 'A', 'C', 'B');////A, B and C are the towers on which discs are placed
    //Initially a is the source , B is the helper and C is the destination 
return 0;
}