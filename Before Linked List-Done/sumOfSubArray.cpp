
//Done
//TC : O(n^2)
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr=0;

    for(int i=0; i<n;i++){
         curr=0;
        for(int j=i; j<n; j++){
        curr+=a[j];
        cout<<curr<<endl;
        }
    }
    return 0;
}
// //Input
// 5
// 1
// 2
// 3
// 4
// 5

/*
Output:
    1         // Sum of subarray [1]
    3         // Sum of subarray [1, 2]
    6         // Sum of subarray [1, 2, 3]
    10        // Sum of subarray [1, 2, 3, 4]
    15        // Sum of subarray [1, 2, 3, 4, 5]
    2         // Sum of subarray [2]
    5         // Sum of subarray [2, 3]
    9         // Sum of subarray [2, 3, 4]
    14        // Sum of subarray [2, 3, 4, 5]
    3         // Sum of subarray [3]
    7         // Sum of subarray [3, 4]
    12        // Sum of subarray [3, 4, 5]
    4         // Sum of subarray [4]
    9         // Sum of subarray [4, 5]
    5         // Sum of subarray [5]
*/