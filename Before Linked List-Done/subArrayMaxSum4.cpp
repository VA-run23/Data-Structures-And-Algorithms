//By
//Done
//8.6
#include <bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){
    int currentSum  = 0; 
    int maxSum  INT_MIN;
    for(int i=0; i<n; i++){
        currentSum += arr[i];
        if(currentSum < 0){
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main(){
    int n; 
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int wrapSum;
    int nonWrapSum;
    nonWrapSum = kadane(arr, n);    
    int totalSum = 0;
    for(int i=0; i<n; i++){
        totalSum += arr[i];
        arr[i] = -arr[i];
    }
    wrapSum = totalSum + kadane(arr, n);//passing the array with negative elements
    cout<<max(wrapSum, nonWrapSum)<<endl;
    return 0;
}