//Done
////8.5
//code for first repeating element
//code which give the position of the first repeating element
//time complexity = O(n)
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int N = 100000;//N = 1e6 + 2; as this consumes a lot of memory
///if value greater than N is given for array element , it gives error
    int idx[N];
    for (int i = 0; i < N; i++) {
        idx[i] = -1;
    }

    int minidx = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (idx[a[i]] != -1) {
            minidx = min(minidx, idx[a[i]]);// If the element a[i] has been seen before (in that condition ,  idx[a[i]] is not -1), update minidx with the minimum of minidx and idx[a[i]]
        } else {
            idx[a[i]] = i;
        }
    }

    if (minidx == INT_MAX) {
        cout << "-1" << endl;
    } else {
        cout << minidx + 1 << endl;//1-based index of the first repeating element
    }
    return 0;
}


// //Input
// 5//n = 5
// 7
// 8
// 7
// 4
// 5
// //Output
// 1

//input
// 5 //n = 5
// 2
// 1
// 1
// 2
// 4
//for this input , first minidx will be having the value 0 as 1 is repeated twice first then 2 is repeated, so min(minidx, idx[a[i]]) helps it to get the first repeated element's position
//Output
//1