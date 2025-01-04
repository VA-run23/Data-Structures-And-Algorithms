////TC : O(n)

#include <bits/stdc++.h>
using namespace std;

int addBinary(int a, int b) {
    int ans = 0, carry = 0, place = 1;
    while (a > 0 || b > 0 || carry > 0) {
        int sum = (a % 10) + (b % 10) + carry;
        carry = sum / 2;
        ans += (sum % 2) * place;
        place *= 10;
        a /= 10;
        b /= 10;
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << addBinary(a, b) << endl;
    return 0;
}
