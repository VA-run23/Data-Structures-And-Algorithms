//40.4
//Unable to run under this file name
// 

#include <bits/stdc++.h>
#include<ctype.h>
using namespace std;

// #define int long long
const int  N = 1e5+2, MOD = 1e9+7;

int tree[4*N], a[N];

void build(int node, int st, int en){
    if(st == en){
        tree[node] = a[st];
        return ;
    }
    int mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node +1, mid+1, en);

    tree[node] = max(tree[2*node], tree[2*node +1]);
}


int query(int node, int st, int en, int l, int r){
    if(st> r || en < l){
        return INT_MIN;
    }
    if(l<= st && en<= r){
        return tree[node];
    }
    int mid = (st+en)/2;
    int q1 = query(2*node, st, mid, l , r);
    int q2 = query(2*node+1, mid +1, en, l, r);

    return max(q1, q2);
}


void update(int node, int st, int en, int idx, int val){
    if(st == en){
        a[st] = val;
        tree[node] = val;
        return;
    }
    int mid = (st + en) / 2;
    if(idx <= mid){
        update(2*node, st, mid, idx, val);
    }else{
        update(2*node+1, mid+1, en, idx, val); 

    }
    tree[node] =max(tree[2*node], tree[2*node +1]);
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
        if (type == -1) break;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            int ans = query(1, 0, n - 1, l, r);
            cout << ans << endl;
        } else if (type == 2) {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
            cout << query(1, 0, n - 1, 0, n - 1) << endl;
        }
    }
    return 0;
}



// #include <iostream>
// #include <algorithm> // For std::max and INT_MIN
// #include <climits> // For INT_MIN

// using namespace std;

// const int N = 1e5 + 2; // Increased size slightly for safety
// int tree[4 * N], a[N];

// void build(int node, int st, int en) {
//     if (st == en) {
//         tree[node] = a[st];
//         return;
//     }
//     int mid = st + (en - st) / 2; // More robust mid calculation
//     build(2 * node, st, mid);
//     build(2 * node + 1, mid + 1, en);
//     tree[node] = max(tree[2 * node], tree[2 * node + 1]);
// }

// int query(int node, int st, int en, int l, int r) {
//     if (st > r || en < l) {
//         return INT_MIN;
//     }
//     if (l <= st && en <= r) {
//         return tree[node];
//     }
//     int mid = st + (en - st) / 2; // More robust mid calculation
//     int q1 = query(2 * node, st, mid, l, r);
//     int q2 = query(2 * node + 1, mid + 1, en, l, r);
//     return max(q1, q2);
// }

// void update(int node, int st, int en, int idx, int val) {
//     if (st == en) {
//         a[st] = val;
//         tree[node] = val;
//         return;
//     }
//     int mid = st + (en - st) / 2; // More robust mid calculation
//     if (idx <= mid) {
//         update(2 * node, st, mid, idx, val);
//     } else {
//         update(2 * node + 1, mid + 1, en, idx, val);
//     }
//     tree[node] = max(tree[2 * node], tree[2 * node + 1]);
// }

// int main() {
//     int n;
//     cin >> n;

//     // Input Validation for n
//     if (n <= 0 || n > N - 2) {  // N-2 to leave some space
//         cerr << "Invalid input for n" << endl;
//         return 1;
//     }

//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     build(1, 0, n - 1);

//     while (true) {
//         int type;
//         cin >> type;

//         if (cin.eof()) break; // Check for end-of-file

//         if (type == -1) break;

//         if (type == 1) {
//             int l, r;
//             cin >> l >> r;

//             // Input Validation for l and r
//             if (l < 0 || l >= n || r < 0 || r >= n || l > r) {
//                 cerr << "Invalid query range" << endl;
//                 continue; // Or handle the error differently
//             }

//             int ans = query(1, 0, n - 1, l, r);
//             cout << ans << endl;
//         } else if (type == 2) {
//             int idx, val;
//             cin >> idx >> val;

//             // Input Validation for idx
//             if (idx < 0 || idx >= n) {
//                 cerr << "Invalid index for update" << endl;
//                 continue;
//             }
//             update(1, 0, n - 1, idx, val);
//             cout << query(1, 0, n - 1, 0, n - 1) << endl;
//         }
//     }
//     return 0;
// }