//34.14
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) __builtin_popcount(x) // counts the number of set bits (1s) in the binary representation of x
const int INF = 1e9;
// Global variables
int n, m;
const int N = 1e5 + 3;
vii g[N];
int cost = 0;

vector<int> dist(N), parent(N);
vector<bool> vis(N);

void primsMST(int source) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    set<vector<int>> s;
    dist[source] = 0;
    s.insert({0, source});
    while (!s.empty()) {
        auto x = *(s.begin());
        s.erase(x);
        vis[x[1]] = true; // as stored as {weight, vertex}
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << endl;
        cost += w;
        for (auto it : g[x[1]]) {
            if (vis[it.first])
                continue;
            if (dist[it.first] > it.second) {
                s.erase({dist[it.first], it.first});
                dist[it.first] = it.second;
                s.insert({dist[it.first], it.first});
                parent[it.first] = x[1];
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    primsMST(0);
    cout << cost;
    return 0;
}


// //Intput 
//4 5
// 0 1 10 
// 1 2 15
// 0 2 5
// 3 1 2
// 3 2 40
////Output
// 0 -1 0
// 2 0 5
// 1 0 10
// 3 1 2
// 17