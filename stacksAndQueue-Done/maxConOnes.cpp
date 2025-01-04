//Done
//TC: 
//
//In this program, we are not physically changing the value 0 by 1.
//In this program we are getting max number of continious 1 with an exception of that there may be k number of continious zeros zeoros considering them as 1
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n; // Input the size of the array
    int k; 
    cin >> k; // Input the maximum number of zeros allowed in the subarray
    vector<int> a(n);
    
    for(auto &i: a) {
        cin >> i; // Input the elements of the array
    }
    
    int zcount = 0, i = 0, ans = 0; // Initialize zero count, start index, and answer
    
    for(int j = 0; j < n; j++) { // Loop through each element in the array
        if(a[j] == 0) // If the current element is zero
            zcount++; // Increment the zero count
        
        while(zcount > k) { // While the zero count exceeds the allowed maximum
            if(a[i] == 0) { // If the element at the start index is zero
                zcount--; // Decrement the zero count
            }
            i++; // Move the start index to the right,
        }
        // The zero count is now <= k
        ans = max(ans, j - i + 1); // Update the answer with the maximum length found
    }
    cout << ans; // Output the length of the longest subarray with at most k zeros
    return 0;
}
// Zero Count and Start Index (i): The relationship between zcount and i is crucial because:

// Whenever zcount exceeds k, the program increments i to shrink the window from the left until zcount is less than or equal to k.

// This ensures that the subarray from i to j always has at most k zeros.

// The line ans = max(ans, j - i + 1) calculates the length of the current valid subarray and updates ans if this length is the largest found so far.


// //INput
// 15
// 3
// 1
// 1
// 1
// 1
// 1
// 1
// 1
// 0
// 0
// 0
// 0
// 1
// 1
// 1
// 1
// //Output
// 10