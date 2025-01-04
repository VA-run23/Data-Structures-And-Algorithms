//Done
//TC : O(nlog(n))
#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort pairs based on their first element
bool myCompare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    int arr[] = {10, 23, 53, 15, 12, 52, 7}; // Input array
    vector<pair<int, int>> v; // Vector to store pairs of (element, index)
    
    // Populate the vector with pairs (element, index)
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++) {
        v.push_back(make_pair(arr[i], i));//pushing pair of value of elements of array with its index
    }
    
    // Sort the vector based on the first element of the pairs using the comparator function
    sort(v.begin(), v.end(), myCompare);//similar to callback function in js    
    
    // Update the original array to hold the new sorted indices
    for (int i = 0; i < v.size(); i++) {
        arr[v[i].second] = i;//now the arr is having sorted indices of the vector elements passed from the same array
    }//OR // Now arr is storing sorted indices of the original array elements
    
    // Print the updated array
    for (int i = 0; i < v.size(); i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
