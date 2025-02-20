#include <bits/stdc++.h>
using namespace std;

// Combinatorics
// EG: C7 = C0C6 + C1C5 + C2C4 + C3C3 + C4C2 + C5C1 + C6C0
// Catalan Numbers: Count specific combinatorial structures.
// Combinations: Count ways to select items without regard to order.
// Permutations: Count ways to arrange items in a specific order.

// TC: O(n^2)
vector<int> dp;

int catalan(int n) {
    if (n <= 1) { // as C(0) = 1 and C(1) = 1
        return 1;
    }
    if (dp[n] != -1) {
        return dp[n];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res += catalan(i) * catalan(n - i - 1);
    }
    dp[n] = res;
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    dp.assign(n + 1, -1); // Initialize the dp vector
    for (int i = 0; i < 10; i++) {
        cout << catalan(i) << " ";
    }
    cout << endl;
    return 0;
}
//OUTPUT:
// 1 1 2 5 14 42 132 429 1430 4862 
