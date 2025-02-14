//Done
//NOTWE: The merging process in merge sort happens through recurring comparisons.
//TC : O(nlogn)

// Dividing array takes O(log n) time since the array is repeatedly split in half.
//  Merging these sorted subarrays takes O(n) time.
// Since merging two halves takes linear time O(n), and there are log n levels, the total merging time is O(n log n).
#include <bits/stdc++.h> 
using namespace std;

// Function to merge two sorted subarrays
void merge(int arr[], int l, int mid, int r) {
    //The merging process in merge sort happens through recurring comparisons.
    int n1 = mid - l + 1; // Size of the first subarray
    int n2 = r - mid;     // Size of the second subarray

    // Create temporary arrays      
    int a[n1], b[n2];
    
    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a[], if any
    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of b[], if any
    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) { // arr: array to be sorted, l: start index, r: end index
    if (l < r) {
        int mid = (l + r) / 2; // Find the middle point
        mergeSort(arr, l, mid); // Sort the first half
        mergeSort(arr, mid + 1, r); // Sort the second half
        merge(arr, l, mid, r); // Merge the sorted halves, this is not recursive 
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 3, 1}; // Array to be sorted
    mergeSort(arr, 0, 5); // Sort the array from index 0 to 5
    for (int i = 0; i < 6; i++) { // Print the sorted array
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
//output
// Original: [5, 4, 3, 2, 3, 1]
// Split:    [5, 4, 3] and [2, 3, 1]
// Split:    [5, 4] [3] and [2, 3] [1]
// Split:    [5] [4] [3] [2] [3] [1]
// Merge:    [4, 5] [3] and [2, 3] [1]
// Merge:    [3, 4, 5] and [1, 2, 3]
// Merge:    [1, 2, 3, 3, 4, 5]

//Detailed explantaion:
// Original: [5, 7, 6, 2, 3, 1]
// Split:    [5, 7, 6] and [2, 3, 1]
// Split:    [5, 7] and [6] and [2, 3] and [1]
// Split:    [5] [7] [6] [2] [3] [1]
// Merge:    [5, 7] and [6] -> [5, 6, 7] // This happens at the previous recursive call where [5] and [7] are merged into [5, 7], then [5, 7] and [6] are merged into [5, 6, 7]
// Merge:    [2, 3] and [1] -> [1, 2, 3] // This happens at the previous recursive call where [2] and [3] are merged into [2, 3], then [2, 3] and [1] are merged into [1, 2, 3]
// Merge:    [5, 6, 7] and [1, 2, 3] -> [1, 2, 3, 5, 6, 7] // This happens at the first recursive call where [5, 6, 7] and [1, 2, 3] are merged into [1, 2, 3, 5, 6, 7]


