//33.5
//The goal is to minimize the total computation time required to merge all files into one.
//Repeated Merging: The smallest two elements are repeatedly removed, summed, and the sum is pushed back into the heap until only one element remains.
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i =0; i<n; i++){
        cin>>a[i];
    } 
    priority_queue<int, vector<int>,greater<int> > minHeap;
    //priority_queue<datatype, container,argument_for_min_or_max_heap)>
    for(int i = 0; i< n; i++){
        minHeap.push(a[i]);
    }
    int ans = 0;
    while(minHeap.size() > 1){
        int e1 =  minHeap.top();
        minHeap.pop();
        int e2= minHeap.top();
        minHeap.pop();
        ans+= e1 + e2;
        minHeap.push(e1+ e2);
    }
    cout<<ans<<endl;

    return 0;
}
// //Input
// 4
// 5 2 4 7
// //Output
// 35