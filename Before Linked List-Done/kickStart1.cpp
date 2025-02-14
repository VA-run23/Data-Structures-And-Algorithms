//Done
//TC : O(n)
//longest subarray with same common difference
#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n; // Input the size of the array
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Input the elements of the array
    }

    int ans = 2; // Initially, ans is set to 2 because it requires at least 2 elements in the subarray to find a common difference
    int pd = a[1] - a[0]; // Initial common difference (pd) between the first two elements
    int j = 2; // Counter variable (loop variable) initialized to 2 (third element) since the difference between the first two elements is already calculated (pd)
    int curr = 2; // curr is the length of the current subarray with the same common difference; it starts at 2

    while (j < n) { // Loop through the array starting from the third element
        if (pd == a[j] - a[j-1]) { // Check if the current difference is equal to the previous common difference (pd)
            curr++; // If true, increment the length of the current subarray
        } else { // If the streak of the same difference is broken, start a new streak
            pd = a[j] - a[j-1]; // Update pd to the new difference
            curr = 2; // Reset the length of the current subarray to 2
        }
        ans = max(ans, curr); // Update ans to the maximum length of subarray found so far
        j++;
    }

    cout << ans; // Output the length of the longest subarray with the same common difference
    return 0;
}
////INput
//11 elements
// 22
// 33
// 44
// 44
// 55
// 44
// 33
// 22
// 11
// 0
// 1
////Output
// 6