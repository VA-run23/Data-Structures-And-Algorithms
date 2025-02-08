//
//42.4
//Applying MOs algo
#include <bits/stdc++.h>
using namespace std;

//#define int long long
const int N = 2e5+2, MOD = 1e9+7;

struct Q{
    int l, r, idx;
};
int rootN;

Q q[N];

bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r < q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    rootN = (int)sqrtl(n);
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    sort(q, q + queries, compare);

    vector<int> ans(queries);
    int currL = 0, currR = -1;
    int currAns = 0;
    vector<int> freq(10 * N, 0);

    for(int i = 0; i < queries; i++){
        int l = q[i].l, r = q[i].r;
        l--; r--; // for 0-based indexing

        while(currR < r){
            freq[a[++currR]]++;
            if(freq[a[currR]] == 1){
                currAns++;
            }
        }
        while(currL > l){
            freq[a[--currL]]++;
            if(freq[a[currL]] == 1){
                currAns++;
            }
        }
        while(currL < l){
            if(freq[a[currL]] == 1){
                currAns--;
            }
            freq[a[currL]]--;
            currL++;
        }
        while(currR > r){
            if(freq[a[currR]] == 1){
                currAns--;
            }
            freq[a[currR]]--;
            currR--;
        }

        ans[q[i].idx] = currAns;
    }

    for(int i = 0; i < queries; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
// //Input
// 5
// 1 1 2 1 3 
// 3 
// 1 5
// 2 4 
// 3 5 
 
// //Output
// 3
// 2
// 3
