// Dutch National Flag (DNF) Sort
// Effectively sorts the array by placing all 0s to the left, all 2s to the right, and 1s in the middle
// Time Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

// Function to swap two elements in the array
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to perform DNF Sort
void dnfSort(int arr[], int n) {
    int low = 0;  // Index to place the next 0
    int mid = 0;  // Current index being examined
    int high = n - 1;  // Index to place the next 2

    // Iterate until mid index is less than or equal to high index
    while (mid <= high) {
        if (arr[mid] == 0) {
            // If current element is 0, swap it to the low index
            swap(arr, low, mid);
            // Increment both low and mid indices
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            // If the current element is 1, leave it as is
            // Simply move to the next element
            mid++;
        } else {
            // If the current element is 2, swap it to the high index
            swap(arr, mid, high);
            // Decrement the high index
            high--;
        }
    }
}

int main() {
    int arr[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Perform DNF Sort
    dnfSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;  // Print a new line for better readability

    return 0;
}
//Output
// 0 0 1 1 1 1 2 2 2 

/*
The Dutch National Flag sort (DNF sort) effectively sorts the array by placing all 0s to the left and all 2s to the right. 
The 1s automatically fall into place in the middle as the 0s and 2s are swapped.
Even if 0 is swapped from last to the mid index, we are swapping from mid index only, so it will sort the array correctly.
*/
