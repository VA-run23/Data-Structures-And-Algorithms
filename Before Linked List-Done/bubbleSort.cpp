//Done
///8.3.2
//TC: Worst-case and Average-case O(n^2)
//best case O(n)
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int counter = 1;
    while (counter < n) {
        for (int i = 0; i < n - counter; i++) {//as the element at the last will be in sorted form so no need to traverse it again in each iteration
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// ////input
// 5
// 7
// 3
// 46
// 3
// 2
// //output
// 2 3 3 7 46
