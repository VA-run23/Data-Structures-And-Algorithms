#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k) {
    if (n < k) {
        cout << "Invalid values" << endl;
        return -1;
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        res += arr[i];
    }
    int sum = res;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        res = max(res, sum);
    }
    return res;
}

bool isNumberPerfect(int n) {
    if (n <= 1) return false;
    int sum = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) {
                sum += i;
            } else {
                sum += i + n / i;
            }
        }
    }
    return sum == n;
}

int maxNumOfPerfects(int arr[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (isNumberPerfect(arr[i])) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
    return maxSum(arr, n, k);
}

int main() {
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int k = 4;
    int n = 8;
    cout << maxNumOfPerfects(arr, n, k) << endl;

    return 0;
}
////output
// 3
// as in the sliding window of 4 , maximum of 3 elements are perfect numbers