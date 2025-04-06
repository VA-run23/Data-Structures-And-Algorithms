//DOne
//TC : O(n)
//First and last occurance of a character/int through recursion
///NOTE:
// The first occurrence is found by checking the current index first and then moving to the next index.
// The last occurrence is found until the recursive call reached the base case and then checks the current index.

#include <bits/stdc++.h>
using namespace std;
int firstOcc(int arr[], int n, int i, int key){////first checking for i then calling for i+1
    if(i==n){//end condition
        return -1;
    }
    if(arr[i]==key){//first checking for i  then calling function with i+1
        return i;
    }
    return firstOcc(arr, n, i+1, key);
}
int lastOcc(int arr[], int n, int i, int key){////first checking for i+1 then calling for i
    if(i==n){
        return -1;
    }
    int restArray= lastOcc(arr, n , i+1, key );//first calling function with i+1 then checking  for arr[i]==key
    if(restArray!=-1){
        return restArray;//NOTE !
    }
    if(arr[i]==key){
        return i;
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,2,5,2,6,5,2};
    cout<<firstOcc(arr,9,0, 2)<<endl;
    cout<<lastOcc(arr,9,0, 2)<<endl;
return 0;
}
// //Output
// 1
// 8


///Recursion Flow
// The function keeps calling itself with the next index until it reaches the end of the array.
// Once it reaches the end, it starts returning back up the call stack, checking each element from the end towards the beginning.
// This way, it effectively finds the last occurrence of the key in the array.

/*
if once -1 is returned it will be propagated to all recursive calls .
But if in between it finds the key, it will propagate the required index.
*/
