//30.2
//for a given array and an integer X. Find the minimum subarray size for which sum > X
//time complexity:  O(n) by sliding windown approach
#include <bits/stdc++.h>
using namespace std;

smallSubMaxSum(int arr[], int val, int arrSize){
    int *start = arr;
    int winSize = INT_MAX;
    int ans = 0;
    int sum =0;
    while(start < arrSize){
        sum = sum + arr[start];
        start ++;
        if(sum > val){
            ans = min(ans, start);
        } 

    }

}

int main(){
    int arr[]= {1,2,3,4,5};
    int arrSize= 5;
    int val = 7;
    smallSubMaxSum(arr,val, arrSize);
    return 0;
}