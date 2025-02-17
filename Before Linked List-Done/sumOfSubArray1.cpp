//DONE 
////8.5
//TC: O(n)
///NOTE: Output is 1 based index
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n; // Read the number of elements in the array
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; // Read the elements into the array
    }

    int s;
    cin >> s; // Read the sum we want to find in a subarray

    int i = 0, j = 0;     // Initialize pointers for the start and end of the current subarray
    int st = -1, en = -1; // Variables to store the start and end indices of the found subarray
    int sum = 0;          // Variable to store the current sum of the subarray

    // Expand the window until the sum is less than or equal to s
    while (j < n && sum + a[j] <= s)
    {
        sum += a[j]; // Add the current element to the sum
        j++;         // Expand the window by moving the end pointer to the right
    }

    // If the sum of the current subarray is exactly equal to s, print the indices
    if (sum == s)
    {
        cout << i + 1 << " " << j << endl; // 1-based indexing for the result
        return 0;                          // Exit the program
    }

    // Continue to search for the subarray with sum equal to s
    while (j < n)
    {
        sum += a[j]; // Add the current element to the sum
        // Shrink the window from the left until the sum is less than or equal to s
        while (sum > s)
        {
            sum -= a[i]; // Subtract the element at the start of the window
            i++;         // Move the start pointer to the right
        }
        // If the sum of the current subarray is exactly equal to s, record the indices
        if (sum == s)
        {
            st = i + 1; // Start index (1-based)
            en = j + 1; // End index (1-based)
            break;      // Exit the loop since we found the subarray
        }
        j++; // Move the end pointer to the right to expand the window
    }

    cout << st << " " << en << endl; // Print the start and end indices of the subarray
    return 0;
}
//Returns -1 -1 for an impossible value

// //INPUT:
// 7
// 1 2 3 4 5 6 7 
// 35
// //OUTPUT
// -1 -1

// ///INPUT:
// 7
// // 1 2 3 4 5 6 7 
// 25

// //OUTPUT:
// 3 7
//Which means from index 3 to 7 , the sum of elements in the array make 25
