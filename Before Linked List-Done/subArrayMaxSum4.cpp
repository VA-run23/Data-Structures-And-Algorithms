//Kadane's algorithm for circular array.
//Done
//8.6
/*
1. Read the size of the array, `n`, and the elements of the array, `arr`.
2. Calculate `nonWrapSum`:
   - Use Kadane's algorithm to find the maximum subarray sum for the given array elements.
3. Calculate `totalSum`:
   - Compute the total sum of all elements in the array.
4. Invert the array elements:
   - Change the sign of each element in the array.
5. Calculate `wrapSum`:
   - Use Kadane's algorithm on the inverted array to find the maximum subarray sum, which corresponds to the minimum subarray sum in the original array.
   - Add this result to `totalSum` to get the maximum subarray sum considering circular wrapping.
6. Output the maximum of `wrapSum` and `nonWrapSum`:
   - Compare the non-circular maximum subarray sum and the circular maximum subarray sum and print the larger value.
*/


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