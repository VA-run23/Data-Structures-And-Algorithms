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
    //and the first non-leaf element is at index n/2 - 1. and subsequently heapify all non-leaf nodes >=0 
    //because we need to heapify the root node as well, which is at index 0 of the array.
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

/*
Explanation of i Initialization
The variable i is initialized to n/2 - 1, and here's why:

Heap Concept:

A binary heap is a complete binary tree represented as an array. In such a tree, the index of each node's left child is 2 * i + 1, and the index of the right child is 2 * i + 2.

Non-Leaf Nodes:

Leaf nodes are the nodes that do not have children. In a heap of size n, all nodes from index n/2 to n-1 are leaf nodes. These nodes do not need heapification because they are already valid heaps of size 1.

Starting Point:

To build a heap, you need to ensure all non-leaf nodes satisfy the heap property. The first non-leaf node is at index n/2 - 1. This is because the parent of the last leaf node (n-1) is at (n-1)/2, which simplifies to n/2 - 1 for integer division.

Initializing i to n/2 - 1 allows the loop to start heapifying from the last non-leaf node and move towards the root node at index 0.

Heapifying Process:

The loop runs from i = n/2 - 1 down to i = 0. This ensures that every non-leaf node is heapified, which recursively ensures that the entire array satisfies the heap property.

Visual Representation
For an array representation of a heap:

Index:     0   1   2   3   4   5   6   ...
Array:    [root,  .. , n/2-1, ...  , n-1]
The loop starts from n/2 - 1 and goes down to 0:

n/2 - 1: Last non-leaf node

0: Root node

Summary
The initialization of i to n/2 - 1 ensures that the heapify process starts from the last non-leaf node and moves upwards to the root, ensuring that the entire array represents a valid heap by the end of the process.
*/
