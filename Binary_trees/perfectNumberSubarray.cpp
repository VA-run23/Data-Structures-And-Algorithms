//DONE
//A perfect number is a positive integer that is equal to the sum of its proper divisors, 
//excluding the number itself. Proper divisors are the divisors of a number other than the number itself.

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
    int sum = res;//initial first k elements sum
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];// calulating rest of the array sum by adding the next element and subtracting the first element of the window
        res = max(res, sum);
    }
    return res;
}

bool isNumberPerfect(int n) {//here n is the individual element of the array
    if (n <= 1) return false;
    int sum = 1;// as 1 divides all the numbers
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {// if i is a divisor
            if (i == n / i) {
                sum += i;//add to sum if i is the square root of n
            } else {
                sum += i + n / i;// it is like 2* 3 == 3*2 property in division so adding both 2 and 3 to the sum as in case of 6
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

//EXPLANATION:
// 6:
// Proper divisors of 6: 1, 2, 3
// Sum of proper divisors: 1 + 2 + 3 = 6
// Since the sum of proper divisors equals the number itself, 6 is a perfect number.