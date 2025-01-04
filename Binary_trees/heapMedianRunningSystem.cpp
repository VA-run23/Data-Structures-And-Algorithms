//Learn this about insertion
//TC: 
//O(log n)
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x)

priority_queue<int, vi, greater<int>> pqmin;
priority_queue<int, vi> pqmax;

void insert(int x){
    if(pqmin.size() == 0){
        if(pqmax.size() == 0){
            pqmax.push(x);
            return;
        }  
        if(x < pqmax.top()){
            pqmax.push(x);
        } else {
            pqmin.push(x);
        }
    } else {
        // Two cases:
        // Case 1: size of maxHeap > size of minHeap
        // Case 2: size of maxHeap < size of minHeap
        if(pqmax.size() > pqmin.size()){
            if(x >= pqmax.top()){
                pqmin.push(x);
            } else {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        } else {
            if(x <= pqmin.top()){
                pqmax.push(x);
            } else {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmin.size() == pqmax.size()){
        return (pqmin.top() + pqmax.top()) / 2.0;
    } else if(pqmax.size() > pqmin.size()){
        return pqmax.top();
    } else {
        return pqmin.top();
    }
}

int main(){
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;

    return 0;
}
// Insert Function:

// If both heaps are empty, the first element is added to the max-heap.

// If the max-heap has more elements than the min-heap, the new element is compared with the top of the max-heap. 
// If the new element is smaller, it's added to the max-heap; otherwise, 
// the top of the max-heap is pushed to the min-heap, and the new element is added to the max-heap.

// If the min-heap has more elements, the new element is compared with the top of the min-heap.
// If the new element is larger, it's added to the min-heap; otherwise,
// the top of the min-heap is pushed to the max-heap, and the new element is added to the min-heap.

// //Find Median Function:

// If both heaps have the same number of elements, the median is the average of the tops of both heaps.

// If the max-heap has more elements, the median is the top of the max-heap.

// If the min-heap has more elements, the median is the top of the min-heap.