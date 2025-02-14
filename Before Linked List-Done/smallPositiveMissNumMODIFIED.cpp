////8.5
///MODIFIED: to find the smallest missing number from the smallest number available
//TC : O(n + N), but N>n, so TC:O(N)
//for this the values must be greater than 0 and need not to be sorted as we use check array
//this can be used in inventory management systems to identify the smallest missing product ID or in database applications where you need to find the smallest missing unique identifier.
//
//
// 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n; 
    int a[n];
    int minVal= INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < minVal) {
            minVal = a[i]; 
        }
    }
   
    const int N = 1e6;
    bool check[N]; // Create a boolean array to mark the presence of elements
    for (int i = 0; i < N; i++) {
        check[i] = 0; // Initialize all values in the check array to 0
    }
    
    for (int i = 0; i < n; i++) { // Iterate over the input array
        if (a[i] > 0) {
            check[a[i]] = 1; // Set the value to 1 at the index represented by the element in the input array
        }
    
    int ans=-1;

    for(int i=minVal; i<N; i++){
        if(check[i]==0){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
return 0;
}
}
// //INPUT:
// 4 5 5 8 9

// //OUTPUT
// 6
