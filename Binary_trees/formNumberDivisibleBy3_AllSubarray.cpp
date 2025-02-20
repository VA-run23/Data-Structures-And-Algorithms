#include <bits/stdc++.h>
using namespace std;

// Function to compute all subarrays of size k whose elements form a number divisible by 3
void computeNumberFromSubarray(vector<int> arr, int k) {
    vector<pair<int, int>> results; // To store the starting and ending indices of the subarrays
    int sum = 0; // To store the sum of the current subarray

    // Calculate the sum of the first subarray of size k
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }

    // Check if the sum of the first subarray is divisible by 3
    if (sum % 3 == 0) {
        results.push_back(make_pair(0, k - 1)); // Store the start and end indices of the subarray
    }

    // Use a sliding window technique to check the rest of the subarrays
    for (int j = k; j < arr.size(); j++) {
        sum = sum + arr[j] - arr[j - k]; // Update the sum by adding the next element and removing the first element of the previous subarray
        if (sum % 3 == 0) {
            results.push_back(make_pair(j - k + 1, j)); // Store the start and end indices of the subarray
        }
    }

    // Print the results
    if (results.empty()) {
        cout << "No such subarray exists" << endl;
    } else {
        for (const auto& ans : results) {
            for (int i = ans.first; i <= ans.second; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> arr = {84, 23, 45, 12, 56, 82}; // Input array
    int k = 3; // Size of the subarray[Not subsequence]
    computeNumberFromSubarray(arr, k); // Call the function
    return 0;
}
