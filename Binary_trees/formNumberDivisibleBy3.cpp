//Done
//For a given array and an integet K, check if any subarray[Not subsequence] of size K exists in the array such that elements in the subbarray form a number divisible by 3 (K)
//THis stores only the last subaaray whose sum is divisible by 3

#include <bits/stdc++.h>
using namespace std;

// Function to compute a subarray of size k whose elements form a number divisible by 3
void computeNumberFromSubarray(vector<int> arr, int k) {
    pair<int, int> ans; // To store the starting and ending indices of the subarray
    int sum = 0; // To store the sum of the current subarray

    // Calculate the sum of the first subarray of size k
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    bool found = false; // Flag to indicate if a valid subarray is found

    // Check if the sum of the first subarray is divisible by 3
    if (sum % 3 == 0) {
        ans = make_pair(0, k - 1); // Store the start and end indices of the subarray
        found = true; // Set the flag to true
    }

    // Use a sliding window technique to check the rest of the subarrays
    for (int j = k; j < arr.size(); j++) {
        if (found) {
            break; // If a valid subarray is found, exit the loop
        }
        sum = sum + arr[j] - arr[j - k]; // Update the sum by adding the next element and removing the first element of the previous subarray
        if (sum % 3 == 0) {
            ans = make_pair(j - k + 1, j); // Store the start and end  indices of the subarray
            found = true; // Set the flag to true
        }
    }

    // If no valid subarray is found, set the answer to (-1, 0)
    if (!found) {
        ans = make_pair(-1, 0);
    }

    // Print the result
    if (ans.first == -1) {
        cout << "No such subarray exists" << endl;
    } else {
        for (int i = ans.first; i <= ans.second; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {84, 23, 45, 12, 56, 82}; // Input array
    int k = 3; // Size of the subarray[Not subsequence]
    computeNumberFromSubarray(arr, k); // Call the function
    return 0;
}


// Output
// 12 56 82 