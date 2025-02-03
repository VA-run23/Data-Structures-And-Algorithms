//Done
//35.12
//My approach
//TC: 
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;cin>>n;
    int arr[n] ;
    for(int i = 0; i< n; i++){
        cin>>arr[i];
    }
    int rahul = 0; int neha = 0;
    int left  = 0, right = n-1;
    while(left <right){
        rahul = rahul +(max(arr[left], arr[right]));
        if(arr[left]> arr[right]) left++;
        else right--;
        neha = neha + (max(arr[left], arr[right]));
        if(arr[left]> arr[right]) left++;
        else right--;
    }
    cout<<"Rahul: "<<rahul<<" "<<"Neha :"<<neha<<endl;
    return 0;
}