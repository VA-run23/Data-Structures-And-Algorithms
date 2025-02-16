/////8.6
/*
1. Input Reading:
   - First, the program reads the size of the array, `n`, from the user and the elements into `arr`.
2. Prefix Sum Calculation:
   - Create `currsum` of size `n+1` to store cumulative sums; initialize `currsum[0]` to `0`.
3. Calculate prefix sums up to each index.
4. Finding Maximum Subarray Sum:
   - Initialize `maxSum` to `INT_MIN`; iterate over all subarrays using nested loops.
   - Calculate subarray sums using prefix sums and update `maxSum`.
5. Output the maximum subarray sum.
6. Time complexity: \(O(n^2)\).
*/


#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int currsum[n+1];
    currsum[0]=0;
    for(int i=1; i<=n; i++){
        currsum[i]=currsum[i-1]+arr[i-1];//as looping is starting from 1
   }
   int maxSum=INT_MIN;
   for(int i=1; i<=n;i++){
    int sum=0;
    for(int j=0; j<i; j++){
        sum=currsum[i]-currsum[j];
        maxSum=max(sum, maxSum);
    }
   }
    cout<<maxSum<<endl;
    return 0;
}
