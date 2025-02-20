//Learn this about insertion
//TC: 
//O(log n)

/*
1. Maintain two heaps such that their sizes differ by at most one element.
2. If both heaps have the same number of elements, the median is the average of the roots of the two heaps.
3. If the heaps have an unequal number of elements, the root of the larger heap is the median.
4. Insert new elements by comparing sizes of heaps and rebalancing if necessary.
5. Find the median using the balanced heaps.
6. Efficient median retrieval with time complexity of O(log n).
7. Ensure accurate computation of the median.
*/

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
void insert(int x) {
    if (pqmin.size() == 0) {
        if (pqmax.size() == 0) {
            pqmax.push(x);
            cout<<"Inserted:"<<x<<" to pqmax"<<endl;
            return;
        }  
        if (x < pqmax.top()) { // Inserting first element into max-heap
            pqmax.push(x);
            cout<<"Inserted:"<<x<<" to pqmax"<<endl;
        } else {
            pqmin.push(x); // Inserting first element into min-heap
            cout<<"Inserted:"<<x<<" to pqmin"<<endl;
        }
    } else {
        // Two cases:
        // Case 1: size of maxHeap > size of minHeap
        // Case 2: size of maxHeap < size of minHeap
        if (pqmax.size() > pqmin.size()) {//Case 1
            if (x >= pqmax.top()) { // If pqmax has more elements and x is greater than pqmax's root, then push x to pqmin
                pqmin.push(x);
                cout<<"Inserted:"<<x<<" to pqmin"<<endl;
            } else {
                int temp = pqmax.top(); // If pqmax has more elements and x is smaller than pqmax's root, then remove the topmost element from pqmax and push it into pqmin, then insert x
                pqmax.pop();
                pqmin.push(temp);
                cout<<"Moved "<<temp<<"from pqmax to pqmin"<<endl;
                pqmax.push(x);
                cout<<"Inserted:"<<x<<" to pqmax"<<endl;
            }
        } else { 
            ///CASE:2 // pqmax.size() <= pqmin.size()
            if (x <= pqmin.top()) { // If pqmin has more elements and x is smaller than pqmin's root, then push x to pqmax
                pqmax.push(x);
                cout<<"Inserted:"<<x<<" to pqmax"<<endl;


            } else { // If pqmin has more elements and x is greater than pqmin's root, then remove the topmost element from pqmin and push it into pqmax, then insert x
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                cout<<"Moved "<<temp<<"from pqmin to pqmax"<<endl;

                pqmin.push(x);
                cout<<"Inserted:"<<x<<" to pqmin"<<endl;
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
    cout <<"MEDIAN:: "<<findMedian() << endl;
    insert(15);
    cout <<"MEDIAN:: " <<findMedian() << endl;
    insert(21);
    cout <<"MEDIAN:: " << findMedian() << endl;
    insert(30);
    cout <<"MEDIAN:: " <<findMedian() << endl;
    insert(18);
    ///NOTE:Since 18 is smaller than 15 (top of min-heap), 15 is moved to the max-heap, and 18 is added to the min-heap.
    cout <<"MEDIAN:: " <<findMedian() << endl;
    insert(19);
    ///NOTE: 19 is compared with 15 (top of max-heap) and inserted into the min-heap.
    cout <<"MEDIAN:: " << findMedian() << endl;

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

///OUTPUT: 
// Inserted:10 to pqmax
// MEDIAN:: 10
// Inserted:15 to pqmin
// MEDIAN:: 12.5
// Moved 15from pqmin to pqmax
// Inserted:21 to pqmin
// MEDIAN:: 15
// Inserted:30 to pqmin
// MEDIAN:: 18
// Inserted:18 to pqmax
// MEDIAN:: 18
// Inserted:19 to pqmin
// MEDIAN:: 18.5
