//40.2
//important
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2, MOD = 1e9+7;

int a[N], tree[4*N];

void build(int node, int st, int en) {
    if (st == en) {
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid); // left child
    build(2 * node + 1, mid + 1, en); // right child

    tree[node] = tree[2 * node] + tree[2 * node + 1]; // sum of left and right child
}

int query(int node, int st, int en, int l, int r) {
    // Case 1: Out of range
    if (st > r || en < l) {
        return 0;
    }
    // Case 2: Completely inside range
    if (l <= st && en <= r) {
        return tree[node];
    }
    // Case 3: Partially inside range
    int mid = (st + en) / 2;
    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);
    return q1 + q2;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while (true) {
        int type;
        cin >> type;
        if (type == -1) {
            break;
        }
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        }
    }
    return 0;
}

// //Input
// 8
// 5 3 2 4 1 8 6 10
// 1 
// 1 5 
// -1
// //Output
// 18