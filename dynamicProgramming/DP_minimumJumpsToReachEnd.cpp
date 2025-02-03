//Done
//35.11
//Can be solved through greedyin O(1)
//TC: O(n^2)
#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int n; 
    cin>>n;
    vector<int> arr(n, NULL);
    for(auto &i : arr){
        cin>>i;
    }
    vector<int> jumps(n, inf); //jumps to reach index is infinity
    if(arr[0] == 0){//if the first element is 0 we cant move further, so output is infinity
        cout<<inf<<" "<<endl;
    }
    jumps[0] = 0 ; // The number of jumps needed to reach the first index is 0
    for(int i  = 0; i<n ; i++){//for each index of the array
        for(int j = 0; j< i; j++){//check whether i-th index  can be reached from index j
            if(i<= (j  + arr[j] ) ){
                jumps [i] = min(jumps[i] , jumps[j ]+ 1);// Update the minimum jumps needed to reach index i
            }
        }
        //like that we are updating for all the elements of the array and storing the minimum jumps in the jumps array
    }        
    cout<<jumps[n-1];
    return 0;
}

// //Input:
// 11
// 1 3 5 8 9  2 6 7 6 8 9
// //Output:
// 3