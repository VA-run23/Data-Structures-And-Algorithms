//
#include <bits/stdc++.h>
using namespace std;

int smallestSubarrayWithSum(int arr[], int n, int x){
    int sum = 0, minLength = n +1;//because n is the maximum possible value as array size is n, hence n+1 is the invalid minLength val
    int start = 0, end = 0;//start and end of sliding window
    while(end < n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < minLength){
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarrayWithSum(arr, n, x);
    if(minLength == n+1){
        cout<<"No such subarray exist"<< endl;
    } else {
        cout<<"Smallest length subarray is greater than " <<x <<" is : "<< minLength << endl;
    }
    return 0;
}