//32.7
//Done
//TC : O(nlogk)
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n){
        cin >> a[i];
    }
    map<int, int> freq;
    rep(i, 0, n){
        int presentSize = freq.size();//initially 0
        if(freq[a[i]] == 0 && presentSize == k){
            break;
            //Breaking Condition: If the map already contains k distinct elements and the current element is a new distinct element (i.e., its frequency is 0), the loop breaks
            //This ensures that the program stops counting as soon as it encounters the (k+1)th distinct element.
        }
        freq[a[i]]++;
    }
    // Uses a map to count the frequency of each element. If the map size reaches k and a new element is encountered, it breaks the loop.
    vii ans;
    map<int, int>::iterator it;
    for(it = freq.begin(); it != freq.end(); it++){
        if(it->ss != 0){
            pii p;
            p.ff= it->ss;
            p.ss = it->ff;
            ans.push_back(p);
        }
    }
    sort(ans.begin(), ans.end(), greater<pii>());//sorting pairs based on frequency
    vii::iterator it1;
    for(it1 = ans.begin(); it1 != ans.end(); it1++){
        cout << it1->ss << " " << it1->ff << endl;
    }
    return 0;
}
// input
// 6 2 
// 1 2 2 2 3 1
// //Output
// 2 3
// 1 1


// For example, if your input is 6 2 and the array is 1 2 2 2 3 1:

// After processing 1, freq.size() is 1.
// After processing 2, freq.size() is 2.
// When processing the next 2s, freq.size() remains 2 because 2 is already in the map.
// When processing 3, if freq.size() is already 2 (equal to k), the loop will break if freq[3] is 0.
// So, freq.size() helps to keep track of the number of distinct elements and ensures the loop breaks when the number of distinct elements reaches k and a new distinct element is encountered.
//So, the program doesn’t return the (k+1)th element directly but stops counting further elements once it encounters the (k+1)th distinct element. It then outputs the frequencies of the elements counted up to that point.


// ////Input
// 10 3//10 elements passed, after finding 3 distinct elements in the given order and after encountering the next distinct element, it breaks, and sorts the given pair of values based on its frequency
// 1 2 2 2 3 3 3 2 1 0
// //Output
// 2 4
// 3 3
// 1 2


// //Output
// 10 3
// 1 2 2 2 0 3 3 2 1 0
// //INput
// 2 3
// 1 1
// 0 1