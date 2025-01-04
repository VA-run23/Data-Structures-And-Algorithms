//Done
// A peak element in an array is an element that is greater than or equal to its neighbors
#include <bits/stdc++.h>
using namespace std;

// Corner case 1: For ascending and descending order, the last element is a peak
// Corner case 2: For all same elements, each element is a peak

int findPeakElement(int arr[], int low, int high, int n) {
    int mid = low + (high - low) / 2; // This ensures the mid value is within the integer range

    // Check if the mid element is a peak
    if(mid == 0 || arr[mid - 1] <= arr[mid] && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
        return mid;
    }
    // If the left neighbor is greater, there is a potential peak on the left side
    else if(mid > 0 && arr[mid - 1] > arr[mid]) {
        return findPeakElement(arr, low, mid - 1, n);
    }
    // Otherwise, there is a potential peak on the right side
    else {
        return findPeakElement(arr, mid + 1, high, n);
    }
}

int main() {
    int arr[] = {0, 6, 8, 5, 89, 9};
    int n = 6;
    cout << "Peak element index: " << findPeakElement(arr, 0, n - 1, n) << endl;

    return 0;
}
