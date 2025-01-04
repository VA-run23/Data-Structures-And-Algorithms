//Done
// Use of greater<int> is always for the min-heap
// By default, priority_queue uses less<int> to organize elements in descending order (max-heap).
// Using greater<int> flips this, organizing elements in ascending order (min-heap).-increasing order

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

int main(){
    priority_queue<int, vector<int>> pq; // Max-heap
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout << pq.top() << endl; // Output: 3 (largest element)
    pq.pop();
    cout << pq.top() << endl; // Output: 2 (next largest element)
    
    priority_queue<int, vector<int>, greater<int>> pqm; // Min-heap
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    cout << pqm.top() << endl; // Output: 1 (smallest element)
    pqm.pop();
    cout << pqm.top() << endl; // Output: 2 (next smallest element)
    
    return 0;
}

// Output
// 3
// 2
// 1
// 2
