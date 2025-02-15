// With memoization, the time complexity has improved to O(n × 6) = O(6n), where n = e − s
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;

int countPath(int s, int e) {
    if (s == e) {
        return 1;
    }
    if (s > e) {
        return 0;
    }
    if (memo.find(s) != memo.end()) {
        return memo[s];
    }
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        count += countPath(s + i, e);
    }
    memo[s] = count;
    return count;
}

int main() {
    int m, n;
    cout << "Enter the two numbers on the dice: " << endl;
    cin >> m >> n;
    cout << "There are " << countPath(m, n) << " ways";
    return 0;
}
