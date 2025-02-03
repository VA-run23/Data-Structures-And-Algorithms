//35.19

// A subsequence is bitionic if it is:
// 1. First strictly increasing and then strictly decreasing
// 2. Entirely increasing
// 3. Entirely decreasing
//TC: O(n^2)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n =  8;
    vector< int> a ={1, 11, 2, 10, 4, 5, 2, 1};
    vector<int> forward(n,1), backward(n, 1);
    for(int i = 0; i<n; i++){
        for(int j  = 0; j<i; j++){
            if(a[i] > a[j]){
                forward[i] = max(forward[i] , 1 + forward[j]);
            }
        }
    }
    for(int i = n-1; i>= 0; i--){
        for(int j = n-1; j>i; j--){
            if(a[i] > a[j]){
                backward[i] = max(backward[i], backward[j] +1);
            }
        }

    }
    int ans = 0;
    for(int i  = 0; i<n; i++){
        ans = max(ans, forward[i] + backward[i]  -1);//subtracting 1 as i-th element have been included in both the cases
    }
    cout<<ans<<endl;
    return 0;
}
// //Input 
// 8
// 1 11 2 10 4 5 2 1 
// //Output
// 6

//explanation
// 1 2 4 5 2 1 
// 1 2 10 5 2 1
// //Both are valid