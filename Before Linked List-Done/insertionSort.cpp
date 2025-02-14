//Done
//TC : O(n^2)
#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array: "<<endl;
    cin >> n; // Input the size of the array
    int arr[n]; // Declare an array of size n
    cout<<"Enter the array elements:"<<endl;
    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Insertion sort algorithm
    //Sorted part : 0 to i-1
    for(int i = 1; i < n; i++) {
        int current = arr[i]; // The current element to be inserted
        int prev = i - 1; // The index of the last element of the sorted part of the array, that is previous of the current element

        // This loop shifts elements to create space for the current element
        // Shift elements of the sorted part to the right to create space for the current element
        while (arr[prev] > current && prev >= 0) {
            // If the current element is less than the compared element in the sorted part,
            // shift the compared element to the right until the correct position is found
            arr[prev + 1] = arr[prev];
            prev--;
        }

// Place the current element in its correct position
arr[prev + 1] = current;

    }

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; // Print newline for better readability
    return 0;
}
// Initial: [5, 2, 9, 1, 5, 6]
// Step 1: [2, 5, 9, 1, 5, 6]
// Step 2: [2, 5, 9, 1, 5, 6]
// Step 3: [1, 2, 5, 9, 5, 6]
// Step 4: [1, 2, 5, 5, 9, 6]
// Step 5: [1, 2, 5, 5, 6, 9]
