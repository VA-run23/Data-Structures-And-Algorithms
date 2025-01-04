#include <bits/stdc++.h>
using namespace std;

// Function to calculate the number of ways to pair up or leave single n friends
int friendsPairing(int n) {
    // Base cases:
    // If there are 0, 1, or 2 friends, the number of ways to pair them up or leave them single is n itself
    // For n = 0, there are 0 ways (obviously, no friends to pair up!)
    // For n = 1, there is 1 way (the friend remains single)
    // For n = 2, there are 2 ways: (1) both remain single, (2) they pair up
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    // Recursive case:
    // If the nth friend remains single, we count the ways to pair up (n-1) friends
    // If the nth friend pairs up with any of the (n-1) friends, we count the ways to pair up (n-2) friends
    // and multiply by (n-1) because there are (n-1) choices for pairing
    return friendsPairing(n - 1) + friendsPairing(n - 2) * (n - 1);
}

int main() {
    int n;
    cin >> n; // Input the number of friends
    cout << friendsPairing(n); // Output the number of ways to pair up or leave single n friends
    return 0;
}
/////NOTE
// For example if number of friends is two the number of ways is 2 
// 1. both friends remain single
// 2.Both get paired up