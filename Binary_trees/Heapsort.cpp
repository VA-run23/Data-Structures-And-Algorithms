// Description: Heap sort is an efficient comparison-based sorting algorithm that utilizes the heap data structure. It builds a max-heap from the input array, repeatedly swaps the root (largest element) with the last element of the heap, and then heapifies the reduced heap. This process continues until the entire array is sorted in ascending order.
//31.2
//Done
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

void heapify(vi&a, int n, int i){
    int maxIdx = i; // Initialize maxIdx as the index of the root node
    int l = 2*i+1; // Calculate the left child index for the ith node
    int r = 2*i+2; // Calculate the right child index for the ith node
    
    if(l < n && a[l] > a[maxIdx]){ // If left child is larger than root
        maxIdx = l;
    }
    if(r < n && a[r] > a[maxIdx]){ // If right child is larger than current max
        maxIdx = r;
    }

    if(maxIdx != i){
        swap(a[i], a[maxIdx]); // swap the values at index i and maxIdx in the original vector a.
        heapify(a, n, maxIdx); // Recursively heapify the affected sub-tree
    }
}

void heapsort(vi &a){
    int n = a.size(); // Get the size of the vector
    for(int i = n/2 -1; i >= 0; i--){ // Start heapifying from the first non-leaf element
    //and the first non-leaf element is at index n/2 - 1. and subsequently heapify all non-leaf nodes
    //>=0 because we need to heapify the root node as well, which is at index 0 of the array.
        heapify(a, n, i);
    }
    for(int i = n-1; i > 0; i--){//here actual sorting happens
        swap(a[0], a[i]); // Move current root to end
        heapify(a, i, 0); // Rebuild the heap with the reduced size (from n to n-1, n-2, etc. in subsequent iterations)
    }
}

int main(){
    int n;
    cin >> n;
     
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];

    heapsort(a);
    rep(i, 0, n){
        cout << a[i] << " ";
    }
    return 0;
}
