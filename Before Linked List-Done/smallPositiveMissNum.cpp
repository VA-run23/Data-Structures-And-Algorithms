////8.5
//Done
//TC : O(n + N), but N>n, so TC:O(N)
//for this the values must be greater than 0 and need not to be sorted as we use check array
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n; 
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    
    const int N = 1e6;
    bool check[N]; // Create a boolean array to mark the presence of elements
    for (int i = 0; i < N; i++) {
        check[i] = 0; // Initialize all values in the check array to 0
    }
    
    for (int i = 0; i < n; i++) { // Iterate over the input array
        if (a[i] > 0) {
            check[a[i]] = 1; // Set the value to 1 at the index represented by the element in the input array
        }
    
    int ans=-1;

    for(int i=1; i<N; i++){
        if(check[i]==0){
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
return 0;
}
}
// 5
// 1
// 2
// 45
// 6
// 7
// 3