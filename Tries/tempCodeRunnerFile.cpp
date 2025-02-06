//36.3
//
//TC: 
#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node* next[2];
    node() {
        for(int i = 0; i < 2; i++) {
            next[i] = NULL;
        }
    }
};

node* trie;

void insert(int num) {
    node* it = trie;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(!it->next[bit]) {
            it->next[bit] = new node();//If you cant go in opposite direction then create a node then go in opposite direction. 
        }
        it = it->next[bit];
    }
}

int query(int num) {
    node* it = trie;
    int xorSum = 0;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(it->next[1 - bit]) {
            xorSum |= (1 << i);
            it = it->next[1 - bit];
        } else {
            it = it->next[bit];
        }
    }
    return xorSum;
}

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    trie = new node();
    insert(0);
    vector<int> rmax(n + 1, 0);
    int R = 0;
    for(int i = n - 1; i >= 0; i--) {
        R = R ^ a[i];
        if(i != n - 1) {
            rmax[i] = max(rmax[i + 1], query(R));
            insert(R);
        }
    }

    free(trie);
    trie = new node();
    int ans = 0;
    int L = 0;
    for(int i = 0; i < n; i++) {
        L = L ^ a[i];
        ans = max(ans, rmax[i + 1] + query(L));
        insert(L);
    }
    cout << ans;
    return 0;
}
