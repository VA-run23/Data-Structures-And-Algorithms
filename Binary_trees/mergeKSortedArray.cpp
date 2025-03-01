//Done
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x) // Corrected from 'builtin_popcount'

int main(){
    int k;//k number of arrays
    cin >> k;
    vector<vector<int>> a(k);
    
    rep(i, 0, k){
        int size; //size of each array
        cin >> size;
        a[i] = vector<int>(size);//initializing the size of each array with size only
        rep(j, 0, size){
            cin >> a[i][j];
        }
    }

    vector<int> idx(k, 0);//vector idx with k elements all initialized to 0
    priority_queue<pii, vector<pii>, greater<pii>> pq;//declares a priority queue of pairs of integers, using a vector as the underlying container, and ordering the elements such that the smallest pair is at the top (min-heap).
   ///SYNTAX: priority_queue< Type, Container, Compare > pq;
   /*
    The priority queue (pq) will typically have the same number of elements as the number of arrays (k) at any given time, with a maximum of k elements. 
    As you extract the smallest element from the pq and add it to the result list, you push the next element from the same array into the pq. 
    This ensures that the pq always contains one element from each array, maintaining a maximum of k elements in the pq.
    */

    rep(i, 0, k){
        pq.push(make_pair(a[i][0], i));//The loop initializes the min-heap priority queue pq with pairs of the first element from each of the k lists in array a and their respective list indices.
    }

    vi ans;//ans is a vector that will hold the final merged sorted list.

while(!pq.empty()) {
    pii x = pq.top(); //since the top element of the priority queue is the smallest element, we store it in x and then pop it.
    pq.pop();
    ans.push_back(x.ff); // Add the smallest element to the result list.

    int listIndex = x.ss; // Determine which list the smallest element came from.
    idx[listIndex]++; // Move to the next element in that list.
    //As you extract the smallest element from pq, you add it to the result list ans and push the next element from the same array 
    //into the priority queue, maintaining the sorted order until all elements are processed.
    if (idx[listIndex] < a[listIndex].size()) {
        pq.push(make_pair(a[listIndex][idx[listIndex]], listIndex)); // Push the next element from the same list into the priority queue.
    }
}


    rep(i, 0, ans.size()){
        cout << ans[i] << endl;
    }

    return 0;
}

// // input
// 3
// 3   1 4 6 
// 2   2 3
// 3   5 6 7

// The priority queue will be initialized with the elements:
// (1, 0) from Array 1
// (2, 1) from Array 2
// (5, 2) from Array 3

// // output
// 1
// 2
// 3
// 4
// 5
// 6
// 6
// 7
//Note: The priority queue (pq) will typically have the same number of elements as the number of arrays (k) at any given time. As you extract the smallest element from the pq and add it to the result list, you push the next element from the same array into the pq. This ensures that the pq always contains one element from each array, maintain